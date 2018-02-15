#ifndef QTGUI_P_F_C_RENDER_H
#define QTGUI_P_F_C_RENDER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QString>

#include "Model/LSYSModelImpl.h"

//! Classes regarding GUI operation
namespace QtGUI {

/**
 * @brief The PFCRenderGUI class is tasked with executing the requested sequence and relaying model change signals to the rendering class
 */
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
