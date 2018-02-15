#ifndef QTCLI_P_F_C_RENDER_H
#define QTCLI_P_F_C_RENDER_H

#include <QObject>

#include "Model/LSYSModelImpl.h"

//! Classes regarding command line operation
namespace QtCLI {

/**
 * @brief The PFCRenderCLI class
 * This class is used when --batch operation is requested and execute the sequence
 */
class PFCRenderCLI : public QObject {
    Q_OBJECT

public:
    PFCRenderCLI(LSYSModel&);
    ~PFCRenderCLI();
};

} // namespace QtCLI
#endif
