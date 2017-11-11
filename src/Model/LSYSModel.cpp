#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "LSYSModel.h"

namespace Model
{

void LSYSModel::setModel(std::unique_ptr<QString> newMod)
{
    m_sModel = std::move(newMod);
    emit modelChanged(*m_sModel.get());
}

QString const * const LSYSModel::getModel() const
{
    return m_sModel.get();
}

}  // namespace Model