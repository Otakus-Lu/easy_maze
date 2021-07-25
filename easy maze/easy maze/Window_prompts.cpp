#include"global_variable.h"
#include"add.h"
void windows(const char nm[20]) {
    HWND save = GetHWnd();
    SetWindowText(save, "迷宫");
    MessageBox(save, nm, "提示", MB_OK);
}
void inquiry(char nm[20]) {
    HWND save = GetHWnd();
    SetWindowText(save, "迷宫");
    int isok = MessageBox(save, "是否保存该迷宫", "提示", MB_OKCANCEL);
    if (isok == IDOK) {
        preserve(nm);
    }
}
void inquiry() {
    HWND play = GetHWnd();
    SetWindowText(play, "迷宫");
    int isok = MessageBox(play, "是否继续游玩", "提示", MB_OKCANCEL);
    if (IDCANCEL == isok) {
        exit(0);
    }
}