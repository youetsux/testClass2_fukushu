#include "stdafx.h"
#include "baseChar.h"

void baseChar::SetMyRect(double _size)
{
	Vec2 hosei = { _size / 2, _size / 2 };
	myRect = { pos - hosei, _size, _size };
}
