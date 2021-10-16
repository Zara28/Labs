#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "stdio.h"
#define WIN32_LEAN_AND_MEAN            
#include <stdlib.h>  
#include "framework.h"

#include "game_lect_5.h"

void pic(HDC hdc)
{
    HBRUSH hBrush;
    HPEN hPen;

    //train

    hPen = CreatePen(PS_SOLID, 2, RGB(90, 47, 60));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 500, 500, NULL);
    LineTo(hdc, 890, 500);
    MoveToEx(hdc, 500, 520, NULL);
    LineTo(hdc, 890, 520);

    hBrush = CreateSolidBrush(RGB(226, 174, 97));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 600, 420, 720, 480);
    Rectangle(hdc, 640, 390, 720, 420);
    Rectangle(hdc, 730, 390, 800, 480);
    Rectangle(hdc, 810, 390, 890, 480);

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 610, 470, 640, 500);
    Ellipse(hdc, 680, 470, 710, 500);

    Ellipse(hdc, 730, 470, 760, 500);
    Ellipse(hdc, 765, 470, 795, 500);

    Ellipse(hdc, 815, 470, 845, 500);
    Ellipse(hdc, 860, 470, 890, 500);


    hBrush = CreateSolidBrush(RGB(0, 255, 255));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 650, 400, 710, 410);
    Rectangle(hdc, 740, 400, 770, 410);
    Rectangle(hdc, 780, 400, 800, 410);
    Rectangle(hdc, 815, 400, 830, 410);
    Rectangle(hdc, 840, 400, 890, 410);
    //HOUSE

    //крыша

    hPen = CreatePen(PS_ENDCAP_MASK, 3, RGB(163, 22, 68));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);
    RECT rect{ 150, 350, 400, 525 };
    hBrush = CreateSolidBrush(RGB(167, 36, 18));
    LineTo(hdc, 150, 350);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 400, 525);
    LineTo(hdc, 400, 350);
    FillRect(hdc, &rect, hBrush);
    DeleteObject(hPen);

    hPen = CreatePen(PS_ENDCAP_MASK, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    DeleteObject(&rect);
    //окно
    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(1, 0, 250));
    SelectObject(hdc, hBrush);

    RECT rect2{ 225, 400, 325, 475 };
    FillRect(hdc, &rect2, hBrush);
    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 225, 400);


    MoveToEx(hdc, 275, 400, NULL);
    LineTo(hdc, 275, 475);
    MoveToEx(hdc, 275, 425, NULL);
    LineTo(hdc, 325, 425);
    DeleteObject(&rect2);



    hPen = CreatePen(PS_DASH, 4, RGB(0, 128, 0));

    SelectObject(hdc, hPen);
    //green tree
    MoveToEx(hdc, 525, 375, NULL);
    LineTo(hdc, 550, 400);
    LineTo(hdc, 500, 400);
    LineTo(hdc, 525, 375);

    MoveToEx(hdc, 525, 400, NULL);
    LineTo(hdc, 575, 450);
    LineTo(hdc, 475, 450);
    LineTo(hdc, 525, 400);

    MoveToEx(hdc, 525, 450, NULL);
    LineTo(hdc, 600, 525);
    LineTo(hdc, 450, 525);
    LineTo(hdc, 525, 450);


    //tree
    DeleteObject(hBrush);

    hPen = CreatePen(PS_SOLID, 18, RGB(225, 128, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 650, 525, NULL);
    LineTo(hdc, 650, 350);

    for (int i = 0; i < 12; i++)
    {
        hBrush = CreateSolidBrush(RGB(0, 255, 0));
        SelectObject(hdc, hBrush);
        hPen = CreatePen(PS_DASH, 5, RGB(0, 255, 0));
        SelectObject(hdc, hPen);
        if (i <= 1)
        {
            Ellipse(hdc, 600 + 30 * i, 300, 650 + 30 * i, 350);
        }
        else if (i > 7)
        {
            Ellipse(hdc, 600 + 30 * (9 - i + 1), 360, 650 + 30 * (9 - i + 1), 410);
        }
        else
        {
            Ellipse(hdc, 600 + 30 * (i / 2 - 1), 330, 650 + 30 * (i / 2 - 1), 380);
        }

    }
    DeleteObject(hPen);
    //sun
    hBrush = CreateHatchBrush(HS_CROSS, RGB(251, 196, 68));
    SelectObject(hdc, hBrush);

    hPen = CreatePen(PS_ALTERNATE, 8, RGB(251, 196, 68));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 50, 50, 150, 150);
    DeleteObject(hBrush);


    //cloud

    hBrush = CreateSolidBrush(RGB(226, 226, 241));
    SelectObject(hdc, hBrush);
    hPen = CreatePen(PS_ALTERNATE, 2, RGB(226, 226, 241));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 200, 150, 300, 200);
    Ellipse(hdc, 270, 155, 350, 210);
    Ellipse(hdc, 350, 60, 480, 200);
    Ellipse(hdc, 210, 75, 512, 190);

}