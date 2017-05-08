#include "projectinfo.h"

#include "PFCRender.h"

using namespace std;

PFCRender::PFCRender(){
	do_stuff();
}

void PFCRender::do_stuff(){
	cout << "hi, this is " << VERSION_STRING << endl;
}

int main(int argc, char** argv)
{
	new PFCRender();
	return 0;
}
