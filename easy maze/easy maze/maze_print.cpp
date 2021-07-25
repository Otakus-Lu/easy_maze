#include "global_variable.h"
using namespace std;
void loadImg() {
    char picture[20];
    for (int i = 0; i < 7; i++) {
        sprintf(picture, "./images/%d.jpg", i);
        loadimage(img_all + i, picture, 20, 20);
        putimage(i * 20, 0, img_all + i);
    }
}
void button() {
    setlinecolor(BLACK);
    setfillcolor(WHITE);
    settextcolor(BLACK);
    settextstyle(0, 8, "楷体");
    fillrectangle(20 * maze.column, 0, 20 * maze.column + 80, 50);
    fillrectangle(20 * maze.column, 50, 20 * maze.column + 80, 100);
    fillrectangle(20 * maze.column, 100, 20 * maze.column + 80, 150);
    fillrectangle(20 * maze.column, 150, 20 * maze.column + 80, 200);
    outtextxy(20 * maze.column + 7, 20, "编辑迷宫");
    outtextxy(20 * maze.column + 7, 70, "自动寻路");
    outtextxy(20 * maze.column + 7, 120, "保存迷宫");
    outtextxy(20 * maze.column + 7, 170, "退出游戏");
}
void Set() {
    HANDLE hOut;
    COORD pos = { 0,0 };
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}
void printmaze() {
    int x, y;
    for (int i = 0; i < maze.row; i++) {
        for (int j = 0; j < maze.column; j++) {
            x = j * 20;
            y = i * 20;
            if (maze.a[i][j] == '0') { putimage(x, y, img_all); continue; }
            else if (maze.a[i][j] == '1') { putimage(x, y, img_all + 1); continue; }
            else if (maze.a[i][j] == '7') { cout << "○"; continue; }
            else if (maze.a[i][j] == '8') { cout << "●"; continue; }
            else if (maze.a[i][j] == '3') { putimage(x, y, img_all + 2); continue; }		//向右走
            else if (maze.a[i][j] == '4') { putimage(x, y, img_all + 3); continue; }
            else if (maze.a[i][j] == '5') { putimage(x, y, img_all + 4); continue; }
            else if (maze.a[i][j] == '6') { putimage(x, y, img_all + 5); continue; }
            if (maze.a[i][j] == '*') { putimage(x, y, img_all + 6); continue; }
        }
        cout << endl;
    }
    button();
}
void printmaze1() {
    Set();
    printmaze();
}
void printmaze2(int x, int y) {
    system("cls");
    maze.a[x][y] = '*';
    printmaze();
}
void printmaze3(int x, int y, char z) {
    system("cls");
    maze.a[x][y] = z;
    printmaze();

}