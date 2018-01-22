#pragma once
#include "CustomGeometryModel.h"
#include "Model/LSYSModel.h"
#include "ModelStringParser.h"
#include <functional>

namespace ViewModel {

class PolarVector2D;

class ViewModelBuilder : public ModelStringParser {
public slots:
    void onModelChanged(const QString* const);

private:
    QSGGeometryNode* _createGeometry(const QString& curve);

    void parse_config(QString opt_name, std::function<void(double)> fnc);

    void draw_curve(QString curve, QPaintDevice& onto);

public:
    friend QSGGeometryNode* createGeom(const QString&);
};

QSGGeometryNode* createGeom(const QString&);
}
