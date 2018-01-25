#pragma once
#include "CustomGeometryModel.h"
#include "Model/LSYSModel.h"
#include "ModelStringParser.h"
#include <QColor>
#include <QList>
#include <QListIterator>
#include <QStack>
#include <Qt>
#include <functional>
#include <utility>

#include "util/PolarVector2D.h"

namespace ViewModel {

class ViewModelBuilder {
public slots:
    void onModelChanged(const QString* const);

public:
    ViewModelBuilder();

private:
    void parse_config(QString opt_name, std::function<void(double)> fnc);
    void parsing_preamble(const QString&);

    LSYS_STRING_PARSE_FUNC_DECL
    void add_segment();
    void next_color();
    void prev_color();
    void incAngle();
    void decAngle();
    void stackPush();
    void stackPop();

    void parsing_finalize(const unsigned int vertexcount);

    QSGGeometryNode* m_geo;
    QSGGeometry* m_g;
    util::PolarVector2D pos;
    QStack<util::PolarVector2D> stack;
    unsigned int current_segment;

    // Color list equivalent to how it was before
    QList<QColor> colors;
    QList<QColor>::const_iterator cur_color;

    double angle_increment;

    QPointF min, max;

    friend std::pair<QSGGeometryNode*, QRectF&&> createGeom(const QString&);
};

std::pair<QSGGeometryNode*, QRectF&&> createGeom(const QString&);
}
