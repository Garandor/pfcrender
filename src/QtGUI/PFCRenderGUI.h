#ifndef QTGUI_P_F_C_RENDER_H
#define QTGUI_P_F_C_RENDER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QString>

#include "Model/LSYSModelImpl.h"

namespace QtGUI {

class PFCRenderGUI : public QObject {
    Q_OBJECT

public slots:
    void onModelChanged(const QString& mdl);

public:
    PFCRenderGUI(QQmlApplicationEngine*, LSYSModel&);
    ~PFCRenderGUI();

    void post_status(const QString& what);

public:
    QQmlApplicationEngine* p_eng;
};

} // namespace QtGUI
#endif
