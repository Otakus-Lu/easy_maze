#include "global_variable.h"
void TimeThread(void* pArguments)
{
    Sleep(nTimeOut);
    flag = 1;
}
int mazefind(int i, int j)  //�ݹ�Ѱ·
{
    _beginthread(TimeThread, 0, NULL);
    int find = 0;
    maze.a[i][j] = '9'; //�߹��ı�ǳ�9
    top++;      //����ջ
    stack[top].i = i;
    stack[top].j = j;
    if (i == maze.row - 2 && j == maze.column - 2) //�����յ�flagΪ1��δ����Ϊ0
    {
        lujing = 1;
        printf("·��%d: ", countlen);
        countlen++;
        for (int k = 0; k <= top; k++) {
            printf("(%d,%d)  ", stack[k].i, stack[k].j);
            if ((k + 1) % 5 == 0)      //���ʱÿ5����㻻һ��
            {
                printf("\n\t");
            }
            if (top + 1 < minlen) {       //�Ƚ�������·��
                for (int k = 0; k <= top; k++)
                    path[k] = stack[k];
                minlen = top + 1;
            }
        }
        printf("\n");
        if (top == -2) { flag = 1; }  //ջΪ�գ��޷���������
    }
    if (flag != 1) {
        if (maze.a[i][j + 1] == '0') //����
        {
            stack[top].di = 0; mazefind(i, j + 1);
        }
        if (maze.a[i + 1][j] == '0') //����
        {
            stack[top].di = 1; mazefind(i + 1, j);
        }
        if (maze.a[i][j - 1] == '0') //����
        {
            stack[top].di = 2; mazefind(i, j - 1);
        }
        if (maze.a[i - 1][j] == '0') //����
        {
            stack[top].di = 3; mazefind(i - 1, j);
        }
        maze.a[i][j] = '0'; //����ĸ������߹��ˣ��ճ��õ㣬������һ����
        top--;
    }
    return flag;
}