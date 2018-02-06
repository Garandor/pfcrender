#ifndef MODEL_CUSTOM_GEOMETRY_MODEL_H
#define MODEL_CUSTOM_GEOMETRY_MODEL_H

#include <QQuickItem>
#include <QRectF>

class QSGNode;
class QSGGeometryNode;

namespace QtGUI {
class CustomGeometryModel : public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(QSizeF vertexSize MEMBER m_vertexSize READ vertexSize NOTIFY orgSizeChanged)

signals:
    void viewModelChanged();
    void orgSizeChanged();

public:
    CustomGeometryModel();
    ~CustomGeometryModel();
    QSizeF vertexSize();

    void setGeometryNode(std::pair<QSGGeometryNode*, QRectF> vm);

protected:
    virtual QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* updatePaintNodeData) override final;

private:
    void _normalizeGeometry(QRectF& boundingBox);
    QSGNode* p_node;
    QSizeF m_vertexSize;
};

} // namespace QtGUI
#endif
