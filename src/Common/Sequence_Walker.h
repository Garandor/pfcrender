#pragma once

#include <QVector>

#include "Model/LSYSModel.h"

namespace Common {

/**
 * @brief The Sequence_Walker class runs the sequence given from CLI or GUI
 * This builder style class takes steps set in config_registry and executes them.
 */
class Sequence_Walker {
public:
    QVector<QString> m_stepNames;

public:
    Sequence_Walker();
    void addStep(const QString& stepName);

    void execute(Model::LSYSModel& mod);
};
}
