// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Image.h"
#include "Matrix.h"
#include "processing.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4 && argc != 5)
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }
    
    string input_file = argv[1];
    string output_file = argv[2];
    int new_width = atoi(argv[3]);
    ifstream fin(input_file);
    ofstream fout(output_file);
    
    if (!fin.is_open())
    {
        cout << "Error opening file: " << input_file << endl;
        return 1;
    }
    
    if (!fout.is_open())
    {
        cout << "Error opening file: " << output_file << endl;
        return 1;
    }
    
    Image *img = new Image;
    Image_init(img, fin);
    int image_width = Image_width(img);
    int img_height = Image_height(img);
    
    if (argc == 4)
    {
        if (new_width <= 0 || new_width > image_width)
        {
            cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                 << "WIDTH and HEIGHT must be less than or equal to original" << endl;
            return 1;
            
        }
    }
    else if (argc == 5)
    {
        int new_height = atoi(argv[4]);
        if (new_width <= 0 || new_width > image_width || new_height <= 0 ||
            new_height > img_height)
        {
            cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                 << "WIDTH and HEIGHT must be less than or equal to original" << endl;
            return 1;
        }
    }
    
    if (argc == 4)
    {
        seam_carve_width(img, new_width);
    }
    else if (argc == 5)
    {
        int new_height = atoi(argv[4]);
        seam_carve(img, new_width, new_height);
    }
    
    Image_print(img, fout);
    fin.close();
    fout.close();
    delete img;
}
