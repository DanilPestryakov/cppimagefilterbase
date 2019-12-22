#pragma once
#include "abstractFilter.h"
#include "bwFilter.h"

class edgeFilter : public abstractFilter {
public:
	edgeFilter(int u, int l, int b, int r) {
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