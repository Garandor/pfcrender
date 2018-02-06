#ifndef QTGUI_P_F_C_RENDER_H
#define QTGUI_P_F_C_RENDER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QString>

#include "Model/LSYSModelImpl.h"
#include "QtGUI/NanoCustomGeometryModel.h"

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
    Model::LSYSModelImpl m_mdl;
    QQmlApplicationEngine* p_eng;
};

} // namespace QtGUI
#endif
