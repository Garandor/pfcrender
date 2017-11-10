#ifndef MODEL_CUSTOM_GEOMETRY_MODEL_H
#define MODEL_CUSTOM_GEOMETRY_MODEL_H

#include<memory>
#include <QQuickItem>
#include <QString>
#include <QSGNode>

class QSGGeometryNode;

namespace ViewModel
{
class CustomGeometryModel : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QSizeF vertexSize MEMBER m_vertexSize READ vertexSize NOTIFY orgSizeChanged)

    signals:
        void viewModelChanged();
        void orgSizeChanged();

    public:
        CustomGeometryModel();
        ~CustomGeometryModel();
        QSizeF vertexSize();

        void setGeometryNode(QSGGeometryNode* newNode);

    protected:
        virtual QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* updatePaintNodeData) override final;

    private:

        void _setNewOuterDimensions();
        QSGNode* p_node;
        QSizeF m_vertexSize;

};

}  // namespace Model
#endif
