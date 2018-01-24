#pragma once
#include "CustomGeometryModel.h"
#include "Model/LSYSModel.h"
#include "ModelStringParser.h"
#include <functional>

namespace ViewModel {

class PolarVector2D;

class ViewModelBuilder {
public slots:
    void onModelChanged(const QString* const);
    friend QSGGeometryNode* createGeom(const QString&);

private:
    QSGGeometryNode* _createGeometry(const QString& curve);

    void parse_config(QString opt_name, std::function<void(double)> fnc);

private:
    void add_segment();
    void next_color();
    void prev_color();
    void incAngle();
    void decAngle();
    void stackPush();
    void stackPop();
    LSYS_STRING_PARSE_FUNC_DECL
};

QSGGeometryNode* createGeom(const QString&);
}
