
#include <vector>
#include <string>
#include <iostream>

#ifndef VOLIMAGE_H // '#pragma once' can be used at the top instead of all the #ifndef ... #endif  
#define VOLIMAGE_H 


namespace tldlir001
{
    
    class VolImage
    {

    private: // private members
        
        int width, height; // width and height of image stack
        std::vector<unsigned char**> slices;  // data for each slice, in order

    public: // public members

        VolImage(); // default constructor - defined in .cpp
       
        ~VolImage(); // destructor - defined in .cpp file

        // populate the object with images in stack and
        //set member variables defined in .cpp
        bool readImages(std::string baseName);

        // compute difference map and write out; defined in .cpp
        void diffmap(int sliceI, int sliceJ, std::string output_prefix);

        // extract slice sliceId and write to output - defined in .cpp
        void extract(int sliceId, std::string output_prefix);

        // number of bytes uses to store image data bytes
        //and pointers (ignore vector<> container, dims etc)
        // defined in .cpp
        int volImageSize(void);

    };

}


    
#endif /* VOLIMAGE_H */
