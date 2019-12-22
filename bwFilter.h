#ifndef BW_FILTER_H
#define BW_FILTER_H
#include "abstractFilter.h"

class bwFilter : public abstractFilter {
public:
	bwFilter(int u, int l, int b, int r) {
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
#endif // BW_FILTER_H