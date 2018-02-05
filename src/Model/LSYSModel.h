#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H
#include <QObject>
#include <QString>
#include <memory>

namespace Model {
class LSYSModel : public QObject {
    Q_OBJECT

signals:
    virtual void modelChanged(const QString& mdl) const = 0;

public:
    virtual void setModel(std::unique_ptr<QString>) = 0;
    virtual QString const* getModel() const = 0;
    virtual ~LSYSModel() {}
};

} // namespace Model

using namespace Model;
Q_DECLARE_INTERFACE(LSYSModel, "Common.LSYSMODEL")
#endif