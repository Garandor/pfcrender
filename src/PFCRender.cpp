#include <stdio>

PFCRender::PFCRender(){
	do_stuff();
};

public void PFCRender::do_stuff(){
	cout << "hi" << endl;
}

int main(int argc, void** argv)
{
	new PFCRender();
	return EXIT_SUCCESS;
};
