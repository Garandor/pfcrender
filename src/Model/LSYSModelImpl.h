#pragma once

#include "LSYSModel.h"

namespace Model {
class LSYSModelImpl : public LSYSModel {
    Q_INTERFACES(LSYSModel)

signals:
    void modelChanged(const QString&) const;

public:
    void setModel(std::unique_ptr<QString>);
    QString const* getModel() const;

private:
    std::unique_ptr<QString> m_sModel;
};

} // namespace Model
