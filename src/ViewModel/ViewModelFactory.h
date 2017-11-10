#include "CustomGeometryModel.h"
#include "Model/LSYSModel.h"

namespace ViewModel
{
class ViewModelFactory
{
public slots:
    void onModelChanged(const QString* const );


private:
    QSGGeometryNode* _createGeometry(const QString& curve);
public:
    CustomGeometryModel generateVM();

 friend QSGGeometryNode* createGeom(const QString&);
};

 QSGGeometryNode* createGeom(const QString&);
}
