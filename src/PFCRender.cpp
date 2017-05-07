#include "PFCRender.h"

PFCRender::PFCRender(){
	do_stuff();
}

void PFCRender::do_stuff(){
	cout << "hi" << endl;
}

int main(int argc, char** argv)
{
	new PFCRender();
	return 0;
}
