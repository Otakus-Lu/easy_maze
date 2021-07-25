#include "global_variable.h"
void TimeThread(void* pArguments)
{
    Sleep(nTimeOut);
    flag = 1;
}
int mazefind(int i, int j)  //递归寻路
{
    _beginthread(TimeThread, 0, NULL);
    int find = 0;
    maze.a[i][j] = '9'; //走过的标记成9
    top++;      //结点进栈
    stack[top].i = i;
    stack[top].j = j;
    if (i == maze.row - 2 && j == maze.column - 2) //到了终点flag为1，未到仍为0
    {
        lujing = 1;
        printf("路径%d: ", countlen);
        countlen++;
        for (int k = 0; k <= top; k++) {
            printf("(%d,%d)  ", stack[k].i, stack[k].j);
            if ((k + 1) % 5 == 0)      //输出时每5个结点换一行
            {
                printf("\n\t");
            }
            if (top + 1 < minlen) {       //比较输出最短路径
                for (int k = 0; k <= top; k++)
                    path[k] = stack[k];
                minlen = top + 1;
            }
        }
        printf("\n");
        if (top == -2) { flag = 1; }  //栈为空，无法继续返回
    }
    if (flag != 1) {
        if (maze.a[i][j + 1] == '0') //往右
        {
            stack[top].di = 0; mazefind(i, j + 1);
        }
        if (maze.a[i + 1][j] == '0') //往下
        {
            stack[top].di = 1; mazefind(i + 1, j);
        }
        if (maze.a[i][j - 1] == '0') //往左
        {
            stack[top].di = 2; mazefind(i, j - 1);
        }
        if (maze.a[i - 1][j] == '0') //往上
        {
            stack[top].di = 3; mazefind(i - 1, j);
        }
        maze.a[i][j] = '0'; //如果四个方向都走过了，空出该点，返回上一个点
        top--;
    }
    return flag;
}