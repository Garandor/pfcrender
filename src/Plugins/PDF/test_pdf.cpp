#include <QObject>
#include <QString>
#include <QtTest>

#include "SVG.h"

namespace Plugins {
namespace Export {
    namespace SVG {

        class Test_SVG : public QObject {
            Q_OBJECT
            SVG plugin{};

        private slots:
            //Test Harness
            void initTestCase() {}
            void cleanupTestCase() {}

            //Public API
            //        void test_getModel();
            //        void test_getModel_data();
        };

        //    void Test_SVG::test_getModel()
        //    {
        //        QFETCH(QList<QString>, list);
        //        QFETCH(ulong, iterates);
        //        QFETCH(QString, resultString);

        //        std::unique_ptr<QString> result = SVG.getModel(list, iterates);

        //        QCOMPARE(*(result.get()), resultString);
        //    }

        //    void Test_SVG::test_getModel_data()
        //    {
        //        QTest::addColumn<QList<QString>>("list");
        //        QTest::addColumn<ulong>("iterates");
        //        QTest::addColumn<QString>("resultString");

        //        //One-Color Tests
        //        QTest::newRow("non PFC") << QList<QString>{ "F", "F", "F+F+F-F-FF", "+", "+", "-", "-" } << 5UL << "F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF";
        //        QTest::newRow("R5-Dragon it1") << QList<QString>{ "F", "F", "F+F+F-F-F", "+", "+", "-", "-" } << 1UL << "F+F+F-F-F";
        //        QTest::newRow("R5-Dragon it2") << QList<QString>{ "F", "F", "F+F+F-F-F", "+", "+", "-", "-" } << 2UL << "F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F";
        //        QTest::newRow("R5-Dragon it3") << QList<QString>{ "F", "F", "F+F+F-F-F", "+", "+", "-", "-" } << 3UL << "F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F";
        //        QTest::newRow("R5-Dragon it4") << QList<QString>{ "F", "F", "F+F+F-F-F", "+", "+", "-", "-" } << 4UL << "F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F";
        //        QTest::newRow("R5-Dragon it5") << QList<QString>{ "F", "F", "F+F+F-F-F", "+", "+", "-", "-" } << 5UL << "F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F";

        //        //    //Multi-Color Tests
        //        //    QTest::newRow("Colored R5-Dragon it2") << QList<QString>{"F","F","F+F+F-F-F_","+","+","-","-"} << 2UL << "F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F" ;
        //    }
    }
}
}

QTEST_MAIN(Plugins::Export::SVG::Test_SVG)
#include "Test_SVG.moc"
