#pragma once

#include <QVector>

#include "Model/LSYSModel.h"

namespace Common {

class Sequence_Walker {
public:
    QVector<QString> m_stepNames;

public:
    Sequence_Walker();
    void addStep(const QString& stepName);

    void execute(Model::LSYSModel& mod);
};
}
