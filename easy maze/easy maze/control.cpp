#include"global_variable.h"
#include"add.h"
using namespace std;
void manual_control(char nm[]) {
    int x = 1, y = 1;
    char input;
    while (1) {
        input = getch();
        if (input == 's')
        {
            if (maze.a[x + 1][y] == '0') {
                maze.a[x][y] = '0';
                x++;
                maze.a[x][y] = '*';
            }
        }
        else if (input == 'w')
        {
            if (maze.a[x - 1][y] == '0') {
                maze.a[x][y] = '0';
                x--;
                maze.a[x][y] = '*';
            }
        }
        else if (input == 'a')
        {
            if (maze.a[x][y - 1] == '0') {
                maze.a[x][y] = '0';
                y--;
                maze.a[x][y] = '*';
            }
        }
        else if (input == 'd')
        {
            if (maze.a[x][y + 1] == '0') {
                maze.a[x][y] = '0';
                y++;
                maze.a[x][y] = '*';
            }
        }
        else if (input == 'x') {
            while (1) {
                if (MouseHit()) {
                    MOUSEMSG msg = GetMouseMsg();
                    if (msg.uMsg == WM_LBUTTONDOWN) {
                        cout << msg.x << msg.y << endl;
                        if (msg.x > maze.column * 20) {
                            if (msg.y > 0 && msg.y <= 50) {
                                maze_modify(nm, x, y);
                                break;
                            }
                            else if (msg.y > 50 && msg.y <= 100) {
                                system("cls");
                                mazefind(x, y);
                                if (lujing == 1) {
                                    printf("最短路径如下:\n");
                                    printf("长度:  %d\n", minlen);
                                    printf("路径:  ");
                                    for (int k = 0; k < minlen; k++) {
                                        printf("(%d,%d)  ", path[k].i, path[k].j);
                                        maze.a[path[k].i][path[k].j] = (char)('3' + path[k].di);
                                        if ((k + 1) % 5 == 0)
                                            printf("\n");
                                    }
                                    printf("\n");
                                    printmaze();
                                    windows("你现在可查看路径");

                                }
                                else printf("未找到路径\n");
                                x = maze.row - 2; y = maze.column - 2;
                                break;
                            }
                            else if (msg.y > 100 && msg.y <= 150) {
                                preserve(nm);
                                printmaze2(x, y);
                                break;
                            }
                            else if (msg.y > 150 && msg.y <= 200) {
                                exit(0);
                            }
                        }
                    }
                }
            }
        }
        printmaze();
        if (x == maze.row - 2 && y == maze.column - 2) {
            windows("恭喜你到达终点");
            break;
        }
    }
}
