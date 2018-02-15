#pragma once

#include <memory>

#include "Model/LSYSModel.h"
#include "Model/ModelStringBuilder.h"

namespace Plugins {
namespace LSYS {

    /**
 * @brief The LSYSModelFactory class
 * The builder implementation that will be returned from the plugin
 */
    class LSYSModelFactory : public Model::ModelStringBuilder {

    private:
        std::unique_ptr<QString> _computeLSYS(const QList<QString>& definition, const ulong iterate);

    public:
        std::unique_ptr<QString> createModel() override;
    };
}
}
