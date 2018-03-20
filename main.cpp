
#include "VolImage.h"

using namespace std;

// argc (argument in main) tells you the number of all items on the command line
// (application name included) items are seperated by spaces

// The argv array contains simple C-strings for each item 
// (e.g. argv[0] is always the application name and argv[1] the first argument)

int main(int argc, char* argv[]) //different arguments than usual
{ 
	tldlir001::VolImage *v = new tldlir001::VolImage();
	

	(*v).readImages("brain_mri_raws/MRI"); 

	//(*v).extract(0,"output"); 
	(*v).diffmap(0,1,"output");


	/*
	//(*v).readImages(argv[1]);
	
	if(argv[2]=="-d")
	{
		(*v).diffmap(argv[3],argv[4],argv[5]);
	}
	else if(argv[2]=="-x")
	{
		(*v).extract(argv[3],argv[4]);
	}
	*/

	return 0;
}