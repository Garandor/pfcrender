

#include "Config_Registry.h"

namespace Common {
Config_Registry* Config_Registry::instance = NULL;

const Config_Registry* Config_Registry::getInstance()
{
    if (instance == NULL)
        instance = new Config_Registry();
    return instance;
}

const QString& getOpt(const QString& optName) const
{
    return m_registered.value(optName);
}

void setOpt(QString& optName, QString optValue){
    m_registered.set(optName, optValue) :
}

Config_Registry::Config_Registry()
    : m_registered{}
{
}

} // namespace Common
