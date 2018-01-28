#ifndef QTGUI_P_F_C_RENDER_H
#define QTGUI_P_F_C_RENDER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QString>

#include "Model/LSYSModel.h"
#include "QtGUI/CustomGeometryModel.h"

namespace QtGUI {

class PFCRenderGUI : public QObject {
    Q_OBJECT

public slots:
    void onModelChanged();

public:
    PFCRenderGUI(QQmlApplicationEngine*);
    ~PFCRenderGUI();

    void post_status(const QString& what);

public:
    Model::LSYSModel m_mdl;
    QtGUI::CustomGeometryModel m_vm;
    QQmlApplicationEngine* p_eng;
};

} // namespace QtGUI
#endif
