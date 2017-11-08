#include "CustomGeometryModel.h"
#include "Model/LSYSModel.h"

namespace ViewModel
{
class ViewModelFactory
{
public slots:
    void onModelChanged(const QString* const );


private:
    std::unique_ptr<QSGGeometryNode> _createGeometry(const QString& curve);
public:
    CustomGeometryModel generateVM();

 friend std::unique_ptr<QSGGeometryNode> createGeom(const QString&);
};

 std::unique_ptr<QSGGeometryNode> createGeom(const QString&);
}
