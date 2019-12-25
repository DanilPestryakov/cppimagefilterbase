#include "redFilter.h"
void redFilter::applyFilter(image_data imgData) {
	int newW;
	int newH;
	int newLineSize;
	int pos;
	int lineSize;
	int newW1;
	int newW2;
	int newH1;
	int newH2;
	if (u != 0){
		newW = imgData.w / b - imgData.w / u - 1;
		newW1 = imgData.w / u;
		newW2 = imgData.w / b;
	}
	else{
		
		newW = imgData.w / b - 1;
		newW1 = imgData.w / u;
		newW2 = imgData.w / b;
	}
	if (l != 0)
	{
			newH = imgData.h / r - imgData.h / l - 1;
		newH1 = imgData.h / l;
		newH2 = imgData.h / r;
	
	}
	else{
			newH = imgData.h / r - 1;
		newH1 = imgData.h / l;
		newH2 = imgData.h / r;
	
	}
	newLineSize = imgData.compPerPixel * newW;
	lineSize = imgData.compPerPixel * imgData.w;
	if (l != 0 && u != 0)
		pos = lineSize * (imgData.h / l) + imgData.compPerPixel * (imgData.w / u + 1);
	if (l == 0 && u != 0)
		pos = imgData.compPerPixel * (imgData.w / u + 1);
	if (l != 0 && u == 0)
		pos = lineSize * (imgData.h / l) + imgData.compPerPixel;
	if (l == 0 && u == 0)
		pos = 0;
	for (int i = newW1; i < newW2; i++)
	{
		for (int j = newH1; j < newH2; j++)
		{
			imgData.pixels[(imgData.w * i + j) * imgData.compPerPixel] = (unsigned char)255;
			imgData.pixels[(imgData.w * i + j) * imgData.compPerPixel + 1] = (unsigned char)0;
			imgData.pixels[(imgData.w * i + j) * imgData.compPerPixel + 2] = (unsigned char)0;
		}
	}
}
