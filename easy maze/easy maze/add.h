#pragma once
#include<iostream>
#include<cstdio>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include <ctime>
#include <process.h>
#include<graphics.h>
void block_find(int, int, int, int);
void block_create(int, int);
void block_choose(int,int);
void createmaze(int, int);
int mazefind(int, int);
void printmaze();
void printmaze1();
void printmaze2(int, int);
void printmaze3(int, int, char);
void Set();
void loadImg();
void preserve(char[]);
void windows(const char[]);
void inquiry(char[]);
void inquiry();
void mouse_click(char[], int, int);
void maze_modify(char[], int, int);
void manual_control(char[]);