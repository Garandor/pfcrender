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
    virtual void add_segment() final override;
    virtual void next_color() final override;
    virtual void prev_color() final override;
    virtual void incAngle() final override;
    virtual void decAngle() final override;
    virtual void stackPush() final override;
    virtual void stackPop() final override;
};

QSGGeometryNode* createGeom(const QString&);
}
