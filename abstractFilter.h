#ifndef ABSTRACT_FILTER_H
#define ABSTRACT_FILTER_H
#include "png_toolkit.h"

class abstractFilter {
public:
	virtual void applyFilter(image_data imgData) = 0;
};
#endif // ABSTRACT_FILTER_H