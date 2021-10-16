#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "stdio.h"
#define WIN32_LEAN_AND_MEAN            
#include <stdlib.h>

#include "framework.h"

void OlympicEmblem(HDC hdc);
void AlarmClock(HDC hdc);
void Cloud(HDC hdc);
void Star1(HDC hdc, int cx, int cy, int size);
void Star2(HDC hdc, int cx, int cy, int size);
void Star3(HDC hdc, int cx, int cy, int size);
void Image1(HDC hdc);
void Image2(HDC hdc);
void my_picture(HDC hdc);
void ship(int x, int y, HDC hdc);
void Lab7(HDC hdc, int numPicture);