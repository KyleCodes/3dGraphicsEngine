#include <iostream>
#include "olcConsoleGameEngine.h"
using namespace std;

class engine3D : public olcConsoleGameEngine
{
public:
	engine3D()
	{
	}

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		return true;
	}
};

int main()
{
	engine3D demo; 
	if (demo.ConstructConsole(256, 240, 4, 4))
		demo.Start();
	else
		cout << "error starting the console graphics engine\n";

	return 0;
}


