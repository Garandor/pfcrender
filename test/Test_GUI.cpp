#include <QString>
#include <QtTest>

#include <QList>
#include <QSGGeometry>
#include <QSGGeometryNode>

#include "QtGUI/ViewModelBuilder.h"

class Test_GUI : public QObject {
    Q_OBJECT

    QSGGeometryNode* n;

private slots:
    void initTestCase();
    void cleanupTestCase();

    void createGeometry_90deg();
    void createGeometry_different_letters();
    void createGeometry_6colors();
};

void Test_GUI::initTestCase()
{
    n = new QSGGeometryNode;
    n->setFlag(QSGGeometryNode::OwnsGeometry);
    n->setFlag(QSGGeometryNode::OwnsMaterial);
}

void Test_GUI::cleanupTestCase()
{
    delete n;
}

void Test_GUI::createGeometry_90deg()
{
    QString resultString{ "F+F-F0F" };
    QList<QSGGeometry::Point2D> plist{ { 0.0, 0.0 }, { 10.0, 0.0 }, { 10.0, 10.0 }, { 20.0, 10.0 }, { 30.0, 10.0 } }; //Should give valid result
    int segments = 4;
    qreal angle = 90;
    int seglen = 10;

    QSGGeometryNode* res = QtGUI::createGeom(resultString).first;
    QSGGeometry const* g = res->geometry();
    const QSGGeometry::ColoredPoint2D* v = g->vertexDataAsColoredPoint2D();

    QVERIFY(v[0].x == plist.at(0).x && v[0].y == plist.at(0).y);
    QVERIFY(v[1].x == plist.at(1).x && v[1].y == plist.at(1).y);
    QVERIFY(v[2].x == plist.at(2).x && v[2].y == plist.at(2).y);
    QVERIFY(v[3].x == plist.at(3).x && v[3].y == plist.at(3).y);
    QVERIFY(v[4].x == plist.at(4).x && v[4].y == plist.at(4).y);
}

void Test_GUI::createGeometry_different_letters()
{
    QString resultString{ "bGNc" };
    QList<QSGGeometry::Point2D> plist{ { 0.0, 0.0 }, { 10.0, 0.0 }, { 20.0, 0.0 }, { 30.0, 0.0 }, { 40.0, 0.0 } }; //Should give valid result
    int segments = 4;
    qreal angle = 90;
    int seglen = 10;

    QSGGeometryNode* res = QtGUI::createGeom(resultString).first;
    QSGGeometry const* g = res->geometry();
    const QSGGeometry::ColoredPoint2D* v = g->vertexDataAsColoredPoint2D();

    QVERIFY(v[0].x == plist.at(0).x && v[0].y == plist.at(0).y);
    QVERIFY(v[1].x == plist.at(1).x && v[1].y == plist.at(1).y);
    QVERIFY(v[2].x == plist.at(2).x && v[2].y == plist.at(2).y);
    QVERIFY(v[3].x == plist.at(3).x && v[3].y == plist.at(3).y);
    QVERIFY(v[4].x == plist.at(4).x && v[4].y == plist.at(4).y);
}

void Test_GUI::createGeometry_6colors()
{
    QString resultString{ "A_A_A_A_A_A" };
    int segments = 6;
    qreal angle = 90;
    int seglen = 10;

    QSGGeometryNode* res = QtGUI::createGeom(resultString).first;
    QSGGeometry const* g = res->geometry();
    const QSGGeometry::ColoredPoint2D* v = g->vertexDataAsColoredPoint2D();

    //Verify the colors of subsequent vertices are different in at least one component
    QVERIFY(v[0].r != v[1].x || v[0].g != v[1].g || v[0].b != v[1].b);
    QVERIFY(v[1].r != v[2].x || v[1].g != v[2].g || v[1].b != v[2].b);
    QVERIFY(v[2].r != v[3].x || v[2].g != v[3].g || v[2].b != v[3].b);
    QVERIFY(v[3].r != v[4].x || v[3].g != v[4].g || v[3].b != v[4].b);
    QVERIFY(v[4].r != v[5].x || v[4].g != v[5].g || v[4].b != v[5].b);
}
QTEST_MAIN(Test_GUI)
#include "Test_GUI.moc"
