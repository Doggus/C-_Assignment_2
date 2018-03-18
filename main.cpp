
#include "VolImage.h"

using namespace std;

int main(int argc, char* argv[]) //different arguments than usual
{ 
	tldlir001::VolImage *v = new tldlir001::VolImage();
	(*v).readImages("brain_mri_raws/MRI");




	return 0;
}