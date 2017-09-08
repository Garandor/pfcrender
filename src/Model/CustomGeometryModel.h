#ifndef MODEL_CUSTOM_GEOMETRY_MODEL_H
#define MODEL_CUSTOM_GEOMETRY_MODEL_H

#include<memory>
#include <QQuickItem>
#include <QString>
#include <QSGNode>
#include <QSGGeometryNode>


namespace Model
{
class CustomGeometryModel : public QQuickItem
{
    Q_OBJECT
private:
    QString type;

protected:
    virtual QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* updatePaintNodeData) override final;
public:
    CustomGeometryModel();
    ~CustomGeometryModel();
    QString getType();

    void setGeometryNode(std::unique_ptr<QSGGeometryNode> newNode);

private:
    std::unique_ptr<QSGGeometryNode> m_geometry;

signals:
    void modelChanged();
};

}  // namespace Model
#endif
