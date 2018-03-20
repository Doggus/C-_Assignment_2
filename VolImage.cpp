
#include "VolImage.h"
#include <fstream>
#include <sstream>
#include <iterator>
#include <cstdlib>
#include <cmath>


using namespace std;

tldlir001::VolImage::VolImage()
{
    width = 0;
    height = 0;
    numImg = 0;
}


tldlir001::VolImage::~VolImage() // destructor method
{
   //delete[] slices;

	for (int i = 0; i < numImg; i++)
	{
		for (int j = 0; j < height; j++)
		{
			delete[] slices[i][j];
		}

		delete[] slices[i];
	}
}


bool tldlir001::VolImage::readImages(string baseName)
{
	
	ifstream in(baseName + ".data");
	//int numImg = 0;


	// allocate space for vector to store byte data based off of header file (width, height, number of imgs)
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

		//----------------------------------------------------

        //storing byte data in vector
        for (int i = 0; i < numImg; i++)
    	{
    		//instream here
    		string file = "brain_mri_raws/MRI" + to_string(i) + ".raw";
    		ifstream inRaw(file,ios::binary);

    		for(int j = 0; j < height; j++)
    		{
    			//either:
    			inRaw.read((char *)slices[i][j], width);  //(char *) casts to char pointer
    	
    			//or:
    			/*
    			for(int k=0; k < width; k++)
    			{
    				unsigned char c = inRaw.get();
    				slices[i][j][k] = c;

    			}
    			*/
    			
    		}
    	}
        	
        
    	//cout<< slices[0] << endl; // prints address
    	//cout << slices[0][0] << endl; // prints out byte data of MRI0.raw
    	//cout << slices[0][1] << endl; // prints out more byte data from MRI0.raw


        return true;
    }


	return false;
}

void tldlir001::VolImage::diffmap(int sliceI, int sliceJ, string output_prefix)
{
	
	//creating new directory
	string folder = "mkdir -p " + output_prefix;
	const int dir_err = system(folder.c_str());
	if (-1 == dir_err)
	{
   	 	printf("An error Occurred when creating the directory");
   		exit(1);
	}

	ofstream dmap;
    dmap.open("./" + output_prefix + "/" + output_prefix + ".raw");

	for (int r = 0; r < height; r++)
	{
		for (int c = 0; c < width; c++)
		{
			//either:
			//dmap.put((unsigned char)(abs( (float)slices[sliceI][r][c] - (float)slices[sliceJ][r][c]) / 2));
			//or:
			dmap << (unsigned char)(abs( (float)slices[sliceI][r][c] - (float)slices[sliceJ][r][c]) / 2);
		}
	}

	dmap.close();

}

void tldlir001::VolImage::extract(int sliceId, string output_prefix)
{
	//creating new directory
	string folder = "mkdir -p " + output_prefix;
	const int dir_err = system(folder.c_str());
	if (-1 == dir_err)
	{
   	 	printf("An error Occurred when creating the directory");
   		exit(1);
	}

	 //creates header(data) file in new directory 
	 ofstream header;
     header.open("./" + output_prefix + "/" + output_prefix + ".data");
     header << "1 1 1" << endl;
     header.close();

     //writes byte data to .raw file in new directory
     ofstream raw;
     raw.open("./" + output_prefix + "/" + output_prefix + ".raw");

	for (int j = 0; j < height; j++)
    {
    	
    	raw << slices[sliceId][j] << endl;

    	//raw.put(slices[sliceIf][j]); //works?

    }

    raw.close();
	

}

// (Extra Credit)
int tldlir001::VolImage::volImageSize(void)
{
	return 0;
}