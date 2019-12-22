#pragma once
#include "png_toolkit.h"

class abstractFilter {
public:
	virtual void applyFilter(image_data imgData) = 0;
};