#include "tresholdFilter.h"
void tresholdFilter::applyFilter(image_data imgData) {
	unsigned char* newBuf;
	unsigned char square[25];
	int count;
	int newCoord[4];
	bwFilter bw(u, l, b, r);
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
	bw.applyFilter(imgData);
	newBuf = new unsigned char[imgData.h * imgData.w];
	for (int i = newCoord[0]; i < newCoord[2]; i++)
	{
		for (int j = newCoord[1]; j < newCoord[3]; j++)
		{
			count = 0;
			for (int t = -2; t <= 2; t++)
			{
				for (int k = -2; k <= 2; k++)
				{
					if (!((i + t) < newCoord[0] || (i + t) >= newCoord[2] || (j + k) < newCoord[1] || (j + k) >= newCoord[3]))
					{
						int pos = ((i + t) * imgData.w + j + k) * imgData.compPerPixel;
						square[count] = imgData.pixels[pos];
						count++;
					}
				}
			}
			if (!returnMedian(square, count, imgData.pixels[(i * imgData.w + j) * imgData.compPerPixel]))
			{
				int pos = (i * imgData.w + j);
				newBuf[pos] = (unsigned char)0;
			}
			else
			{
				int pos = (i * imgData.w + j);
				newBuf[pos] = (unsigned char)255;
			}
		}
	}
	for (int i = newCoord[0]; i < newCoord[2]; i++)
	{
		for (int j = newCoord[1]; j < newCoord[3]; j++)
		{
			int pos = (i * imgData.w + j) * imgData.compPerPixel;
			int posBuf = (i * imgData.w + j);
			if (newBuf[posBuf] == (unsigned char)0)
			{
				imgData.pixels[pos] = (unsigned char)newBuf[posBuf];
				imgData.pixels[pos + 1] = (unsigned char)newBuf[posBuf];
				imgData.pixels[pos + 2] = (unsigned char)newBuf[posBuf];
			}
		}
	}
}


int tresholdFilter::returnMedian(unsigned char arr[], int size, unsigned char elem)
{
	int key = 0;
	unsigned char temp;
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
