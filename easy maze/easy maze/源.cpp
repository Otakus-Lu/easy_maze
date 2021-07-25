#include"add.h"
#include"global_variable.h"
using namespace std;
int flag;
IMAGE img_all[7];
DWORD nTimeOut = 5000;//延迟bai时间
int sizelen = 0;
struct maze maze;
struct Randomly_generated_maze randommaze[2500];
struct maze_stack stack[1000];
struct maze_stack path[1000];
int top = -1;     //栈顶    
int minlen = 999999;  //最小路径数
int countlen = 1;
int lujing = 0;

int main()
{
    while (1) {
        system("cls");
        flag = 0;
        minlen = 999999;
        countlen = 1;
        top = -1;
        //memset(path, 0, sizeof(path));
        loadImg();
        unsigned seed;
        seed = time(0);
        srand(seed);
        int guanka;
        char nm[20];
        printf("迷宫操作说明：\nwasd上左下右移动\n使用右侧按钮时先按下x\n");
        cout << "请选择关卡（仅限数字）" << endl;
        while (!(cin >> guanka)) {
            windows("输入数据的类型错误");
            cin.clear();//清除错误标记，重新打开输入流，但是输入流中依旧保留着之前的不匹配的类型/*cin.sync();*///清楚cin缓存区的数据。
            while (cin.get() != '\n') {
                continue;
            }
            cout << "请再次输入" << endl;
        }
        sprintf(nm, "%d.txt", guanka);
        ifstream read(nm);
        if (!read)
        {
            cout << "该文件不存在，正在为你创建随机迷宫(loading.....)" << endl;
            cout << "请输入行数和列数" << endl;
            //（仅限不小于13的单数，且行数不大于39，列数不大于73）
            int row1, column1;
            int flag2 = 0;
            while (flag2 != 1) {
                if (!(cin >> row1 >> column1)) {
                    windows("输入数据的类型错误");
                    cin.clear();                           //清除错误标记，重新打开输入流，但是输入流中依旧保留着之前的不匹配的类型,清楚cin缓存区的数据。
                    while (cin.get() != '\n') {
                        continue;
                    }
                    cout << "请再次输入" << endl;
                }
                //else if (row1 % 2 != 1 || column1 % 2 != 1 || row1 < 13 || column1 < 5 || row1>39 || column1>73) {
                //    windows("输入数据不在范围内");
                //    cin.clear();                       //清除错误标记，重新打开输入流，但是输入流中依旧保留着之前的不匹配的类型,清楚cin缓存区的数据。
                //    while (cin.get() != '\n') {
                //        continue;
                //    }
                //    cout << "请再次输入" << endl;
                //}
                else flag2 = 1;
            }
            maze.row = row1;
            maze.column = column1;
            createmaze(row1, column1);
        }
        else {
            read >> maze.row >> maze.column;
            for (int i = 0; i < maze.row; i++) {
                read >> maze.a[i];
            }
            read.close();
        }
        initgraph(20 * maze.column + 82, 20 * maze.row, 1);
        setbkcolor(WHITE);
        cleardevice();
        system("cls");
        maze.a[1][1] = '*';
        printmaze1();
        manual_control(nm);
        inquiry(nm);
        inquiry();
        closegraph();
        system("pause");

    }
    return 0;
}