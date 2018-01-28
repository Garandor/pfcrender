/**
* @class Plugin_Registry This class holds filenames of registered plugins and returns them by names of the services they expose. What to do with the files is up to the caller
*
**/

#ifndef COMMON_CONFIG_REGISTRY_H
#define COMMON_CONFIG_REGISTRY_H

#include <QHash>
#include <QSettings>
#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QVector>

namespace Common {

class SettingsFile;

class Config_Registry : public QObject , public QSettings{
    Q_OBJECT
    Q_DISABLE_COPY(Config_Registry)

    void store_to_file();
    Config_Registry();

public:
    //QML Metatype Information
    static constexpr auto URI{ "Common.Config_Registry" };
    static constexpr uint V_MAJ{ 1 },
        V_MIN{ 0 };
    static constexpr auto QMLTYPE{ "Config_Registry" };

    //Singleton API
    static Config_Registry* getInstance();
    static QObject* qmlInstance(QQmlEngine*, QJSEngine*);
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

private:
    static Config_Registry* instance; ///XXX: Old style leaky singleton. Should be a more C++11 style definiton
    QHash<QString, QString> m_options;
    QVector<QString> m_sequence; //XXX: Having sequence in the config store seems dirty
    QSettings m_set;
};

} // namespace Common
#endif
