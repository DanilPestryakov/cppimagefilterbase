#include <iostream>
#include "png_toolkit.h"
#include "parser.h"
#include "redFilter.h" 
#include "tresholdFilter.h" 
#include "edgeFilter.h" 
#include "blurFilter.h" 

int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test images!
    try
    {
        if (argc != 4)
            throw "Not enough arguments";
        png_toolkit studTool;
        studTool.load(argv[2]);
		parser pars;
		pars.pars(argv[1]);
		for (int i = 0; i < pars.countOfFilters(); i++) {
			if (pars.GetString(i) == "Red") {
				redFilter filter(pars.GetU(i), pars.GetL(i), pars.GetB(i), pars.GetR(i));
				image_data img = studTool.getPixelData();
				filter.applyFilter(img);
			}
			if (pars.GetString(i) == "Treshold") {
				tresholdFilter filter(pars.GetU(i), pars.GetL(i), pars.GetB(i), pars.GetR(i));
				image_data img = studTool.getPixelData();
				filter.applyFilter(img);
			}
			if (pars.GetString(i) == "Edge") {
				edgeFilter filter(pars.GetU(i), pars.GetL(i), pars.GetB(i), pars.GetR(i));
				image_data img = studTool.getPixelData();
				filter.applyFilter(img);
			}
			if (pars.GetString(i) == "Blur") {
				blurFilter filter(pars.GetU(i), pars.GetL(i), pars.GetB(i), pars.GetR(i));
				image_data img = studTool.getPixelData();
				filter.applyFilter(img);
			}
		}
        studTool.save(argv[3]);
    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
