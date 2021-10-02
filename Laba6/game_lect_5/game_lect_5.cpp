// game_lect_5.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "game_lect_5.h"

#include <stdio.h>

#define MAX_LOADSTRING 100


// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

int size = 80;
int number_task = 0;
int goalCx = 300;
int goalCy = 200;
int goalSize = 100;

// Параметры прицела
int aimX = 100;
int aimY = 100;

// Счетчики выстрелов
int hit = 0; // попал
int missed = 0; // промазал

int r = 100;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GAMELECT5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMELECT5));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAMELECT5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GAMELECT5);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//



void RecursiveRectagle(HDC hdc, int cx, int cy, int size) {
    Rectangle(hdc, cx - size, cy - size, cx + size, cy + size);

    if (size < 5) {
        return;
    }

    RecursiveRectagle(hdc, cx - size * 0.45, cy - size * 0.45, size / 2.5);
    RecursiveRectagle(hdc, cx + size * 0.45, cy - size * 0.45, size / 2.5);
    RecursiveRectagle(hdc, cx - size * 0.45, cy + size * 0.45, size / 2.5);
    RecursiveRectagle(hdc, cx + size * 0.45, cy + size * 0.45, size / 2.5);
}

void DrawAim(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(128, 0, 0));
    SelectObject(hdc, hPen);

    Ellipse(hdc, x - 40, y - 40, x + 40, y + 40);
    Ellipse(hdc, x - 30, y - 30, x + 30, y + 30);
    Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);

    MoveToEx(hdc, x - 50, y, NULL);
    LineTo(hdc, x + 50, y);

    MoveToEx(hdc, x, y - 50, NULL);
    LineTo(hdc, x, y + 50);
}

void DrawGoal(HDC hdc, int x, int y, int size) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
    SelectObject(hdc, hPen);

    RecursiveRectagle(hdc, x, y, size);
}

void moveDown() {
    aimY += 10;
}

void moveToLeft() {
    aimX -= 10;
}

void moveUp() {
    aimY -= 10;
}

void moveToRight() {
    aimX += 10;
}


int insideGoal(int x, int y) {
    if (x < goalCx - goalSize)
        return 0;
    if (x > goalCx + goalSize)
        return 0;
    if (y < goalCy - goalSize)
        return 0;
    if (y > goalCy + goalSize)
        return 0;
    return 1;
}

void game(HDC hdc)
    {


            HFONT hFont = CreateFont(20,
                0, 0, 0, 0, 0, 0, 0,
                DEFAULT_CHARSET,
                0, 0, 0, 0,
                L"Courier New"
            );
            SelectObject(hdc, hFont);
            SetTextColor(hdc, RGB(0, 0, 128));

            TCHAR  string1[] = _T("Попал:");
            TextOut(hdc, 10, 10, string1, _tcslen(string1));

            TCHAR  string2[] = _T("Промазал:");
            TextOut(hdc, 400, 10, string2, _tcslen(string2));

            char sHit[5]; // локальная переменная sHit
            TCHAR  tsHit[5];
            sprintf_s(sHit, "%d", hit); // использование глобальной переменной hit
            OemToChar(sHit, tsHit);
            TextOut(hdc, 100, 10, tsHit, _tcslen(tsHit));

            char sMissed[5];
            TCHAR  tsMissed[5];
            sprintf_s(sMissed, "%d", missed);
            OemToChar(sMissed, tsMissed);
            TextOut(hdc, 520, 10, tsMissed, _tcslen(tsMissed));

            DrawGoal(hdc, goalCx, goalCy, goalSize);
            DrawAim(hdc, aimX, aimY);
    }

void Cross(HDC hdc, int cx, int cy, int size, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx - size, cy, NULL);
    LineTo(hdc, cx + size, cy);
    MoveToEx(hdc, cx, cy - size, NULL);
    LineTo(hdc, cx, cy + size);
    DeleteObject(hPen);
}
void RecursiveCross(HDC hdc, int cx, int cy, int size, COLORREF color) {
    Cross(hdc, cx, cy, size, color); // Cross() см лаб раб  11
    if (size < 10) {
        return;
    }
    RecursiveCross(hdc, cx - size, cy, size / 2, color);
    RecursiveCross(hdc, cx, cy - size, size / 2, color);
    RecursiveCross(hdc, cx + size, cy, size / 2, color);
}
void Triangle(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, cx, cy - size, NULL);
    LineTo(hdc, cx + size, cy + size);
    LineTo(hdc, cx - size, cy + size);
    LineTo(hdc, cx, cy - size);

    DeleteObject(hPen);
}
void RecursiveTriangle(HDC hdc, int cx, int cy, int size) {
    Triangle(hdc, cx, cy, size); // Triangle() см лаб раб  11
    if (size < 10) {
        return;
    }
    RecursiveTriangle(hdc, cx, cy - size, size / 2);
    RecursiveTriangle(hdc, cx + size, cy + size, size / 2);
    RecursiveTriangle(hdc, cx - size, cy + size, size / 2);
}
void Circle(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, cx - size, cy - size, cx + size, cy + size);

    DeleteObject(hPen);
}
void RecursiveCircle(HDC hdc, int cx, int cy, int size) {
    Circle(hdc, cx, cy, size); // Circle() см лаб раб  11
    if (size < 10) {
        return;
    }
    RecursiveCircle(hdc, cx, cy - size, size / 2);
    RecursiveCircle(hdc, cx + size, cy, size / 2);
    RecursiveCircle(hdc, cx, cy + size, size / 2);
    RecursiveCircle(hdc, cx - size, cy, size / 2);
}
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

