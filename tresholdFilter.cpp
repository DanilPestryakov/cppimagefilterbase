#include "tresholdFilter.h"

void tresholdFilter::applyFilter(image_data imgData) {
	char* newBuf;
	std::vector<int> matrix;
	int newCoord[4];
	int size = imgData.h * imgData.w * imgData.compPerPixel;
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
	newBuf = new char[size];
	memcpy(newBuf, imgData.pixels, size);
	for (int i = newCoord[0]; i < newCoord[2]; i++)
	{
		for (int j = newCoord[1]; j < newCoord[3]; j++)
		{
			for (int t = -2; t <= 2; t++)
			{
				for (int k = -2; k <= 2; k++)
				{
					if (!((i + t) < newCoord[0] || (i + t) >= newCoord[2] || (j + k) < newCoord[1] || (j + k) >= newCoord[3]))
					{
						int pos = ((i + t) * imgData.w + j + k) * imgData.compPerPixel;
						matrix.push_back(newBuf[pos]);
					}
				}
			}
			std::sort(matrix.begin(), matrix.end());
			if (matrix[matrix.size() / 2] > newBuf[(i * imgData.w + j) * imgData.compPerPixel])
			{
				int pos = (i * imgData.w + j) * imgData.compPerPixel;
				imgData.pixels[pos] = (unsigned char)0;
				imgData.pixels[pos + 1] = (unsigned char)0;
				imgData.pixels[pos + 2] = (unsigned char)0;
			}
			matrix.clear();
		}
	}
}


int tresholdFilter::returnMedian(char arr[], int size, char elem)
{
	int key = 0;
	char temp;
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
