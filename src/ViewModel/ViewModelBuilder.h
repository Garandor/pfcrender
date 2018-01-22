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
    friend QSGGeometryNode* createGeom(const QString&);

private:
    QSGGeometryNode* _createGeometry(const QString& curve);

    void parse_config(QString opt_name, std::function<void(double)> fnc);

    void draw_curve(QString curve, QPaintDevice& onto);

private:
    void add_segment() override;
    void next_color() override;
    void prev_color() override;
    void incAngle() override;
    void decAngle() override;
    void stackPush() override;
    void stackPop() override;
};

QSGGeometryNode* createGeom(const QString&);
}
