// Laba5.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Laba5.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int number = 0;
int num2 = 0;
int size = 15;

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
    LoadStringW(hInstance, IDC_LABA5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA5));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LABA5);
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
void Сrown(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {

    POINT p[] = {
        cx,		cy - sizeY,
        cx + sizeX / 2,	cy,
        cx + sizeX,	cy - sizeY,
        cx + sizeX,	cy + sizeY,
        cx - sizeX,	cy + sizeY,
        cx - sizeX,	cy - sizeY,
        cx - sizeX / 2,	cy,
        cx,		cy - sizeY
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 8);
    DeleteObject(hPen);
}


void BlockСrown1(HDC hdc) {
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (x < 900) {
        Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        x += 100;
        sizeX += 5;

        g += 30;
    }
}

void BlockСrown2(HDC hdc) {
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (y < 600) {
        Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 80;
        sizeY += 5;

        r += 30;
    }
}
void BlockСrown3(HDC hdc) {
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (y < 600) {
        Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 80;
        sizeY += 5;

        x += 100;
        sizeX += 5;

        b += 30;
        g += 30;
    }
}

void BlockСrown4(HDC hdc) {
    int y = 50;
    int sizeY = 5;
    while (y < 600)
    {
        int r = 0;
        int b = 0;
        int g = 0;

        int x = 50;
        int sizeX = 5;

        while (x < 600) {
            Сrown(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

            x += 100;
            sizeX += 5;

            b += 30;
            g += 30;
        }

        y += 80;
        sizeY += 5;
    }
    
}

void Arrow(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {

    POINT p[] = {
        cx-sizeX, cy - sizeY,
        cx,	cy - sizeY,
        cx + sizeX,	cy,
        cx,	cy+sizeY,
        cx - sizeX,	cy + sizeY,
        cx - sizeX / 2,	cy,
        cx - sizeX, cy - sizeY,
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 7);
    DeleteObject(hPen);
}

void BlockArrow1(HDC hdc) {
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (x < 900) {
        Arrow(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        x += 100;
        sizeX += 5;

        g += 30;
    }
}

void BlockArrow2(HDC hdc) {
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (y < 600) {
        Arrow(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 80;
        sizeY += 5;

        r += 30;
    }
}
void BlockArrow3(HDC hdc) {
    int y = 50;
    int sizeY = 10;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;
    int sizeX = 10;

    while (y < 600) {
        Arrow(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 80;
        sizeY += 5;

        x += 100;
        sizeX += 5;

        b += 30;
        g += 30;
    }
}

void BlockArrow4(HDC hdc) {
    int y = 50;
    int sizeY = 5;
    while (y < 600)
    {
        int r = 0;
        int b = 0;
        int g = 0;

        int x = 50;
        int sizeX = 5;

        while (x < 600) {
            Arrow(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

            x += 100;
            sizeX += 5;

            b += 30;
            g += 30;
        }

        y += 80;
        sizeY += 5;
    }

}

void MyFigure1(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {

    POINT p[] = {
        cx, cy - sizeY,
        cx + sizeX/3,	cy - sizeY/3,
        cx + sizeX,	cy,
        cx,	cy + sizeY,
        cx - sizeX/3,	cy + sizeY/3,
        cx - sizeX,	cy,
        cx, cy - sizeY,
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 7);
    DeleteObject(hPen);
}


void BlockMyFigure11(HDC hdc, int sizeX, int sizeY) {
    int y = 50;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;

    while (x < 900) {
        MyFigure1(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        x += 100;
        sizeX += 5;

        g += 30;
    }
}

void BlockMyFigure12(HDC hdc, int sizeX, int sizeY) {
    int y = 50;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;

    while (y < 600) {
        MyFigure1(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 80;
        sizeY += 5;

        r += 30;
    }
}
void BlockMyFigure13(HDC hdc, int sizeX, int sizeY) {
    int y = 50;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;

    while (y < 600) {
        MyFigure1(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 80;
        sizeY += 5;

        x += 100;
        sizeX += 5;

        b += 30;
        g += 30;
    }
}

void BlockMyFigure14(HDC hdc, int sizeX, int sizeY) {
    int y = 50;
    while (y < 600)
    {
        int r = 0;
        int b = 0;
        int g = 0;

        int x = 50;

        while (x < 600) {
            MyFigure1(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

            x += 100;
            sizeX += 5;

            b += 30;
            g += 30;
        }

        y += 80;
        sizeY += 5;
    }

}

void MyFigure2(HDC hdc, int cx, int cy, int sizeX, int sizeY, COLORREF color) {

    POINT p[] = {
        cx, cy - sizeY,
        cx + sizeX / 4,	cy - sizeY / 4,
        cx + sizeX,	cy+sizeY/2,
        cx,	cy + sizeY,
        cx - sizeX / 6,	cy + sizeY / 4,
        cx - sizeX / 6,	cy - sizeY / 4,
        cx, cy - sizeY,
    };

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Polyline(hdc, p, 7);
    DeleteObject(hPen);
}


void BlockMyFigure21(HDC hdc, int sizeX, int sizeY) {
    int y = 50;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;

    while (x < 900) {
        MyFigure2(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        x += 100;
        sizeX += 5;

        g += 30;
    }
}

void BlockMyFigure22(HDC hdc, int sizeX, int sizeY) {
    int y = 50;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;

    while (y < 600) {
        MyFigure2(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 80;
        sizeY += 5;

        r += 30;
    }
}
void BlockMyFigure23(HDC hdc, int sizeX, int sizeY) {
    int y = 50;

    int r = 0;
    int b = 0;
    int g = 0;

    int x = 50;

    while (y < 600) {
        MyFigure2(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

        y += 80;
        sizeY += 5;

        x += 100;
        sizeX += 5;

        b += 30;
        g += 30;
    }
}

void BlockMyFigure24(HDC hdc, int sizeX, int sizeY) {
    int y = 50;
    while (y < 600)
    {
        int r = 0;
        int b = 0;
        int g = 0;

        int x = 50;

        while (x < 600) {
            MyFigure2(hdc, x, y, sizeX, sizeY, RGB(r, g, b));

            x += 100;
            sizeX += 5;

            b += 30;
            g += 30;
        }

        y += 80;
        sizeY += 5;
    }

}
void task1(int n, HDC hdc)
{
    if (n == 1)
    {
        //task1
        BlockСrown1(hdc);
        //task 2
        BlockСrown2(hdc);
        //task 3
        BlockСrown3(hdc);
    }
    else {
        BlockСrown4(hdc);
    }
}
void task2(int n, HDC hdc)
{
    if (n == 1)
    {
               //task1
              BlockArrow1(hdc);
              //task 2
              BlockArrow2(hdc);
              //task 3
              BlockArrow3(hdc);
    }
    else {
        BlockArrow4(hdc);
    }
}
void task3(int n, HDC hdc, int sizex, int sizey)
{
    if (n == 1)
    {
        //task1
        BlockMyFigure11(hdc, sizex, sizey);
        //task 2
        BlockMyFigure12(hdc, sizex, sizey);
        //task 3
        BlockMyFigure13(hdc, sizex, sizey);
    }
    else {
        BlockMyFigure14(hdc, sizex, sizey);
    }
}
void task4(int n, HDC hdc, int sizex, int sizey)
{
    if (n == 1)
    {
        //task1
        BlockMyFigure21(hdc, sizex, sizey);
        //task 2
        BlockMyFigure22(hdc, sizex, sizey);
        //task 3
        BlockMyFigure23(hdc, sizex, sizey);
    }
    else {
        BlockMyFigure24(hdc, sizex, sizey);
    }
}
void rec(int x, int y, int sizex, int sizey, HDC hdc, COLORREF color)
{
    MyFigure1(hdc, x + sizex, y, sizex, sizey, color);
    MyFigure1(hdc, x - sizex, y, sizex, sizey, color);
}
void task5(HDC hdc, int sizex, int sizey)
{
    int x = 500;
    int y = 50;
    int r = 0; int g = 0, b = 0;
    for (int i = 0; i < 13; i++)
    {
        int j = 0;
        while (j <= i)
        {
            MyFigure1(hdc, x-j*20, y, sizex, sizey, RGB(r, g, b));
            MyFigure1(hdc, x + j * 20, y, sizex, sizey, RGB(r, g, b));
            j += 1;
        }
        y += 50;
        r += 30;
        sizey+= 5;
    }

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
        case VK_RIGHT:
            number += 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_LEFT:
            number -= 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            size+=20;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN:
            size -= 20;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_LSHIFT:
            num2 = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RSHIFT:
            num2 = 2;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            if (number == 1)
            {
                task1(num2, hdc);
            }
            if (number == 2)
            {
                task2(num2, hdc);
            }
            if (number == 3)
            {
                task3(num2, hdc, size, size);
            }
            if (number == 4)
            {
                task4(num2, hdc, size, size);
            }
            if (number == 5)
            {
                task5(hdc, size, size);
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
