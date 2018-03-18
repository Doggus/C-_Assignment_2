
#include "VolImage.h"
#include <fstream>
#include <sstream>
#include <iterator>


using namespace std;

tldlir001::VolImage::VolImage()
{
    width = 0;
    height = 0;
}

/*
tldlir001::VolImage::~VolImage() // destructor method
{
   
}
*/

bool tldlir001::VolImage::readImages(string baseName)
{
	
	ifstream in(baseName + ".data");
	int numImg= 0;

    if(!in)
    { 
       	cout << "Couldn't open file";
       	return false;
    }
    else
    {
    	for(string line; getline(in,line);)
        {

        	istringstream buf(line);
         	istream_iterator<string> beg(buf), end;
         
         	vector<string> tokens(beg,end);

			width = stoi(tokens[0]);
			height = stoi(tokens[1]);
			numImg = stoi(tokens[2]);

			slices.reserve(numImg);
        }

        for(int i = 0; i < numImg; i++)
        {
        	slices[i] = new unsigned char * [height];
        	for (int j = 0; j < height; j++)
        	{
        		slices[i][j] = new unsigned char[width];
        	}
        }

        slices[1][2][3] = 'b';
        cout << slices[1][2][3] << endl;

        return true;
    }


	return false;
}

void tldlir001::VolImage::diffmap(int sliceI, int sliceJ, string output_prefix)
{

}

void tldlir001::VolImage::extract(int sliceId, string output_prefix)
{

}

int  tldlir001::VolImage::volImageSize(void)
{
	return 0;
}