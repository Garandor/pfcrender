#ifndef QTGUI_P_F_C_RENDER_H
#define QTGUI_P_F_C_RENDER_H

#include <QObject>
#include <QQmlApplicationEngine>

namespace QtGUI
{

class PFCRender : public QObject
{
    Q_OBJECT
public:
    PFCRender(QQmlApplicationEngine*);

public slots:
    void onQmlReady();

private:
};

}  // namespace QtGUI
#endif
