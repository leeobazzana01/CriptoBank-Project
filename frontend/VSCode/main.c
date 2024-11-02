#include <raylib.h>

Color yellow = {253, 219, 20, 255};
Color green = {20, 160, 133, 255};

typedef enum GameScreen {LOGIN = 0, MENU} GameScreen;



void DrawRoundedRectangle(int posX, int posY, int width, int height, float radius, Color color) {
    // Draw the main rectangle without corners
    DrawRectangle(posX + radius, posY, width - 2 * radius, height, color);
    DrawRectangle(posX, posY + radius, width, height - 2 * radius, color);
    
    // Draw the rounded corners
    DrawCircle(posX + radius, posY + radius, radius, color);
    DrawCircle(posX + width - radius, posY + radius, radius, color);
    DrawCircle(posX + radius, posY + height - radius, radius, color);
    DrawCircle(posX + width - radius, posY + height - radius, radius, color);
}
void DrawFilledRoundedRhombus(int centerX, int centerY, int width, int height, int radius, Color color) {
    Vector2 vertices[4] = {
        {centerX, centerY - height / 2},
        {centerX + width / 2, centerY},
        {centerX, centerY + height / 2},
        {centerX - width / 2, centerY}
    };

    for (int i = 0; i < 4; i++) {
        DrawCircle(vertices[i].x, vertices[i].y, radius, color);
    }

    // Preenchendo o losango
    for (int y = -height / 2 + radius; y <= height / 2 - radius; y++) {
        for (int x = -width / 2 + radius; x <= width / 2 - radius; x++) {
            DrawPixel(centerX + x, centerY + y, color);
        }
    }

    DrawLineEx(vertices[0], vertices[1], radius * 2, color);
    DrawLineEx(vertices[1], vertices[2], radius * 2, color);
    DrawLineEx(vertices[2], vertices[3], radius * 2, color);
    DrawLineEx(vertices[3], vertices[0], radius * 2, color);
}

int main() 
{

  // Fontes


    

    InitWindow(1600, 900, "LP /Cripto");
    SetTargetFPS(60);

    GameScreen currentScreen = LOGIN;
    Rectangle loginbotao = {700, 700, 200, 50};

    while(WindowShouldClose() == false) 
    {
        Font fontTtf = LoadFontEx("resources/Baxoe.ttf", 32, 0, 250);
                Font baxomaior = LoadFontEx("resources/Baxoe.ttf", 150, 0, 250);
        Font cwgTtf = LoadFontEx("resources/cwg.ttf", 32, 0, 250);
        Font daysone = LoadFontEx("resources/DaysOne-Regular.ttf", 150, 0, 250);
        Font dance = LoadFontEx("resources/Dance.ttf", 90, 0, 250);
                Font daystwo = LoadFontEx("resources/DaysOne-Regular.ttf", 100, 0, 250);

        BeginDrawing();

        if(currentScreen == LOGIN)
        { // tela inicial
        ClearBackground(WHITE);

        DrawRectangleRec(loginbotao, WHITE);    
 
        DrawRoundedRectangle(699, 699, 202, 52, 20, BLACK);
        DrawRoundedRectangle(700, 700, 200, 50, 20, yellow);

        DrawTextEx(fontTtf, "Login", (Vector2){773, 712}, fontTtf.baseSize, 2, BLACK);

        DrawFilledRoundedRhombus(400, 300, 85, 85, 55, BLACK);
        DrawFilledRoundedRhombus(400, 430, 85, 85, 55, yellow);
            DrawTextEx(daysone, "L", (Vector2){384, 265}, 70, 2, yellow);
            DrawTextEx(daysone, "P", (Vector2){384, 395}, 70, 2, BLACK);
            DrawTextEx(daysone, "/cripto", (Vector2){520, 325}, 95, 6, BLACK);
            DrawTextEx(daystwo, "The safest, the easier, the smartest choice.", (Vector2){290, 560}, 55, 2, BLACK);

        if(CheckCollisionPointRec(GetMousePosition(), loginbotao))
        {
            DrawRectangleRec(loginbotao, WHITE);        
            DrawRoundedRectangle(699, 699, 212, 62, 20, BLACK);
            DrawRoundedRectangle(700, 700, 210, 60, 20, yellow);
              
            DrawTextEx(fontTtf, "Login", (Vector2){773, 712}, fontTtf.baseSize, 2, BLACK);
        }

        }
        else if(currentScreen == MENU){    
        DrawRoundedRectangle(699, 699, 202, 52, 20, BLACK);
        DrawRoundedRectangle(700, 700, 200, 50, 20, WHITE);


        DrawFilledRoundedRhombus(400, 300, 500, 500, 35, BLACK);
        DrawFilledRoundedRhombus(400, 430, 500, 500, 35, yellow);

        }


        {
            if (CheckCollisionPointRec(GetMousePosition(), loginbotao) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentScreen = MENU;
            }
        }

// para lembrar: drawrectangle(posxdocantosupesquerd,posydeletmb, largura, altura, raio das borda redonda)
        EndDrawing();
    }
    CloseWindow();
    return 0;
}