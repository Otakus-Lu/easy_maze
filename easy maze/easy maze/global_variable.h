#pragma once
#include<iostream>
#include<cstdio>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include <ctime>
#include <process.h>
#include<graphics.h>
extern int flag;
extern IMAGE img_all[7];
extern DWORD nTimeOut;//�ӳ�baiʱ��
struct maze
{
    int row;
    int column;
    char a[100][100];
};
extern struct maze maze;
extern int sizelen;
struct Randomly_generated_maze {
    int x;
    int y;
};
extern struct Randomly_generated_maze randommaze[];
struct maze_stack {
    int i;      //·��������
    int j;      //·��������
    int di;     //����
};
extern struct maze_stack path[];
extern struct maze_stack stack[];
extern int top;     //ջ��    
extern int minlen;  //��С·����
extern int countlen;
extern int lujing;
