#pragma once

#include "GameWindow.h"

class COMInitializer
{
public:
	COMInitializer();
	~COMInitializer();
private:
	HRESULT hr;
};