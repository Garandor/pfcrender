#ifndef EXPORT_EXPORTER_H
#define EXPORT_EXPORTER_H

#include "Model/Curve.h"

namespace Export
{
class Exporter
{
public:
	virtual void exportToFile(char* filename, Model::Curve pfc)=0;

};

}  // namespace Export
#endif
