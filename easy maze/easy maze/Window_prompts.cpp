#include"global_variable.h"
#include"add.h"
void windows(const char nm[20]) {
    HWND save = GetHWnd();
    SetWindowText(save, "�Թ�");
    MessageBox(save, nm, "��ʾ", MB_OK);
}
void inquiry(char nm[20]) {
    HWND save = GetHWnd();
    SetWindowText(save, "�Թ�");
    int isok = MessageBox(save, "�Ƿ񱣴���Թ�", "��ʾ", MB_OKCANCEL);
    if (isok == IDOK) {
        preserve(nm);
    }
}
void inquiry() {
    HWND play = GetHWnd();
    SetWindowText(play, "�Թ�");
    int isok = MessageBox(play, "�Ƿ��������", "��ʾ", MB_OKCANCEL);
    if (IDCANCEL == isok) {
        exit(0);
    }
}