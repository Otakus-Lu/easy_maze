#include"add.h"
#include"global_variable.h"
using namespace std;
int flag;
IMAGE img_all[7];
DWORD nTimeOut = 5000;//�ӳ�baiʱ��
int sizelen = 0;
struct maze maze;
struct Randomly_generated_maze randommaze[2500];
struct maze_stack stack[1000];
struct maze_stack path[1000];
int top = -1;     //ջ��    
int minlen = 999999;  //��С·����
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
        printf("�Թ�����˵����\nwasd���������ƶ�\nʹ���Ҳఴťʱ�Ȱ���x\n");
        cout << "��ѡ��ؿ����������֣�" << endl;
        while (!(cin >> guanka)) {
            windows("�������ݵ����ʹ���");
            cin.clear();//��������ǣ����´������������������������ɱ�����֮ǰ�Ĳ�ƥ�������/*cin.sync();*///���cin�����������ݡ�
            while (cin.get() != '\n') {
                continue;
            }
            cout << "���ٴ�����" << endl;
        }
        sprintf(nm, "%d.txt", guanka);
        ifstream read(nm);
        if (!read)
        {
            cout << "���ļ������ڣ�����Ϊ�㴴������Թ�(loading.....)" << endl;
            cout << "����������������" << endl;
            //�����޲�С��13�ĵ�����������������39������������73��
            int row1, column1;
            int flag2 = 0;
            while (flag2 != 1) {
                if (!(cin >> row1 >> column1)) {
                    windows("�������ݵ����ʹ���");
                    cin.clear();                           //��������ǣ����´������������������������ɱ�����֮ǰ�Ĳ�ƥ�������,���cin�����������ݡ�
                    while (cin.get() != '\n') {
                        continue;
                    }
                    cout << "���ٴ�����" << endl;
                }
                //else if (row1 % 2 != 1 || column1 % 2 != 1 || row1 < 13 || column1 < 5 || row1>39 || column1>73) {
                //    windows("�������ݲ��ڷ�Χ��");
                //    cin.clear();                       //��������ǣ����´������������������������ɱ�����֮ǰ�Ĳ�ƥ�������,���cin�����������ݡ�
                //    while (cin.get() != '\n') {
                //        continue;
                //    }
                //    cout << "���ٴ�����" << endl;
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