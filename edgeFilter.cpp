#include "edgeFilter.h"

void edgeFilter::applyFilter(image_data imgData) {
	int newW;
	int newH;
	int newLineSize;
	int pos;
	int sum;
	char* newBuf;
	int lineSize;
	bwFilter bw(u, l, b, r);
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
	newBuf = new char[(newW + 2) * (newH + 2)];
	bw.applyFilter(imgData);
	if (l != 0 && u != 0)
		pos = lineSize * (imgData.h / l) + imgData.compPerPixel * (imgData.w / u + 1);
	if (l == 0 && u != 0)
		pos = imgData.compPerPixel * (imgData.w / u + 1);
	if (l != 0 && u == 0)
		pos = lineSize * (imgData.h / l) + imgData.compPerPixel;
	if (l == 0 && u == 0)
		pos = 0;
	for (int i = 0; i < newH; i++)
	{
		for (int j = 0; j < newLineSize; j += imgData.compPerPixel)
		{
			sum = 0;
			for (int t = -1; t <= 1; t++)
			{
				for (int k = -1; k <= 1; k++)
				{
					if (!((i + t) < 0 || (i + t) >= newH || (j + imgData.compPerPixel * k) < 0 || (j + imgData.compPerPixel * k) >= newW * imgData.compPerPixel))
					{
						if (k == 0 && t == 0)
							sum += (9 * imgData.pixels[pos + (lineSize) * (i + t) + (j + imgData.compPerPixel * k)]);
						else
							sum -= imgData.pixels[pos + (lineSize) * (i + t) + (j + imgData.compPerPixel * k)];
					}
				}
			}
			sum /= 9;
			if (sum < 0)
				sum = 0;
			if (sum >= 256)
				sum = 255;
			newBuf[newW * i + j] = sum;
		}
	}
	for (int i = 0; i <= newH; i++)
	{
		for (int j = 0; j < newLineSize; j += 3)
		{
			imgData.pixels[pos + (lineSize)* i + j] = (unsigned char)newBuf[newW * i + j];
			imgData.pixels[pos + (lineSize)* i + j + 1] = (unsigned char)newBuf[newW * i + j];
			imgData.pixels[pos + (lineSize)* i + j + 2] = (unsigned char)newBuf[newW * i + j];
		}
	}
}