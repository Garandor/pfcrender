#ifndef QTCLI_P_F_C_RENDER_H
#define QTCLI_P_F_C_RENDER_H

#include <QCoreApplication>
#include <QObject>
#include <QString>

#include "QtGUI/CustomGeometryModel.h"
#include "Model/LSYSModelImpl.h"

namespace QtCLI {

class PFCRenderCLI : public QObject {
    Q_OBJECT

public:
    PFCRenderCLI();

public:
    Model::LSYSModelImpl m_mdl;
    QtGUI::CustomGeometryModel m_vm;
};

} // namespace QtCLI
#endif
