#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include <string>
#include <vector>
#include <list>
#include <memory>
#include <iostream>
#include <assert.h>
#include <QObject>


namespace Model
{
class LSYSModel : public QObject
{
    Q_OBJECT

    signals:
        void modelChanged(const QString&) const;

    public:
        void setModel(std::unique_ptr<QString>);
        QString const * const getModel() const;

    private:
        std::unique_ptr<QString> m_sModel;

};

}  // namespace Model
#endif
