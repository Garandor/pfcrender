#include<QtTest>
#include<QString>

#include<QSGGeometryNode>
#include<QSGGeometry>
#include<QList>

#include"ViewModel/ViewModelBuilder.h"

class Test_GUI : public QObject
{
    Q_OBJECT

    QSGGeometryNode* n;

private slots:
    void initTestCase();
    void cleanupTestCase();

    void createGeometry_90deg();
    void createGeometry_different_letters();
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

void Test_GUI::createGeometry_90deg(){
   QString resultString{"F+F-F0F"};
   QList<QSGGeometry::Point2D> plist{{0.0,0.0},{10.0,0.0},{10.0,10.0},{20.0,10.0},{30.0,10.0} };	//Should give valid result
   int segments = 4;
   qreal angle = 90;
   int seglen = 10;

    auto geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), segments+1);
    geometry->setVertexDataPattern(QSGGeometry::StaticPattern);	//we won't touch the vertices after they have first been rendered. NOTE: if we do, mark_dirty
    geometry->setDrawingMode(QSGGeometry::DrawLineStrip);	//Draw connected lines each vertex
    geometry->setLineWidth(3);

    QSGGeometryNode* res = ViewModel::createGeom(resultString);
    QSGGeometry const * g = res->geometry();

    QVERIFY(g->vertexDataAsPoint2D()[0].x == plist.at(0).x && g->vertexDataAsPoint2D()[0].y == plist.at(0).y );
    QVERIFY(g->vertexDataAsPoint2D()[1].x == plist.at(1).x && g->vertexDataAsPoint2D()[1].y == plist.at(1).y );
    QVERIFY(g->vertexDataAsPoint2D()[2].x == plist.at(2).x && g->vertexDataAsPoint2D()[2].y == plist.at(2).y );
    QVERIFY(g->vertexDataAsPoint2D()[3].x == plist.at(3).x && g->vertexDataAsPoint2D()[3].y == plist.at(3).y );
    QVERIFY(g->vertexDataAsPoint2D()[4].x == plist.at(4).x && g->vertexDataAsPoint2D()[4].y == plist.at(4).y );
}

void Test_GUI::createGeometry_different_letters(){
   QString resultString{"b+G-N0c"};
   QList<QSGGeometry::Point2D> plist{{0.0,0.0},{10.0,0.0},{10.0,10.0},{20.0,10.0},{30.0,10.0} };	//Should give valid result
   int segments = 4;
   qreal angle = 90;
   int seglen = 10;

    auto geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), segments+1);
    geometry->setVertexDataPattern(QSGGeometry::StaticPattern);	//we won't touch the vertices after they have first been rendered. NOTE: if we do, mark_dirty
    geometry->setDrawingMode(QSGGeometry::DrawLineStrip);	//Draw connected lines each vertex
    geometry->setLineWidth(3);

    QSGGeometryNode* res = ViewModel::createGeom(resultString);
    QSGGeometry const * g = res->geometry();

    QVERIFY(g->vertexDataAsPoint2D()[0].x == plist.at(0).x && g->vertexDataAsPoint2D()[0].y == plist.at(0).y );
    QVERIFY(g->vertexDataAsPoint2D()[1].x == plist.at(1).x && g->vertexDataAsPoint2D()[1].y == plist.at(1).y );
    QVERIFY(g->vertexDataAsPoint2D()[2].x == plist.at(2).x && g->vertexDataAsPoint2D()[2].y == plist.at(2).y );
    QVERIFY(g->vertexDataAsPoint2D()[3].x == plist.at(3).x && g->vertexDataAsPoint2D()[3].y == plist.at(3).y );
    QVERIFY(g->vertexDataAsPoint2D()[4].x == plist.at(4).x && g->vertexDataAsPoint2D()[4].y == plist.at(4).y );
}
QTEST_MAIN(Test_GUI)
#include "Test_GUI.moc"
