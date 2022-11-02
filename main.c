#include "raylib.h"
#include <stdio.h>

int GetState(int a, int b, int c, int d);
void MarchingSquares(int state, Vector2 a, Vector2 b, Vector2 c, Vector2 d);

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 900;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Marching Square");
	
	int res = 30;
	
	int col = (screenWidth / res) + 1;
	int row = (screenHeight / res) + 1;
	
	int field[row][col];
	
	Color color;

	SetTargetFPS(0.5);
	//--------------------------------------------------------------------------------------
	while (!WindowShouldClose())
	{		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				field[i][j] = GetRandomValue(0, 1);
			}
		}
		
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

			ClearBackground(BLACK);

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (field[i][j] == 1) color = LIGHTGRAY;
					else color = BLACK;
					DrawCircle(j * res, i * res, res * 0.2, color);
				}
			}
		
			for (int i = 0; i < row - 1; i++) {
				for (int j = 0; j < col - 1; j++) {
					int x = j * res;
					int y = i * res;
					Vector2 a = (Vector2){x + res / 2, y};
					Vector2 b = (Vector2){x + res, y + res / 2};
					Vector2 c = (Vector2){x + res / 2, y + res};
					Vector2 d = (Vector2){x, y + res / 2};
					
					int state = GetState(field[i][j], field[i][j + 1], field[i + 1][j + 1], field[i + 1][j]);					
					MarchingSquares(state, a, b, c, d);
				}
			}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

int GetState(int a, int b, int c, int d) {
	return a * 8 + b * 4 + c * 2 + d * 1;
}

void MarchingSquares(int state, Vector2 a, Vector2 b, Vector2 c, Vector2 d) {
	Color color = {GetRandomValue(100, 255), GetRandomValue(100, 255), GetRandomValue(100, 255), 255};
	switch (state) {
		case 1:
			DrawLineV(c, d, color);
			break;
		case 2:
			DrawLineV(b, c, color);
			break;
		case 3:
			DrawLineV(b, d, color);
			break;
		case 4:
			DrawLineV(a, b, color);
			break;
		case 5:
			DrawLineV(a, d, color);
			DrawLineV(b, c, color);
			break;
		case 6:
			DrawLineV(a, c, color);
			break;
		case 7:
			DrawLineV(a, d, color);
			break;
		case 8:
			DrawLineV(a, d, color);
			break;
		case 9:
			DrawLineV(a, c, color);
			break;
		case 10:
			DrawLineV(a, b, color);
			DrawLineV(c, d, color);
			break;
		case 11:
			DrawLineV(a, b, color);
			break;
		case 12:
			DrawLineV(b, d, color);
			break;
		case 13:
			DrawLineV(b, c, color);
			break;
		case 14:
			DrawLineV(c, d, color);
			break;
		default:
			break;
	}
}