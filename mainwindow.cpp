#include <QStandardItemModel>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller.h"

// UI relay names list
QStringList relaysListString;
QStringListModel *model;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Plug listeners
    connect(ui->addRelayButton, SIGNAL(released()), this, SLOT(handleAddRelay()));
    connect(ui->deleteRelayButton, SIGNAL(released()), this, SLOT(handleDeleteRelay()));
    connect(ui->readStatusButton, SIGNAL(released()), this, SLOT(handleRelayStatusCommand()));
    connect(ui->openRelayButton, SIGNAL(released()), this, SLOT(handleRelayOpenCommand()));
    connect(ui->closeRelayButton, SIGNAL(released()), this, SLOT(handleRelayCloseCommand()));
    connect(ui->relaysList, SIGNAL(clicked(QModelIndex)), this, SLOT(handleListClick(QModelIndex)));
    connect(ui->statusEdit, SIGNAL(textChanged(QString)), this, SLOT(handleRelayPropertyChanged()));
    connect(ui->openEdit, SIGNAL(textChanged(QString)), this, SLOT(handleRelayPropertyChanged()));
    connect(ui->closeEdit, SIGNAL(textChanged(QString)), this, SLOT(handleRelayPropertyChanged()));

    // Default controller is in a separated class
    this->controller = new MainController;

    // Init list view
    if(!ui->relaysList->model())
    {
        model = new QStringListModel(relaysListString, this);
        ui->relaysList->setModel(model);
    }
 }

void MainWindow::handleAddRelay()
{
    if(this->controller)
    {
        Relay *r = this->controller->addRelay();
        relaysListString.append(r->name);
        model->setStringList(relaysListString);
    }
}

void MainWindow::handleDeleteRelay()
{

    QModelIndexList selection = this->ui->relaysList->selectionModel()->selectedRows();
    if(!selection.empty())
    {
        int row = selection.at(0).row();
        Relay *selectedRelay = this->selectedRelay();
        this->controller->deleteRelay(selectedRelay);

        relaysListString.removeAt(row);
        model->setStringList(relaysListString);
    }
}

void MainWindow::handleRelayConfigChanged()
{
    Relay *selectedRelay = NULL;
    if(this->controller && selectedRelay)
    {
        this->controller->deleteRelay(selectedRelay);
    }
}

void MainWindow::handleListClick(QModelIndex modelIndex)
{
  const Relay *r = this->controller->getRelays().at(modelIndex.row());
   if(r)
   {
       ui->statusEdit->setText(r->statusUrl);
       ui->openEdit->setText(r->openUrl);
       ui->closeEdit->setText(r->closeUrl);
   }
}

void MainWindow::handleRelayPropertyChanged()
{
    Relay* r = this->selectedRelay();
    if(r)
    {
        r->statusUrl = ui->statusEdit->text();
        r->openUrl = ui->openEdit->text();
        r->closeUrl = ui->closeEdit->text();
    }
}

Relay* MainWindow::selectedRelay()
{
    QModelIndexList selection = this->ui->relaysList->selectionModel()->selectedRows();
    if(!selection.empty())
    {
        int row = selection.at(0).row();
        if(row > 0 && row < this->controller->getRelays().size())
        {
            return this->controller->getRelays().at(row);
        } else {
          // Should never happen
        }

    }

    return NULL;
}

void MainWindow::handleRelayStatusCommand()
{
    Relay *r = selectedRelay();
    if(r)
    {
        controller->openRelayUrl(r->statusUrl);
    }
}

void MainWindow::handleRelayOpenCommand()
{
    Relay *r = selectedRelay();
    if(r)
    {
        controller->openRelayUrl(r->openUrl);
    }
}

void MainWindow::handleRelayCloseCommand()
{
    Relay *r = selectedRelay();
    if(r)
    {
        controller->openRelayUrl(r->closeUrl);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete controller;
}
