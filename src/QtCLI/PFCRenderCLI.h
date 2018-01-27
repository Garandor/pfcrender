#ifndef QTCLI_P_F_C_RENDER_H
#define QTCLI_P_F_C_RENDER_H

#include <QCoreApplication>
#include <QObject>
#include <QString>

#include "Model/LSYSModel.h"
#include "QtGUI/CustomGeometryModel.h"

namespace QtCLI {

class PFCRenderCLI : public QObject {
    Q_OBJECT

public:
    PFCRenderCLI();

public:
    Model::LSYSModel m_mdl;
    ViewModel::CustomGeometryModel m_vm;
};

} // namespace QtCLI
#endif
