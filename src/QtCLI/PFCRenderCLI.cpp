#include "Common/Config_Registry.h"
#include "Common/Plugin_Registry.h"
#include "Common/Sequence_Walker.h"

#include "PFCRenderCLI.h"

namespace QtCLI {

PFCRenderCLI::PFCRenderCLI()
    : m_mdl{}
{
    //Execute the provided sequence and quit
    Common::Sequence_Walker walker;

    walker.execute(m_mdl);

    qApp->quit();
}

PFCRenderCLI::~PFCRenderCLI()
{
    delete Common::Config_Registry::getInstance();
    delete Common::Plugin_Registry::getInstance();
}

} // namespace QtCLI
