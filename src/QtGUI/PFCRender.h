#ifndef QTGUI_P_F_C_RENDER_H
#define QTGUI_P_F_C_RENDER_H

#include <QObject>
#include <QString>
#include <QQmlApplicationEngine>
#include "Model/LSYSModel.h"

namespace QtGUI
{

class PFCRender : public QObject
{
    Q_OBJECT

    public slots:
        void onModelChanged(const QString&);

    public:
        PFCRender(QQmlApplicationEngine*);

        void post_status(const QString &what);

private:
        Model::LSYSModel m_dMdl;
        QQmlApplicationEngine* p_eng;
    };

}  // namespace QtGUI
#endif
