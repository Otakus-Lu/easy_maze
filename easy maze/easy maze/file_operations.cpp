#include"global_variable.h"
#include"add.h"
using namespace std;
void preserve(char nm[20]) {
    for (int i = 0; i < maze.row; i++) {
        for (int j = 0; j < maze.column; j++) {
            if (maze.a[i][j] != '0' && maze.a[i][j] != '1') {
                maze.a[i][j] = '0';
            }
        }
    }
    ofstream write(nm);     //����һ��%d.txt���ļ�
    write << maze.row << " " << maze.column << endl;	//��������ֵд���ļ�
    for (int i = 0; i < maze.row; i++) {
        write << maze.a[i] << endl;
    }
    write.close();                //�ر��ļ�
    windows("����ɹ�");
    system("cls");
    cout << "�ļ��ѱ��浽" << nm << endl;
}