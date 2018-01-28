/**
* @class Plugin_Registry This class holds filenames of registered plugins and returns them by names of the services they expose. What to do with the files is up to the caller
*
**/

#ifndef COMMON_CONFIG_REGISTRY_H
#define COMMON_CONFIG_REGISTRY_H

#include <QHash>
#include <QSettings>
#include <QString>
#include <QVector>

namespace Common {

class SettingsFile;

class Config_Registry : public QSettings {
private:
    static Config_Registry* instance; ///XXX: Old style leaky singleton. Should be a more C++11 style definiton
    QHash<QString, QString> m_options;
    QVector<QString> m_sequence; //XXX: Having sequence in the config store seems dirty
    QSettings m_set;

private:
    Config_Registry();
    Q_DISABLE_COPY(Config_Registry)
    void store_to_file();

public:
    static Config_Registry* getInstance();
    ~Config_Registry();

    //Declared as slots to have this accessible from QML
public slots:
    const QString getOpt(const QString& optName) const;
    void setOpt(const QString& optName, const QString& optValue);
    void setOpt(const QPair<QString, QString>&);

public:
    void add_to_sequence(const QString& name);
    void clearSequence();
    const QVector<QString> getSequence() const;
};

} // namespace Common
#endif
