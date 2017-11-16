#ifndef QTCLI_P_F_C_RENDER_H
#define QTCLI_P_F_C_RENDER_H

#include <QCoreApplication>
#include <QObject>
#include <QString>

#include "Model/LSYSModel.h"
#include "ViewModel/CustomGeometryModel.h"

namespace QtCLI {

class PFCRender : public QObject {
    Q_OBJECT

public:
    PFCRender();

public:
    Model::LSYSModel m_mdl;
    ViewModel::CustomGeometryModel m_vm;
};

} // namespace QtCLI
#endif
