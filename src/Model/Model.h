#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Model/2DShapeModel.h"

namespace Model
{
class Model
{
public:
	virtual 2DShapeModel getModel()=0;

	virtual void<<signal>> modelChanged()=0;

};

}  // namespace Model
#endif
