#pragma once
#include "Garbage.h"

class PaperGarbage : public Garbage {

private:
	bool isSqueezed;

public:
	PaperGarbage() : isSqueezed{ false } {};
	bool getIsSqueezed();
	void squeezed();

};
