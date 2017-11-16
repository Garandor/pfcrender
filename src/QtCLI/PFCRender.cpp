#include "PFCRender.h"
#include "Common/Sequence_Walker.h"
namespace QtCLI {

PFCRender::PFCRender()
{
    //Instantiate everything from the provided sequence
    Common::Sequence_Walker walker;

    walker.execute(this);

    Qt.quit();
}

} // namespace QtCLI
