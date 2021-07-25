#include<iostream>
#include"global_variable.h"
using namespace std;

void block_find(int x, int y, int row2, int column2) {               //�ҵ���ѡ���ӣ���������
    if (x + 2 <= row2 && maze.a[x + 2][y] == '1') {                    //��
        randommaze[sizelen].x = x + 2; randommaze[sizelen].y = y;
        maze.a[x + 2][y] = '0';
        sizelen++;
    }
    if (y + 2 <= column2 && maze.a[x][y + 2] == '1') {                   //��
        randommaze[sizelen].x = x; randommaze[sizelen].y = y + 2;
        maze.a[x][y + 2] = '0';
        sizelen++;
    }
    if (x - 2 >= 1 && maze.a[x - 2][y] == '1') {                    //��
        randommaze[sizelen].x = x - 2; randommaze[sizelen].y = y;
        maze.a[x - 2][y] = '0';
        sizelen++;
    }
    if (y - 2 >= 1 && maze.a[x][y - 2] == '1') {                   //��
        randommaze[sizelen].x = x; randommaze[sizelen].y = y - 2;
        maze.a[x][y - 2] = '0';
        sizelen++;
    }
}
void block_create(int x, int y) {                          //��ѡ��һ����ѡ���Ӻ󣬿���·��
    int flag2 = 0;
    int di;
    while (flag2 != 1) {
        di = rand() % 4;
        switch (di) {
        case 0:if (maze.a[x - 2][y] == '2' && maze.a[x - 1][y] == '1') {             //�������ѷ��ʸ�����δ����ͨ
            maze.a[x - 1][y] = '0'; flag2 = 1; break;
        };
        case 1:if (maze.a[x][y + 2] == '2' && maze.a[x][y + 1] == '1') {             //�ұ����ѷ��ʸ�����δ����ͨ
            maze.a[x][y + 1] = '0'; flag2 = 1; break;
        };
        case 2:if (maze.a[x + 2][y] == '2' && maze.a[x + 1][y] == '1') {             //�������ѷ��ʸ�����δ����ͨ
            maze.a[x + 1][y] = '0'; flag2 = 1; break;
        };
        case 3:if (maze.a[x][y - 2] == '2' && maze.a[x][y - 1] == '1') {             //������ѷ��ʸ�����δ����ͨ
            maze.a[x][y - 1] = '0'; flag2 = 1;
        };
        }
    }
}
void block_choose(int row2, int column2) {
    int choose = rand() % sizelen;
    block_create(randommaze[choose].x, randommaze[choose].y);              //����·��
    block_find(randommaze[choose].x, randommaze[choose].y, row2, column2); //����Χ�ĺ�ѡ����
    maze.a[randommaze[choose].x][randommaze[choose].y] = '2';                   //����ѷ���
    for (int i = choose; i < sizelen; i++) {                               //��������ɾȥ�ø���
        randommaze[i] = randommaze[i + 1];
    }
    sizelen--;
}
void createmaze(int row, int column) {
    int sum = ((row - 2) * (column - 2) - 1) / 2 - 2;
    int row2 = row - 1;
    int column2 = column - 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            maze.a[i][j] = '1';
        }
    }
    randommaze[sizelen].x = 1; randommaze[sizelen].y = 1;
    maze.a[1][1] = '2';
    block_find(1, 1, row2, column2);
    while (sizelen != 0) {
        block_choose(row2, column2);
    }
    for (int i = 0; i < maze.row; i++) {
        for (int j = 0; j < maze.column; j++) {
            if (maze.a[i][j] == '2') { maze.a[i][j] = '0'; }
        }
    }
}