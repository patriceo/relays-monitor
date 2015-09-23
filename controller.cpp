#include <QStringBuilder>

#include "mainwindow.h"
#include "controller.h"


MainController::MainController()
{
    this->relays = {};
}


MainController::~MainController()
{
    if(!this->relays.isEmpty())
    {
        for(int i=this->relays.size()-1; i>=0; i--)
        {
             Relay *r = this->relays.at(i);
             this->relays.removeAt(i);
             delete r;
        }
    }
}


Relay* MainController::addRelay()
{
    Relay *r = new Relay;
    r->name = "Relay " % QString::number(this->relays.size());
    r->closeUrl = "http://localhost/close";
    r->openUrl = "http://localhost/open";
    r->statusUrl = "http://localhost/status";
    this->relays.append(r);
    return r;
}

void MainController::deleteRelay(Relay *r)
{
    this->relays.removeOne(r);
    delete r;
}


void MainController::updateRelay(Relay *r, QString name, QString statusUrl, QString openUrl, QString closeUrl)
{
    r->name = name;
    r->statusUrl = statusUrl;
    r->openUrl = openUrl;
    r->closeUrl = closeUrl;
}


QList<Relay*> MainController::getRelays()
{
    return this->relays;
}

void MainController::openRelayUrl(QString url)
{
    //TODO
}
