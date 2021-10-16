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
