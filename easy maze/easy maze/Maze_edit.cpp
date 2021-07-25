#include"add.h"
#include"global_variable.h"
void mouse_click(char nm[20], int a, int b) {
    int x, y;
    fillrectangle(20 * maze.column, 200, 20 * maze.column + 80, 250);
    outtextxy(20 * maze.column + 7, 220, "ÍË³ö±à¼­");
    while (1) {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN) {
            x = msg.x / 20;
            y = msg.y / 20;
            if (msg.x <= maze.column * 20) {

                if (maze.a[y][x] == '1') {
                    maze.a[y][x] = '0';
                }
                else if (maze.a[y][x] == '0') {
                    maze.a[y][x] = '1';
                }
            }
            else if (msg.x > maze.column * 20 && msg.y <= 150 && msg.y > 100) {
                preserve(nm);
                printmaze2(a, b);
            }
            else if (msg.x > maze.column * 20 && msg.y <= 250 && msg.y > 200) {
                inquiry(nm);
                solidrectangle(20 * maze.column, 200, 20 * maze.column + 80, 250);
                printmaze2(a, b);
                break;
            }
        }
        printmaze1();
    }
}
void maze_modify(char nm[20], int a, int b) {
    mouse_click(nm, a, b);
}