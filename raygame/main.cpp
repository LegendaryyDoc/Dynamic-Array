#include "raylib.h"
#include "tVecor.h"
#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));

	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	tVector<int> v;

	while (!WindowShouldClose())    
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			v.push_back(rand() % 10);

			for (size_t i = 0; i < v.size(); ++i)
			{
				v.at(i);
			}
			v.capacity();
			v.size();
			std::cout << "\n" << std::endl;
		}
		EndDrawing();
	}
	CloseWindow(); 
	return 0;
}