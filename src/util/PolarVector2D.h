#pragma once
#include <QColor>
#include <QSGGeometry>
#include <QtMath> //cos, sin
#include <cmath> //fmod
#include <gsl/gsl>

namespace util {

/**
 * @brief The PolarVector2D class
 * utility class for easy calculation of vertex coordinates,
 * making sure it only gets instantiated once
 */
class PolarVector2D {

public:
    QSGGeometry::ColoredPoint2D start;
    qreal angle;
    qreal length;

public:
    PolarVector2D()
        : start{ 0.0, 0.0, 0, 0, 0, 0 }
        , angle{ 0 }
        , length{ 10 }
    {
        setColor(QColor(Qt::black));
    }
    PolarVector2D& next()
    {
        start.x += length * qCos(angle / 180 * M_PI); //TODO: #17 about half the cycles of model building are spent on sin/cos functions. maybe approximate?
        start.y += length * qSin(angle / 180 * M_PI);
        return *(this);
    }
    const QSGGeometry::ColoredPoint2D& getPoint() { return start; }
    void addToAngle(qreal inc) { angle = fmod((angle + inc), 360); }
    void setColor(const QColor& c)
    {
        start.set(start.x,
            start.y,
            gsl::narrow<uchar>(c.red()),
            gsl::narrow<uchar>(c.green()),
            gsl::narrow<uchar>(c.blue()),
            gsl::narrow<uchar>(c.alpha()));
    }

    const QColor getColor() const
    {
        return QColor(start.r, start.g, start.b, start.a);
    }

    operator QPointF() { return QPointF(start.x, start.y); }
};
}
