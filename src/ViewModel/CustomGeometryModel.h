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

    signals:
        void viewModelChanged();
        void dimensionChanged();

    public:
        CustomGeometryModel();
        ~CustomGeometryModel();

        void setGeometryNode(QSGGeometryNode* newNode);

    protected:
        virtual QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* updatePaintNodeData) override final;

    private:

        void _setNewOuterDimensions();
        QSGNode* p_node;

};

}  // namespace Model
#endif