void Image1(HDC hdc, int cx, int cy, int size)
{
    int x1 = cx - size;
    int x2 = cx + size;
    int x3 = cx;
    int y1 = cy - size;
    int y2 = cy - size;
    int y3 = cy + size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage1_1(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_1(hdc, cx - size, cy - size, size / 2);
    RecursiveImage1_1(hdc, cx + size, cy - size, size / 2);
}

void RecursiveImage1_2(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_2(hdc, cx - size, cy - size, size / 2);
    RecursiveImage1_2(hdc, cx, cy + size, size / 2);
}

void RecursiveImage1_3(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_3(hdc, cx - size, cy - size, size / 2);
    RecursiveImage1_3(hdc, cx, cy + size, size / 2);
    RecursiveImage1_3(hdc, cx + size, cy - size, size / 2);
}


void RecursiveImage1_4(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_4(hdc, cx, cy - size, size / 2);

}


void RecursiveImage1_5(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_5(hdc, cx + size, cy, size / 2);
}


void RecursiveImage1_6(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_6(hdc, cx - size, cy, size / 2);
}

void RecursiveImage1_7(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage1_7(hdc, cx, cy - size, size / 2);
    RecursiveImage1_7(hdc, cx + size, cy, size / 2);
    RecursiveImage1_7(hdc, cx - size, cy, size / 2);
}

void Image2(HDC hdc, int cx, int cy, int size)
{
    int x1 = cx - size / 2;
    int x2 = cx + size / 2;
    int x3 = cx - size;
    int x4 = cx + size;

    int y1 = cy - size;
    int y2 = cy - size;
    int y3 = cy + size;
    int y4 = cy + size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage2_1(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    RecursiveImage2_1(hdc, cx - size, cy + size, size / 2);
}

void RecursiveImage2_2(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    RecursiveImage2_2(hdc, cx - size / 2, cy - size, size / 2);
}

void RecursiveImage2_3(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    RecursiveImage2_3(hdc, cx - size / 2, cy - size, size / 2);
    RecursiveImage2_3(hdc, cx + size / 2, cy - size, size / 2);
}

void RecursiveImage2_4(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    RecursiveImage2_4(hdc, cx - size, cy + size, size / 2);
    RecursiveImage2_4(hdc, cx + size, cy + size, size / 2);
}
void RecursiveImage2_5(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage2_5(hdc, cx - size, cy - size, size / 2);
    RecursiveImage2_5(hdc, cx + size, cy - size, size / 2);
    RecursiveImage2_5(hdc, cx - size, cy + size, size / 2);
    RecursiveImage2_5(hdc, cx + size, cy + size, size / 2);
}

void RecursiveImage2_6(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    RecursiveImage2_6(hdc, cx - size, cy, size / 2);
}

void RecursiveImage2_7(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    RecursiveImage2_7(hdc, cx + size, cy, size / 2);
}

void RecursiveImage2_8(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    RecursiveImage2_8(hdc, cx - size, cy, size / 2);
    RecursiveImage2_8(hdc, cx + size, cy, size / 2);
}


void Image3(HDC hdc, int cx, int cy, int size)
{
    int x1 = cx;
    int x2 = cx + size;
    int x3 = cx;
    int x4 = cx - size;

    int y1 = cy - size;
    int y2 = cy;
    int y3 = cy + size;
    int y4 = cy;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage3_1(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_1(hdc, cx + size, cy, size / 2);
}

void RecursiveImage3_2(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_2(hdc, cx + size, cy, size / 2);
    RecursiveImage3_2(hdc, cx - size, cy, size / 2);
}

void RecursiveImage3_3(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_3(hdc, cx + size, cy, size / 2);
    RecursiveImage3_3(hdc, cx - size, cy, size / 2);
    RecursiveImage3_3(hdc, cx, cy + size, size / 2);
}

void RecursiveImage3_4(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_4(hdc, cx + size, cy, size / 2);
    RecursiveImage3_4(hdc, cx - size, cy, size / 2);
    RecursiveImage3_4(hdc, cx, cy - size, size / 2);
}

void RecursiveImage3_5(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage3_5(hdc, cx + size, cy, size / 2);
    RecursiveImage3_5(hdc, cx - size, cy, size / 2);
    RecursiveImage3_5(hdc, cx, cy - size, size / 2);
    RecursiveImage3_5(hdc, cx, cy + size, size / 2);
}


void Image4(HDC hdc, int cx, int cy, int size)
{
    int x1 = cx;
    int x2 = cx + size / 4;
    int x3 = cx + size;
    int x4 = cx + size / 4;
    int x5 = cx;
    int x6 = cx - size / 4;
    int x7 = cx - size;
    int x8 = cx - size / 4;

    int y1 = cy - size;
    int y2 = cy - size / 4;
    int y3 = cy;
    int y4 = cy + size / 4;
    int y5 = cy + size;
    int y6 = cy + size / 4;
    int y7 = cy;
    int y8 = cy - size / 4;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);
    LineTo(hdc, x8, y8);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage4_1(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage4_1(hdc, cx + size, cy, size / 2);
}


void RecursiveImage4_2(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage4_2(hdc, cx - size, cy, size / 2);
}

void RecursiveImage4_3(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage4_3(hdc, cx + size, cy, size / 2);
    RecursiveImage4_3(hdc, cx - size, cy, size / 2);
}
void RecursiveImage4_4(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage4_4(hdc, cx - size, cy, size / 2);

    RecursiveImage4_4(hdc, cx, cy - size, size / 2);

    RecursiveImage4_4(hdc, cx, cy + size, size / 2);
}

void Image5(HDC hdc, int cx, int cy, int size)
{
    int x1 = cx;
    int x2 = cx + size;
    int x3 = cx + size;
    int x4 = cx;
    int x5 = cx - size;
    int x6 = cx - size;

    int y1 = cy - size / 2;
    int y2 = cy - size;
    int y3 = cy + size;
    int y4 = cy + size / 2;
    int y5 = cy + size;
    int y6 = cy - size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}
void RecursiveImage5_1(HDC hdc, int cx, int cy, int size) {
    Image5(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage5_1(hdc, cx - size, cy - size, size / 2);

    RecursiveImage5_1(hdc, cx + size, cy - size, size / 2);

    RecursiveImage5_1(hdc, cx - size, cy + size, size / 2);
    RecursiveImage5_1(hdc, cx + size, cy + size, size / 2);
}
void Image6(HDC hdc, int cx, int cy, int size) {
    int x1 = cx + size / 2;
    int x2 = cx + size;
    int x3 = cx + size;
    int x4 = cx + size / 2;
    int x5 = cx - size / 2;
    int x6 = cx - size;
    int x7 = cx - size;
    int x8 = cx - size / 2;

    int y1 = cy - size;
    int y2 = cy - size / 2;
    int y3 = cy + size / 2;
    int y4 = cy + size;
    int y5 = cy + size;
    int y6 = cy + size / 2;
    int y7 = cy - size / 2;
    int y8 = cy - size;
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);

    LineTo(hdc, x7, y7);

    LineTo(hdc, x8, y8);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void RecursiveImage6_1(HDC hdc, int cx, int cy, int size) {
    Image6(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage6_1(hdc, cx, cy - 2 * size, size / 2);
    RecursiveImage6_1(hdc, cx + size, cy - size, size / 2);
    RecursiveImage6_1(hdc, cx + 2 * size, cy, size / 2);
    RecursiveImage6_1(hdc, cx + size, cy + size, size / 2);
    RecursiveImage6_1(hdc, cx, cy + 2 * size, size / 2);
    RecursiveImage6_1(hdc, cx - size, cy + size, size / 2);
    RecursiveImage6_1(hdc, cx - 2 * size, cy, size / 2);
    RecursiveImage6_1(hdc, cx - size, cy - size, size / 2);
}
void Image7(HDC hdc, int cx, int cy, int size)
{
    int x1 = cx - size;
    int x2 = cx;
    int x3 = cx + size;
    int x4 = cx;
    int x5 = cx - size;
    int x6 = cx - size / 2;

    int y1 = cy - size;
    int y2 = cy - size;
    int y3 = cy;
    int y4 = cy + size;
    int y5 = cy + size;
    int y6 = cy;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);

}

void RecursiveImage7_1(HDC hdc, int cx, int cy, int size) {
    Image7(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage7_1(hdc, cx + 3 * size / 2, cy, size / 2);
    RecursiveImage7_1(hdc, cx - size, cy, size / 2);
}

void Image8(HDC hdc, int cx, int cy, int size)
{
    Ellipse(hdc, cx - size, cy - size, cx + size, cy + size);
    Ellipse(hdc, cx - size / 4, cy - 3 * size / 2, cx + 5 * size / 4, cy);

    Ellipse(hdc, cx - size / 2, cy - size / 2, cx + size / 2, cy + size / 2);


}

void RecursiveImage8_1(HDC hdc, int cx, int cy, int size) {
    Image8(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage8_1(hdc, cx + size, cy, size / 2);

    RecursiveImage8_1(hdc, cx - size, cy, size / 2);

    RecursiveImage8_1(hdc, cx, cy + size, size / 2);

    RecursiveImage8_1(hdc, cx, cy - size, size / 2);
}

void Image9(HDC hdc, int cx, int cy, int size)
{
    Image3(hdc, cx, cy, size / 3);
    Image3(hdc, cx - size, cy, size / 3);
    Image3(hdc, cx + size, cy, size / 3);
}

void RecursiveImage9_1(HDC hdc, int cx, int cy, int size) {
    Image9(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage9_1(hdc, cx + size, cy, size / 2);

    RecursiveImage9_1(hdc, cx - size, cy, size / 2);

    RecursiveImage9_1(hdc, cx, cy + size, size / 2);

    RecursiveImage9_1(hdc, cx, cy - size, size / 2);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_DOWN:
            moveDown();
            size -= 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_LEFT:
            r -= 10;
            moveToLeft();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            moveUp();

            size += 10;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:

            r -= 10;
            moveToRight();
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case VK_RETURN:
            if (insideGoal(aimX, aimY)) {
                hit++;
            }
            else {
                missed++;
            }

            InvalidateRect(hWnd, NULL, TRUE);
            break;
        
        case VK_F1:
            number_task -= 1;

            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_F2:
            number_task += 1;

            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            switch (number_task)
            {
            case 1:
                game(hdc); 
                break;
            case 2:
                RecursiveCross(hdc, 200, 160, size, RGB(r, 0, 0));
                break;
            case 3:
                RecursiveTriangle(hdc, 200, 160, size);
                break;
            case 4:
                RecursiveCircle(hdc, 200, 160, size);
                break;
            case 5:
                pic(hdc);
                break;
            case 6:
                cicle(hdc);
                break;
            case 7:
                StClausAuto(hdc, 10, 10);
                break;
            case 8:
                StClausAuto(hdc, 10, 10);
                break;
            case 9:
                Snowman(hdc, 10, 10);
                break;
            case 10:
                Logo(hdc, 10, 10);
                break;
            case 11:
                RecursiveImage1_1(hdc, 200, 160, 80);
                break;
            case 12:
                RecursiveImage1_2(hdc, 550, 150, 80);
                RecursiveImage1_3(hdc, 800, 150, 80);

                RecursiveImage1_4(hdc, 80, 400, 80);

                RecursiveImage1_5(hdc, 260, 400, 80);

                RecursiveImage1_6(hdc, 550, 400, 80);

                RecursiveImage1_7(hdc, 800, 500, 80);
                break;
            case 13:
                RecursiveImage2_1(hdc, 200, 100, 80);
                RecursiveImage2_2(hdc, 400, 150, 60);
                RecursiveImage2_3(hdc, 600, 150, 60);
                RecursiveImage2_4(hdc, 800, 100, 80);
                break;
            case 14:
                RecursiveImage2_5(hdc, 200, 400, 80);
                RecursiveImage2_6(hdc, 600, 400, 80);
                RecursiveImage2_7(hdc, 800, 400, 80);
                RecursiveImage2_8(hdc, 1000, 400, 80);

                break;
            case 15:
                RecursiveImage3_1(hdc, 100, 100, 60);
                RecursiveImage3_2(hdc, 500, 200, 60);
                RecursiveImage3_3(hdc, 800, 200, 60);
                RecursiveImage3_4(hdc, 100, 400, 60);
                RecursiveImage3_5(hdc, 500, 400, 60);
                break;
            case 16:
                RecursiveImage4_1(hdc, 100, 100, 80);

                RecursiveImage4_2(hdc, 450, 100, 80);

                RecursiveImage4_3(hdc, 800, 100, 80);

                RecursiveImage4_4(hdc, 150, 300, 80);
                break;
            case 17:
                RecursiveImage5_1(hdc, 200, 200, 80);
                RecursiveImage5_1(hdc, 500, 100, 20);
                break;
            case 18:

                RecursiveImage6_1(hdc, 200, 200, 60);
                break;
            case 19:
                RecursiveImage7_1(hdc, 500, 200, 60);
                break;
            case 20:
                RecursiveImage9_1(hdc, 800, 200, 60);
                break;
            }

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
