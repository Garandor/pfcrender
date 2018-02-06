#include "LSYSModelImpl.h"

namespace Model {

void LSYSModelImpl::setModel(std::unique_ptr<QString> newMod)
{
    m_sModel = std::move(newMod);
    emit modelChanged(*m_sModel.get());
}

const QString* LSYSModelImpl::getModel() const
{
    return m_sModel.get();
}

} // namespace Model
