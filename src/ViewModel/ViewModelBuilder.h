#include "CustomGeometryModel.h"
#include "Model/LSYSModel.h"

namespace ViewModel
{
   class PolarVector2D;

class ViewModelBuilder
{
public slots:
    void onModelChanged(const QString* const );


private:
    QSGGeometryNode* _createGeometry(const QString& curve);
public:

 friend QSGGeometryNode* createGeom(const QString&);
};

 QSGGeometryNode* createGeom(const QString&);

}
