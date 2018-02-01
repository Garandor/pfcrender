#ifndef QTCLI_P_F_C_RENDER_H
#define QTCLI_P_F_C_RENDER_H

#include <QObject>

#include "Model/LSYSModelImpl.h"

namespace QtCLI {

class PFCRenderCLI : public QObject {
    Q_OBJECT

public:
    PFCRenderCLI();
    ~PFCRenderCLI();

public:
    Model::LSYSModelImpl m_mdl;
};

} // namespace QtCLI
#endif
