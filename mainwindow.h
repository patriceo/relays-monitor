#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QException>
#include <QStringListModel>
#include <QModelIndex>
#include <QString>
#include <QStringList>
#include <QMainWindow>
#include "relay.h"
#include "controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    /*
     * Pointer on controller abstraction
     */
    AbstractMainWindowController *controller;

    /**
     * @brief getSelectedRelay
     * @return
     */
    Relay* selectedRelay();

private slots:
    /**
     * @brief Called when the user clicks the + add button
     */
    void handleAddRelay();

    /**
     * @brief Called when the user clicks the - add button
     */
    void handleDeleteRelay();

    /**
     * @brief Called when the user change any property of the selected relay
     */
    void handleRelayConfigChanged();

    /**
     * @brief Called when the user select a relay in the list
     */
    void handleListClick(QModelIndex modelIndex);

    /**
     * @brief Called each time any relay property changes by controller
     */
    void handleRelayPropertyChanged();

    /**
     * @brief When user clicks status button
     */
    void handleRelayStatusCommand();

    /**
     * @brief When user clicks open button
     */
    void handleRelayOpenCommand();

    /**
     * @brief When user clicks close button
     */
    void handleRelayCloseCommand();

};
#endif // MAINWINDOW_H
