#ifndef PLUGINS_LSYS_2_D_SHAPE_MODEL_H
#define PLUGINS_LSYS_2_D_SHAPE_MODEL_H

#include <QPainter>
#include <QQuickPaintedItem>

namespace Plugins
{
namespace LSYS
{
class PFCModel : public QQuickPaintedItem
{
public:
	/**
	 *  
	 */
        void paint(QPainter  painter);

};

}  // namespace LSYS
}  // namespace Plugins
#endif
