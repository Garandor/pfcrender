#include<QtTest>
#include<QString>

class Test_GUI : public QObject
{
    Q_OBJECT

private slots:
    void buildString();
    void buildString_data();
};

void Test_GUI::buildString(){
//   QFETCH(QList<QString>, list);
//   QFETCH(ulong, iterates);
//   QFETCH(QString, resultString);

//    LSYS::LSYS cut{};

//    std::unique_ptr<QString> result = cut.getModel(list, iterates);

//    QCOMPARE(*(result.get()), resultString);
}

void Test_GUI::buildString_data()
{
//    QTest::addColumn<QList<QString>>("list");
//    QTest::addColumn<ulong>("iterates");
//    QTest::addColumn<QString>("resultString");

//    QTest::newRow("non PFC") << QList<QString>{"F","F","F+F+F-F-FF","+","+","-","-"} << 5UL << "F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF-F+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FFF+F+F-F-FF+F+F+F-F-FF+F+F+F-F-FF-F+F+F-F-FF-F+F+F-F-FFF+F+F-F-FF";
//    QTest::newRow("R5-Dragon it1") << QList<QString>{"F","F","F+F+F-F-F","+","+","-","-"} << 1UL << "F+F+F-F-F" ;
//    QTest::newRow("R5-Dragon it2") << QList<QString>{"F","F","F+F+F-F-F","+","+","-","-"} << 2UL << "F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F" ;
//    QTest::newRow("R5-Dragon it3") << QList<QString>{"F","F","F+F+F-F-F","+","+","-","-"} << 3UL << "F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F" ;
//    QTest::newRow("R5-Dragon it4") << QList<QString>{"F","F","F+F+F-F-F","+","+","-","-"} << 4UL << "F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F" ;
//    QTest::newRow("R5-Dragon it5") << QList<QString>{"F","F","F+F+F-F-F","+","+","-","-"} << 5UL << "F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F-F+F+F-F-F+F+F+F-F-F+F+F+F-F-F-F+F+F-F-F-F+F+F-F-F" ;
}
QTEST_MAIN(Test_GUI)
#include "Test_GUI.moc"
