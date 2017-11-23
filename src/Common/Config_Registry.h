/**
* @class Plugin_Registry This class holds filenames of registered plugins and returns them by names of the services they expose. What to do with the files is up to the caller
*
**/

#ifndef COMMON_CONFIG_REGISTRY_H
#define COMMON_CONFIG_REGISTRY_H

#include <QHash>
#include <QString>
#include <QVector>

namespace Common {
class Config_Registry {
private:
    static Config_Registry* instance;
    QHash<QString, QString> m_options;
    QVector<QString> m_sequence; //XXX: Having sequence in the config store seems dirty

private:
    Config_Registry();
    Q_DISABLE_COPY(Config_Registry)

public:
    static Config_Registry* getInstance();
    const QString getOpt(const QString& optName) const;
    void setOpt(const QString& optName, const QString& optValue);
    void setOpt(const QPair<QString, QString>&);

    void addToSequence(const QString& name);
    void clearSequence();
    const QVector<QString> getSequence() const;
};

} // namespace Common
#endif
