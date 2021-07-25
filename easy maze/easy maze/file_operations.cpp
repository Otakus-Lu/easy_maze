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
    ofstream write(nm);     //创建一个%d.txt的文件
    write << maze.row << " " << maze.column << endl;	//将变量的值写入文件
    for (int i = 0; i < maze.row; i++) {
        write << maze.a[i] << endl;
    }
    write.close();                //关闭文件
    windows("保存成功");
    system("cls");
    cout << "文件已保存到" << nm << endl;
}