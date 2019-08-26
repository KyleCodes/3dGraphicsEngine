#include <iostream>
#include "olcConsoleGameEngine.h"
using namespace std;

struct vec3d
{
	float x, y, z;
};

struct triangle
{
	vec3d p[3];
};

struct mesh
{
	vector<triangle> tris;
};

struct mat4x4
{
	float m[4][4] = { 0 };
};

class engine3D : public olcConsoleGameEngine
{
private: 
	mesh meshCube;
	mat4x4 matProj;
public:
	engine3D()
	{
		m_sAppName = L"3d Demo";
	}

public:
	bool OnUserCreate() override
	{
		// Creating a unit cube for testing the display functionality

		meshCube.tris = {

			// SOUTH
			{0.0f, 0.0f, 0.0f,	0.0f, 1.0f, 0.0f,	1.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f,	1.0f, 1.0f, 0.0f,	1.0f, 0.0f, 0.0f},

			// EAST
			{1.0f, 0.0f, 0.0f,	1.0f, 1.0f, 0.0f,	1.0f, 1.0f, 1.0f},
			{1.0f, 0.0f, 0.0f,	1.0f, 1.0f, 1.0f,	1.0f, 1.0f, 1.0f},

			// NORTH
			{1.0f, 0.0f, 1.0f,	1.0f, 1.0f, 1.0f,	0.0f, 1.0f, 1.0f},
			{1.0f, 0.0f, 1.0f,	0.0f, 1.0f, 1.0f,	0.0f, 0.0f, 1.0f},

			// WEST
			{0.0f, 0.0f, 1.0f,	0.0f, 1.0f, 1.0f,	0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 1.0f,	0.0f, 1.0f, 0.0f,	0.0f, 0.0f, 0.0f},

			// TOP 
			{0.0f, 1.0f, 0.0f,	0.0f, 1.0f, 1.0f,	1.0f, 1.0f, 1.0f},
			{0.0f, 1.0f, 0.0f,	1.0f, 1.0f, 1.0f,	1.0f, 1.0f, 0.0f},
			
			// BOTTOM
			{1.0f, 0.0f, 1.0f,	0.0f, 0.0f, 1.0f,	0.0f, 0.0f, 0.0f},
			{1.0f, 0.0f, 1.0f,	0.0f, 0.0f, 0.0f,	1.0f, 0.0f, 0.0f},

		};
		
		// Populate projection matrix
		float fNear = 0.1f;
		float fFar = 1000.0f;
		float fFov = 90.0f;
		float aspectRatio = (float)ScreenHeight() / (float)ScreenWidth();
		float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLACK);

		// Draw triangles
		for(auto tri: meshCube.tris)

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


