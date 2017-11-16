/**
* @class Plugin_Registry This class holds filenames of registered plugins and returns them by names of the services they expose. What to do with the files is up to the caller
*
**/

#ifndef COMMON_CONFIG_REGISTRY_H
#define COMMON_CONFIG_REGISTRY_H

#include <QHash>
#include <QString>

namespace Common {
class Config_Registry {
private:
    static Config_Registry* instance;
    QHash<QString, QString> m_registered;

private:
    Config_Registry();
    Q_DISABLE_COPY(Config_Registry)

public:
    static const Config_Registry* getInstance();
    const QString getOpt(const QString& optName) const;
    void setOpt(const QString& optName, const QString& optValue);
    void setOpt(const QPair<QString, QString>&);
};

} // namespace Common
#endif
