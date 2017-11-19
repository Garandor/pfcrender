#pragma once

#include <memory>

#include "Model/LSYSModel.h"

namespace Model {

/**
 * @brief The ModelFactory class
 * This is the abstract interface to use for Import plugins
 */
class ModelFactory {

public:
    virtual std::unique_ptr<QString> createModel() = 0;
};
}
