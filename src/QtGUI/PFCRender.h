#ifndef QTGUI_P_F_C_RENDER_H
#define QTGUI_P_F_C_RENDER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QString>

#include "Model/LSYSModel.h"
#include "ViewModel/CustomGeometryModel.h"

namespace QtGUI {

class PFCRender : public QObject {
    Q_OBJECT

public slots:
    void onModelChanged(const QString&);

public:
    PFCRender(QQmlApplicationEngine*);

    void post_status(const QString& what);

public:
    Model::LSYSModel m_mdl;
    ViewModel::CustomGeometryModel m_vm;
    QQmlApplicationEngine* p_eng;
};

} // namespace QtGUI
#endif
