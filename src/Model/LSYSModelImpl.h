#pragma once

#include "LSYSModel.h"

namespace Model {
class LSYSModelImpl : public LSYSModel {
    Q_OBJECT
    Q_INTERFACES(LSYSModel)

signals:
    void modelChanged(const QString& mdl) const override;

public:
    void setModel(std::unique_ptr<QString>) override;
    QString const* getModel() const override;

private:
    std::unique_ptr<QString> m_sModel;
};

} // namespace Model
