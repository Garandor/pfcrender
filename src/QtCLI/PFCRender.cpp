#include "PFCRender.h"
#include "Common/Sequence_Walker.h"
#include "Model/LSYSModel.h"
#include "ViewModel/CustomGeometryModel.h"

namespace QtCLI {

PFCRender::PFCRender()
    : m_mdl()
    , m_vm()
{
    //Instantiate everything from the provided sequence
    Common::Sequence_Walker walker;

    walker.execute(m_mdl, m_vm);

    qApp->quit();
}

} // namespace QtCLI
