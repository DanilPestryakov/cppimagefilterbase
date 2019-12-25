#include "redFilter.h"
void redFilter::applyFilter(image_data imgData) {
	int newW1;
	int newW2;
	int newH1;
	int newH2;
	if (u != 0){
		newH1 = imgData.h / u;
		newH2 = imgData.h / b;
	}
	else{
		newH1 = 0;
		newH2 = imgData.h / b;
	}
	if (l != 0)
	{
		newW1 = imgData.w / l;
		newW2 = imgData.w / r;
	}
	else{
		newW1 = 0;
		newW2 = imgData.w / r;
	}

	for (int i = newH1; i < newH2; i++)
	{
		for (int j = newW1; j < newW2; j++)
		{
			imgData.pixels[(imgData.w * i + j) * imgData.compPerPixel] = (unsigned char)255;
			imgData.pixels[(imgData.w * i + j) * imgData.compPerPixel + 1] = (unsigned char)0;
			imgData.pixels[(imgData.w * i + j) * imgData.compPerPixel + 2] = (unsigned char)0;
		}
	}
}

