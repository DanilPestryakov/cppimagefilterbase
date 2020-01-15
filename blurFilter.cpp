#include "blurFilter.h"

void blurFilter::applyFilter(image_data imgData) {
	int sumR;
	int sumG;
	int sumB;
	char* newBuf;
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
	newBuf = new char[imgData.h * imgData.w * imgData.compPerPixel];
	for (int i = newCoord[0]; i < newCoord[2]; i++)
	{
		for (int j = newCoord[1]; j < newCoord[3]; j++)
		{
			sumR = 0;
			sumG = 0;
			sumB = 0;
			for (int t = -1; t <= 1; t++)
			{
				for (int k = -1; k <= 1; k++)
				{
					if (!((i + t) < newCoord[0] || (i + t) >= newCoord[2] || (j + k) < newCoord[1] || (j + k) >= newCoord[3]))
					{
						int pos = ((i + t) * imgData.w + j + k) * imgData.compPerPixel;
						sumR += imgData.pixels[pos];
						sumG += imgData.pixels[pos + 1];
						sumB += imgData.pixels[pos + 2];
					}
						
				}
			}
			sumR /= 9;
			sumG /= 9;
			sumB /= 9;
			if (sumR < 0)
				sumR = 0;
			if (sumR >= 256)
				sumR = 255;
			if (sumG < 0)
				sumG = 0;
			if (sumG >= 256)
				sumG = 255;
			if (sumB < 0)
				sumB = 0;
			if (sumB >= 256)
				sumB = 255;
			int posBuf = (i * imgData.w + j) * imgData.compPerPixel;
			newBuf[posBuf] = sumR;
			newBuf[posBuf + 1] = sumG;
			newBuf[posBuf + 2] = sumB;

		}
	}
	for (int i = newCoord[0]; i < newCoord[2]; i++)
	{
		for (int j = newCoord[1]; j < newCoord[3]; j++)
		{
			int pos = (i * imgData.w + j) * imgData.compPerPixel;
			imgData.pixels[pos] = (unsigned char)newBuf[pos];
			imgData.pixels[pos + 1] = (unsigned char)newBuf[pos + 1];
			imgData.pixels[pos + 2] = (unsigned char)newBuf[pos + 2];
		}
	}
}
