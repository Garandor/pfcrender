#pragma once
#include "CustomGeometryModel.h"
#include "Model/LSYSModel.h"
#include "Model/ModelStringParser.h"
#include <QColor>
#include <QList>
#include <QListIterator>
#include <QSGGeometry>
#include <QStack>
#include <QString>
#include <Qt>
#include <functional>
#include <utility>

#include "util/PolarVector2D.h"

namespace QtGUI {

class ViewModelBuilder {
public slots:
    void onModelChanged(const QString* const);

public:
    ViewModelBuilder();
    std::pair<QSGGeometryNode*, QRectF> build(const QString& mdl);

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

    QSGGeometryNode* p_geo;
    QSGGeometry* m_g;
    util::PolarVector2D pos;
    QStack<util::PolarVector2D> stack;
    unsigned int current_segment;

    // Color list equivalent to how it was before
    QList<QColor> colors;
    QList<QColor>::const_iterator cur_color;

    double angle_increment;

    std::vector<QSGGeometry::ColoredPoint2D> temp_vertexstore;

    QPointF min, max;
};

std::pair<QSGGeometryNode*, QRectF> createGeom(const QString&);
}
