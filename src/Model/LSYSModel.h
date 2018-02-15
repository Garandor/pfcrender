#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H
#include <QObject>
#include <QString>
#include <memory>

//! Holds classes that have to do with the data model
namespace Model {

/**
 * @brief The LSYSModel class
 * Holds a data model string in a unique ptr, notifies and supplies clients with changes
 */
class LSYSModel : public QObject {
    Q_OBJECT

signals:
    virtual void modelChanged(const QString& new_string) const = 0;

public:
    virtual void setModel(std::unique_ptr<QString>) = 0;
    virtual QString const* getModel() const = 0;
    virtual ~LSYSModel() {}
};

} // namespace Model

using namespace Model;
Q_DECLARE_INTERFACE(LSYSModel, "Common.LSYSMODEL")
#endif
