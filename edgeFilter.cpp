#include "edgeFilter.h"

void edgeFilter::applyFilter(image_data imgData) {
	int sum;
	char* newBuf;
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
	newBuf = new char[imgData.h * imgData.w];
	bw.applyFilter(imgData);
	for (int i = newCoord[0]; i < newCoord[2]; i++)
	{
		for (int j = newCoord[1]; j < newCoord[3]; j++)
		{
			sum = 0;
			for (int t = -1; t <= 1; t++)
			{
				for (int k = -1; k <= 1; k++)
				{
					if (!((i + t) < newCoord[0] || (i + t) >= newCoord[2] || (j + k) < newCoord[1] || (j + k) >= newCoord[3]))
					{
						int pos = ((i + t) * imgData.w + j + k) * imgData.compPerPixel;
						if (t == 0 && k == 0)
							sum += (9 * imgData.pixels[pos]);
						else
							sum -= imgData.pixels[pos];
					}

				}
			}
			if (sum < 0)
				sum = 0;
			if (sum > 255)
				sum = 255;
			newBuf[i * imgData.w + j] = sum;
		}
	}
	for (int i = newCoord[0]; i < newCoord[2]; i++)
	{
		for (int j = newCoord[1]; j < newCoord[3]; j++)
		{
			int pos = (i * imgData.w + j) * imgData.compPerPixel;
			int posBuf = (i * imgData.w + j);
			imgData.pixels[pos] = (unsigned char)newBuf[posBuf];
			imgData.pixels[pos + 1] = (unsigned char)newBuf[posBuf];
			imgData.pixels[pos + 2] = (unsigned char)newBuf[posBuf];
		}
	}
}
