#include "bwFilter.h"

void bwFilter::applyFilter(image_data imgData) {
	int newW;
	int newH;
	int newLineSize;
	int pos;
	int x;
	int lineSize;
	if (u != 0)
		newW = imgData.w / b - imgData.w / u - 1;
	else
		newW = imgData.w / b - 1;
	if (l != 0)
		newH = imgData.h / r - imgData.h / l - 1;
	else
		newH = imgData.h / r - 1;
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
	for (int i = 0; i <= newH; i++)
	{
		for (int j = 0; j <= newLineSize; j += imgData.compPerPixel)
		{
			x = (3 * imgData.pixels[pos + (lineSize)* i + j] + 6 * imgData.pixels[pos + (lineSize)* i + j + 1] + imgData.pixels[pos + (lineSize)* i + j + 2]) / 10;
			imgData.pixels[pos + (lineSize)* i + j] = (unsigned char)x;
			imgData.pixels[pos + (lineSize)* i + j + 1] = (unsigned char)x;
			imgData.pixels[pos + (lineSize)* i + j + 2] = (unsigned char)x;
		}
	}
}