#ifndef MODEL_CUSTOM_GEOMETRY_MODEL_H
#define MODEL_CUSTOM_GEOMETRY_MODEL_H

#include <QQuickItem>

class QSGNode;
class QSGGeometryNode;

namespace ViewModel {
class CustomGeometryModel : public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(QSizeF vertexSize MEMBER m_vertexSize READ vertexSize NOTIFY orgSizeChanged)
    Q_PROPERTY(bool loading MEMBER m_loading READ loading NOTIFY loadingChanged)

signals:
    void viewModelChanged();
    void orgSizeChanged();
    void loadingChanged();

public slots:
    void onNewGeometry(QSGGeometryNode const* const newNode); //TODO: Offload model creation to thread and return object through signal

public:
    CustomGeometryModel();
    ~CustomGeometryModel();
    QSizeF vertexSize();
    bool loading();

    void setGeometryNode(QSGGeometryNode* newNode);

protected:
    virtual QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* updatePaintNodeData) override final;

private:
    void _setNewOuterDimensions();
    QSGNode* p_node;
    QSizeF m_vertexSize;
    bool m_loading;
};

} // namespace Model
#endif
