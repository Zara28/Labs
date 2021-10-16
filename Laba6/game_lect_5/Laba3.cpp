#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "stdio.h"
#define WIN32_LEAN_AND_MEAN            
#include <stdlib.h>  
#include "framework.h"

#include "game_lect_5.h"
//#include"Laba3.h"


void StClausAuto(HDC hdc, int x, int y)
{
    //hight
    MoveToEx(hdc, 20 + x, 0 + y, NULL);
    LineTo(hdc, 30 + x, 20 + y);
    LineTo(hdc, 10 + x, 20 + y);
    LineTo(hdc, 20 + x, 0 + y);

    //middle
    MoveToEx(hdc, 20 + x, 10 + y, NULL);
    LineTo(hdc, 30 + x, 40 + y);
    LineTo(hdc, 10 + x, 40 + y);
    LineTo(hdc, 20 + x, 10 + y);

    //bottom
    MoveToEx(hdc, 20 + x, 30 + y, NULL);
    LineTo(hdc, 40 + x, 80 + y);
    LineTo(hdc, 0 + x, 80 + y);
    LineTo(hdc, 20 + x, 30 + y);
}

void Snowman(HDC hdc, int x, int y) {
    Ellipse(hdc, 20 + x, 0 + y, 40 + x, 20 + y);
    Ellipse(hdc, 10 + x, 20 + y, 50 + x, 60 + y);
    Ellipse(hdc, 0 + x, 60 + y, 60 + x, 120 + y);

    MoveToEx(hdc, 15 + x, 30 + y, NULL);
    LineTo(hdc, 0 + x, 40 + y);

    MoveToEx(hdc, 45 + x, 30 + y, NULL);
    LineTo(hdc, 60 + x, 40 + y);

    MoveToEx(hdc, 70 + x, 0 + y, NULL);
    LineTo(hdc, 40 + x, 120 + y);

    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 60 + x, 0 + y);

    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 75 + x, 0 + y);


}

void Logo(HDC hdc, int x, int y)
{
    HPEN hPen;
    hPen = CreatePen(PS_COSMETIC, 4, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x + 25, y + 25, NULL);
    Ellipse(hdc, x + 25, y + 25, x + 150, y + 100);

    Ellipse(hdc, x + 30, y + 30, x + 145, y + 65);
    Ellipse(hdc, x + 65, y + 25, x + 110, y + 100);

}