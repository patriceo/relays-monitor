#ifndef RELAY
#define RELAY

#include <QString>

class Relay
{
    public:
    // Display name
    QString name;

    // REST URL to get Relay status
    QString statusUrl;

    // REST URL to open the relay
    QString openUrl;

    // REST URL to close the relay
    QString closeUrl;
};


#endif // RELAY

