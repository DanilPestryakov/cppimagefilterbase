#pragma once
#include "abstractFilter.h"

class redFilter : public abstractFilter {
public:
	redFilter(int u, int l, int b, int r) {
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