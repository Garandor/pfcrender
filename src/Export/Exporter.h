#ifndef EXPORT_EXPORTER_H
#define EXPORT_EXPORTER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Model/Curve.h"

namespace Export
{
class Exporter
{
public:
	virtual void exportToFile(string filename, Model::Curve pfc)=0;

};

}  // namespace Export
#endif
