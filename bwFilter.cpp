#include "bwFilter.h"

void bwFilter::applyFilter(image_data imgData) {
	int x;
	int newCoord[4];
	if (u != 0)
		newCoord[0] = imgData.h / u;
	else
		newCoord[0] = 0;
	if (l != 0)
		newCoord[1] = imgData.w / l;
	else
		newCoord[1] = 0;
	if (b != 0)
		newCoord[2] = imgData.h / b;
	else
		newCoord[2] = 0;
	if (r != 0)
		newCoord[3] = imgData.w / r;
	else
		newCoord[3] = 0;
	for (int i = newCoord[0]; i < newCoord[2]; i++)
	{
		for (int j = newCoord[1]; j < newCoord[3]; j++) 
		{
			int pos = (i * imgData.w + j) * imgData.compPerPixel;
			x = (3 * imgData.pixels[pos] + 6 * imgData.pixels[pos + 1] + imgData.pixels[pos + 2]) / 10;
			imgData.pixels[pos] = (unsigned char)x;
			imgData.pixels[pos + 1] = (unsigned char)x;
			imgData.pixels[pos + 2] = (unsigned char)x;
		}
	}
}
