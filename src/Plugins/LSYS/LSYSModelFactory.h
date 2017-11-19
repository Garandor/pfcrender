#pragma once

#include <memory>

#include "Model/LSYSModel.h"
#include "Model/ModelFactory.h"

namespace Plugins {
namespace LSYS {

    /**
 * @brief The LSYSModelFactory class
 *
 */
    class LSYSModelFactory : public Model::ModelFactory {

    private:
        std::unique_ptr<QString> _computeLSYS(const QList<QString>& definition, const ulong iterate);

    public:
        std::unique_ptr<QString> createModel() override;
    };
}
}
