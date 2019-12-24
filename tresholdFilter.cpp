#include "tresholdFilter.h"

void tresholdFilter::applyFilter(image_data imgData) {
	int newW;
	int newH;
	int newLineSize;
	int pos;
	char* newBuf;
	char square[25];
	int counter;
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
	for (int i = 0; i <= newH; i++)
	{
		for (int j = 0; j < newLineSize; j += imgData.compPerPixel)
		{
			counter = 0;
			for (int t = -2; t <= 2; t++)
			{
				for (int k = -2; k <= 2; k++)
				{
					if (!((i + t) < 0 || (i + t) >= newH || (j + imgData.compPerPixel * k) < 0 || (j + imgData.compPerPixel * k) >= newW * imgData.compPerPixel))
					{
						square[counter] = imgData.pixels[(newLineSize) * (i + t) + (j + imgData.compPerPixel * k)];
						counter++;
					}
				}
			}
			if (!(returnMedian(square, counter, imgData.pixels[(newLineSize) * i + j])))
				newBuf[newW * i + j] = 0;
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


int tresholdFilter::returnMedian(char arr[], int size, char elem)
{
	int key = 0;
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		key = i + 1;
		temp = arr[key];
		for (int j = i + 1; j > 0; j--)
		{
			if (temp < arr[j - 1])
			{
				arr[j] = arr[j - 1];
				key = j - 1;
			}
		}
		arr[key] = temp;
	}
	if (elem < arr[size / 2])
		return 0;
	return 1;
}