#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "stdio.h"
#define WIN32_LEAN_AND_MEAN            
#include <stdlib.h>  
#include "framework.h"

#include "game_lect_5.h"

//#include"Laba2.h"
void cicle(HDC hdc)
{
    // picture 1
    int x1 = 10, y1 = 40;
    int x2 = 50, y2 = 40;
    int i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        y1 -= 5;
        y2 += 10;
        i++;
    } while (i < 9);

    //picture 2
    x1 = 100, y1 = 10;
    x2 = 100, y2 = 100;
    i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        y1 += 5;
        y2 -= 5;

        x1 -= 5;
        x2 += 5;
        i++;
    } while (i < 9);

    //picture 3
    x1 = 150, y1 = 70;
    x2 = 210, y2 = 70;
    i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        y1 -= 5;

        x2 -= 5;
        i++;
    } while (i < 13);

    //picture 4
    x1 = 280, y1 = 10;
    x2 = 280, y2 = 100;
    i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 -= 5;
        y1 += 5;

        y2 -= 5;
        i++;
    } while (i < 13);

    //picture 5
    x1 = 450, y1 = 10;
    x2 = 320, y2 = 100;
    i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        y1 += 10;

        x2 += 10;
        i++;
    } while (i < 10);


    //picture 6
    x1 = 520, y1 = 10;
    x2 = 520, y2 = 100;
    i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        x2 -= 5;
        i++;
    } while (i < 13);

    //picture 7
    x1 += 10;
    x2 = x1;
    i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;

        y2 -= 5;
        i++;
    } while (i < 13);

    //picture 8
    x1 += 10;
    x2 = x1;
    y1 = 80, y2 = 100;
    i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 -= 5;

        x2 += 5;
        y2 += 5;
        i++;
    } while (i < 13);

    //picture 9
    x1 += 20;
    x2 = x1;
    y1 = 65, y2 = 90;
    i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 += 5;

        x2 += 5;
        y2 -= 5;
        i++;
    } while (i < 13);

    //picture 10
    x1 = 50, x2 = 130;
    y1 += 100, y2 = y1 + 150;
    i = 0;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 += 5;

        x2 += 5;
        y2 -= 10;
        i++;
    } while (i < 25);



}