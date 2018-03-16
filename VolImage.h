
#include <vector>
#include <string>
#include <iostream>

#ifndef VOLIMAGE_H // '#pragma once' can be used at the top instead of all the #ifndef ... #endif  
#define VOLIMAGE_H 


namespace tldlir001
{
    
    class VolImage
    {

    private:
        
        int width, height;
        std::vector<unsigned char**> slices;   

    public:

        VolImage();
       
        ~VolImage();

        bool readImages(std::string baseName);

        void diffmap(int sliceI, int sliceJ, std::string output_prefix);

        void extract(int sliceId, std::string output_prefix);

        int volImageSize(void);

    };

}


    
#endif /* VOLIMAGE_H */
