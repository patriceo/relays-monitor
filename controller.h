#ifndef CONTROLLER
#define CONTROLLER

#include "relay.h"
#include <QString>
#include <QObject>

/**
 * @brief The AbstractMainWindowController class Describe UI/Controller protocol
 */
class AbstractMainWindowController : public QObject
{
    public:
    /**
     * @brief addRelay Create a new Relay instance and add it to relays list
     * @return
     */
    virtual Relay* addRelay()=0;

    /**
     * @brief deleteRelay Delete a Relay instance from the global relays list
     * @param r
     */
    virtual void deleteRelay(Relay *r)=0;


    /**
     * @brief updateRelay Update given relay properties
     * @param r
     * @param name
     * @param statusUrl
     * @param openUrl
     * @param closeUrl
     */
    virtual void updateRelay(Relay *r, QString name, QString statusUrl, QString openUrl, QString closeUrl)=0;


    /**
     * @brief getRelays return the relays list
     * @return
     */
    virtual QList<Relay*> getRelays()=0;

    /**
     * @brief openRelayUrl open with HTTP Get the url and return the HTTP Result through SIGNAL
     * @param url
     */
    virtual void openRelayUrl(QString url)=0;
};

class MainController : virtual public AbstractMainWindowController
{
    Q_OBJECT

    // Store the model list
    QList<Relay*> relays;

public:
     MainController();
     ~MainController();

    virtual Relay* addRelay();
    virtual void deleteRelay(Relay *r);
    virtual void updateRelay(Relay *r, QString name, QString statusUrl, QString openUrl, QString closeUrl);
    virtual QList<Relay*> getRelays();
    virtual void openRelayUrl(QString url);

};

#endif // CONTROLLER

