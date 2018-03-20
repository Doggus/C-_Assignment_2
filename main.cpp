
#include "VolImage.h"
#include <cstring>

using namespace std;

// argc (argument in main) tells you the number of all items on the command line
// (application name included) items are seperated by spaces

// The argv array contains simple C-strings for each item 
// (e.g. argv[0] is always the application name and argv[1] the first argument)

int main(int argc, char* argv[]) //different arguments than usual
{ 
	tldlir001::VolImage *v = new tldlir001::VolImage();
	

	//(*v).readImages("brain_mri_raws/MRI"); 

	//(*v).extract(0,"output"); 
	//(*v).diffmap(0,1,"output");


	//have to use cstrings inorder to make sure the command line parameters can be read as strings
	
	//(*v).readImages(argv[1]);
	
	if(strcmp(argv[2], "-d")==0) //equals to 0 means equals true
	{
		(*v).diffmap(stoi(argv[3]),stoi(argv[4]),argv[5]);
	}
	else if(strcmp(argv[2], "-x")==0)
	{
		(*v).extract(stoi(argv[3]),argv[4]);
	}
	


	delete v; //calls the ~VolImage method to clear 'v' from memory

	return 0;
}