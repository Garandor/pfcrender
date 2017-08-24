#ifndef QTCLI_P_F_C_RENDER_H
#define QTCLI_P_F_C_RENDER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Qt/QGUIApplication.h"

namespace QtCLI
{
/**
 * Project pfcrender 
 * 
 * @author Adam Reif
 * 
 * 
 * 
 * @version 0.1
 */
class PFCRender : public Qt::QGUIApplication
{
public:
	int someflag;


public:
	/**
	 * Project pfcrender 
	 * 
	 * @author Adam Reif
	 * 
	 * 
	 * 
	 * @version 0.1 Builder implementation
	 * 
	 * 
	 * 
	 * @return int
	 */
	int do_stuff();

};

}  // namespace QtCLI
#endif
