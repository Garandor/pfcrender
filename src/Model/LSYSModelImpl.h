#pragma once

#include "LSYSModel.h"

namespace Model {
/**
 * @brief The LSYSModel implementation
 */
class LSYSModelImpl : public LSYSModel {
    Q_OBJECT
    Q_INTERFACES(LSYSModel)

signals:
    void modelChanged(const QString& new_string) const override;

public:
    void setModel(std::unique_ptr<QString>) override;
    const QString* getModel() const override;

private:
    std::unique_ptr<QString> m_sModel;
};

} // namespace Model
