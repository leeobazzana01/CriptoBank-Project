#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_CHARS 256

Color yellow = {253, 219, 20, 255};
Color green = {20, 160, 133, 255};
Color darkyellow = {253, 239, 90, 255};
Color darkgreen = {20, 160, 133, 255};
Color lightgreen = {129, 204, 184, 255};


typedef enum GameScreen {LOGIN = 0, MENULOGAR, REGISTRO} GameScreen;

Font daysone;

void InitResources() {
    // Inicialização da fonte
    daysone = LoadFontEx("resources/DaysOne-Regular.ttf", 150, 0, 250);
}

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

void DrawFadeRect(int x, int y, int width, int height, Color color) {
    for (int i = 0; i < height; i++) {
        float alpha = (float)(height - i) / height; // Calcular opacidade
        Color fadeColor = Fade(color, alpha);
        DrawRectangle(x, y + i, width, 1, fadeColor);
    }
}

void DrawLPSign(int xpos, int ypos, int xtam, int ytaman, int raio) {
    DrawFilledRoundedRhombus(xpos, ypos, xtam, ytaman, raio, BLACK);
    DrawFilledRoundedRhombus(xpos, ypos + (ytaman*1.5), xtam, ytaman, raio, yellow);

}


int main() 
{

    InitWindow(1600, 900, "LP /Crypto");
    SetTargetFPS(60);

    bool mouseOnText = false;
    char inputText[MAX_INPUT_CHARS] = "\0";
    int letterCount = 0;
    int framesCounter = 0;
    int letterCount2 = 0;
    int framesCounter2 = 0;
    char inputText2[MAX_INPUT_CHARS] = "\0";
    int a, i;
    char input1[MAX_INPUT_CHARS] = "\0";

    GameScreen currentScreen = LOGIN;
    Rectangle loginbotao = {700, 700, 200, 50};
    Rectangle caixatexto1 = {1250, 460, 200, 50};
    Rectangle caixatexto2 = {1250, 530, 200, 50};
    Rectangle registrobotao = {1285, 595, 150, 25};

    while(WindowShouldClose() == false) 
    {
        Font fontTtf = LoadFontEx("resources/Baxoe.ttf", 32, 0, 250);
                Font baxomaior = LoadFontEx("resources/Baxoe.ttf", 150, 0, 250);
        Font cwgTtf = LoadFontEx("resources/cwg.ttf", 32, 0, 250);
        Font daysone = LoadFontEx("resources/DaysOne-Regular.ttf", 150, 0, 250);
        Font dance = LoadFontEx("resources/Dance.ttf", 90, 0, 250);
            Font dance1 = LoadFontEx("resources/Dance.ttf", 14, 0, 250);
                Font daystwo = LoadFontEx("resources/DaysOne-Regular.ttf", 100, 0, 250);
                Font daysthree = LoadFontEx("resources/DaysOne-Regular.ttf", 20, 0, 250);

        BeginDrawing();

        if(currentScreen == LOGIN)
        { // tela inicial
        ClearBackground(WHITE);

        DrawFadeRect(0, 0, 1900, 900, darkyellow);

        DrawRectangleRec(loginbotao, WHITE);    
 
        // DrawRoundedRectangle(699, 699, 202, 52, 20, BLACK);
        DrawRoundedRectangle(700, 700, 200, 50, 20, yellow);

        DrawTextEx(fontTtf, "Login", (Vector2){773, 712}, fontTtf.baseSize, 2, BLACK);

        DrawFilledRoundedRhombus(400, 300, 85, 85, 55, BLACK);
        DrawFilledRoundedRhombus(400, 430, 85, 85, 55, yellow);
            DrawTextEx(daysone, "L", (Vector2){384, 265}, 70, 2, yellow);
            DrawTextEx(daysone, "P", (Vector2){384, 395}, 70, 2, BLACK);
            DrawTextEx(daysone, "/crypto", (Vector2){520, 325}, 95, 6, BLACK);
            DrawTextEx(daystwo, "The safest, the easier, the smartest choice.", (Vector2){290, 560}, 55, 2, BLACK);

        if(CheckCollisionPointRec(GetMousePosition(), loginbotao))
        {
            DrawRectangleRec(loginbotao, WHITE);        
        DrawRoundedRectangle(699, 699, 202, 52, 20, WHITE);
        DrawRoundedRectangle(700, 700, 200, 50, 20, darkyellow);
              
            DrawTextEx(fontTtf, "Login", (Vector2){773, 712}, fontTtf.baseSize, 2, BLACK);
        }

        }
        else if(currentScreen == MENULOGAR){
        ClearBackground(WHITE);    
        DrawFadeRect(0, 0, 1100, 900, darkyellow);
        {   // lp sign
        DrawLPSign(1200, 200, 50, 50, 25);
            DrawTextEx(daysone, "L", (Vector2){1189, 178}, 40, 2, yellow);
            DrawTextEx(daysone, "P", (Vector2){1189, 255}, 40, 2, BLACK);
            DrawTextEx(daysone, "/crypto", (Vector2){1260, 207}, 65, 6, BLACK);
        }

        {  
            {   // pagina de login design
                DrawRectangle(30, 800, 30, 200, darkgreen);
                DrawRectangle(80, 750, 30, 100, darkgreen);
                DrawRectangle(130, 720, 30, 80, darkgreen);   
                DrawRectangle(180, 725, 30, 90, RED);
                DrawRectangle(230, 700, 30, 130, darkgreen);
                DrawRectangle(280, 660, 30, 40, darkgreen);
                DrawRectangle(330, 660, 30, 80, RED);
                DrawRectangle(380, 700, 30, 40, darkgreen);
                DrawRectangle(430, 620, 30, 80, darkgreen);
                DrawRectangle(480, 550, 30, 70, darkgreen);
                DrawRectangle(530, 510, 30, 40, darkgreen);
                DrawRectangle(580, 510, 30, 80, RED);
                DrawRectangle(630, 590, 30, 20, RED);
                DrawRectangle(680, 540, 30, 70, darkgreen);
                DrawRectangle(730, 490, 30, 50, darkgreen);


                DrawLineEx((Vector2){600, 490}, (Vector2){625, 490}, 3.5f, BLACK);
                DrawLineEx((Vector2){650, 490}, (Vector2){675, 490}, 3.5f, BLACK);
                DrawLineEx((Vector2){700, 490}, (Vector2){725, 490}, 3.5f, BLACK);                
                DrawLineEx((Vector2){750, 490}, (Vector2){775, 490}, 3.5f, BLACK);
                DrawLineEx((Vector2){800, 490}, (Vector2){825, 490}, 3.5f, BLACK);
                DrawLineEx((Vector2){850, 490}, (Vector2){875, 490}, 3.5f, BLACK);
                DrawLineEx((Vector2){900, 490}, (Vector2){925, 490}, 3.5f, BLACK);
                DrawLineEx((Vector2){950, 490}, (Vector2){975, 490}, 3.5f, BLACK);
                DrawLineEx((Vector2){1000, 490}, (Vector2){1025, 490}, 3.5f, BLACK);
                DrawLineEx((Vector2){1050, 490}, (Vector2){1075, 490}, 3.5f, BLACK);

                DrawLineEx((Vector2){600, 610}, (Vector2){625, 610}, 3.5f, BLACK);
                DrawLineEx((Vector2){650, 610}, (Vector2){675, 610}, 3.5f, BLACK);
                DrawLineEx((Vector2){700, 610}, (Vector2){725, 610}, 3.5f, BLACK);                
                DrawLineEx((Vector2){750, 610}, (Vector2){775, 610}, 3.5f, BLACK);
                DrawLineEx((Vector2){800, 610}, (Vector2){825, 610}, 3.5f, BLACK);
                DrawLineEx((Vector2){850, 610}, (Vector2){875, 610}, 3.5f, BLACK);
                DrawLineEx((Vector2){900, 610}, (Vector2){925, 610}, 3.5f, BLACK);
                DrawLineEx((Vector2){950, 610}, (Vector2){975, 610}, 3.5f, BLACK);
                DrawLineEx((Vector2){1000, 610}, (Vector2){1025, 610}, 3.5f, BLACK);
                DrawLineEx((Vector2){1050, 610}, (Vector2){1075, 610}, 3.5f, BLACK);

                 
                DrawLineEx((Vector2){1040, 500}, (Vector2){1040, 600}, 3.5f, lightgreen);
                DrawLineEx((Vector2){1030, 510}, (Vector2){1040, 500}, 3.5f, lightgreen);
                DrawLineEx((Vector2){1050, 510}, (Vector2){1040, 500}, 3.5f, lightgreen);

                //DrawTextEx(daysthree, "Positive growth rate.", (Vector2){600, 620}, 20, 1, BLACK);

                /*
                DrawLineEx((Vector2){0, 900}, (Vector2){540, 550}, 7.0f, BLACK);
                //DrawLineEx((Vector2){520, 535}, (Vector2){550, 530}, 7.0f, BLACK);
                DrawLineEx((Vector2){530, 535}, (Vector2){548,560}, 7.0f, BLACK);
                DrawLineEx((Vector2){530, 537}, (Vector2){558,535}, 7.0f, BLACK);
                DrawLineEx((Vector2){545,560}, (Vector2){558,532}, 7.0f, BLACK);
                DrawRectangle(533, 535, 19, 16, BLACK);
                */
                DrawTextEx(daystwo, "Where your money grow.", (Vector2){100, 100}, 55, 1, BLACK);
                DrawTextEx(daystwo, "Where your money is safe.", (Vector2){100, 150}, 55, 1, BLACK);
                DrawTextEx(daystwo, "Where you are sure about your choice.", (Vector2){100, 200}, 55, 1, BLACK);
                DrawLineEx((Vector2){60, 60}, (Vector2){60, 260}, 6.0f, BLACK);

            }
 //login boxes
            DrawRectangleRec(caixatexto1, WHITE);

            DrawRoundedRectangle(1249, 459, 202, 52, 20, BLACK);
            DrawRoundedRectangle(1250, 460, 200, 50, 20, RAYWHITE);

            DrawRoundedRectangle(1249, 529, 202, 52, 20, BLACK);
            DrawRoundedRectangle(1250, 530, 200, 50, 20, RAYWHITE);
            
            DrawTextEx(dance, "Email/Password:", (Vector2){1250, 435}, 15, 1, BLACK);
            DrawTextEx(dance, "Email", (Vector2){1269, 480}, 15, 1, GRAY);
            DrawTextEx(dance, "Password", (Vector2){1269, 550}, 15, 1, GRAY);

            DrawRectangleRec(registrobotao, WHITE);    
            DrawTextEx(dance, "Criar conta", (Vector2){1297, 600}, 15, 1, GRAY);

            DrawRoundedRectangle(1350, 700, 100, 50, 20, yellow);
            DrawTextEx(fontTtf, "Ir", (Vector2){1395, 712}, fontTtf.baseSize, 2, BLACK);

        if(CheckCollisionPointRec(GetMousePosition(), registrobotao))
        {
            DrawTextEx(dance, "Criar conta", (Vector2){1297, 600}, 15, 1, yellow);

        }


    if (CheckCollisionPointRec(GetMousePosition(), caixatexto1)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText) {
            int key = GetKeyPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS - 1)) {
                    inputText[letterCount] = (char)key;
                    inputText[letterCount + 1] = '\0';
                    letterCount++;
                }
                key = GetKeyPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE)) {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                inputText[letterCount] = '\0';
            }
        }

        if(letterCount >= 1){
            DrawRoundedRectangle(1250, 460, 200, 50, 20, RAYWHITE);
        }

        DrawTextEx(dance1, inputText, (Vector2){ caixatexto1.x + 5, caixatexto1.y + 18 }, 13, 1, BLACK);


        if (mouseOnText) {
        if (((framesCounter / 20) % 2) == 0) DrawText("_", caixatexto1.x + 8 + MeasureText(inputText, 20), caixatexto1.y + 12, 20, BLACK);
            framesCounter++;
        } else framesCounter = 0;        
        // ===========================================================

            if (CheckCollisionPointRec(GetMousePosition(), caixatexto2)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText) {
            int key = GetKeyPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && (letterCount2 < MAX_INPUT_CHARS - 1)) {
                    inputText2[letterCount2] = (char)key;
                    inputText2[letterCount2 + 1] = '\0';
                    letterCount2++;
                }
                key = GetKeyPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE)) {
                letterCount2--;
                if (letterCount2 < 0) letterCount2 = 0;
                inputText2[letterCount2] = '\0';
            }
        }

        if(letterCount2 != 0){
            DrawRoundedRectangle(1250, 530, 200, 50, 20, RAYWHITE);
        }


        a = strlen(inputText2) - 1;

        for(i=0; i <= a; i++)
        {
            input1[i] = '*';
        DrawTextEx(daysone, input1, (Vector2){ caixatexto2.x + 5, caixatexto2.y + 18 }, 18, 1, BLACK);

        }

            if (IsKeyPressed(KEY_BACKSPACE) && (strlen(input1) > 0)) {
                input1[strlen(input1) - 1] = '\0';
            }


        if (mouseOnText) {
        if (((framesCounter2 / 20) % 2) == 0) DrawText("_", caixatexto2.x + 8 + MeasureText(inputText, 20), caixatexto2.y + 12, 20, BLACK);
            framesCounter2++;
        } else framesCounter2 = 0;


        }
        }
        {
            if (CheckCollisionPointRec(GetMousePosition(), loginbotao) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentScreen = MENULOGAR;
            }
        }

// para lembrar: drawrectangle(posxdocantosupesquerd,posydeletmb, largura, altura, raio das borda redonda)

        if(CheckCollisionPointRec(GetMousePosition(), registrobotao) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            currentScreen = REGISTRO;

            ClearBackground(WHITE);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

