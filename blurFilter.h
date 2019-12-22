#ifndef BLUR_FILTER_H
#define BLUR_FILTER_H
#include "abstractFilter.h"
#include "bwFilter.h"

class blurFilter : public abstractFilter {
public:
	blurFilter(int u, int l, int b, int r) {
		this->u = u;
		this->l = l;
		this->b = b;
		this->r = r;
	}
	virtual void applyFilter(image_data imgData);
private:
	int u;
	int l;
	int b;
	int r;
};
#endif // BLUR_FILTER_H