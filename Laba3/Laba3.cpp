// Laba3.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Laba3.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

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
    LoadStringW(hInstance, IDC_LABA3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA3));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LABA3);
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

    MoveToEx(hdc, x+25, y+25, NULL);
    Ellipse(hdc, x+25, y+25, x+150, y+100);

    Ellipse(hdc,x+ 30, y+30, x+145, y+65);
    Ellipse(hdc, x + 65, y + 25, x + 110, y + 100);

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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...

            ////task1
            //RECT rect;
            //GetClientRect(hWnd, &rect);
            //StClausAuto(hdc, 10, 10);
            //StClausAuto(hdc, 10, rect.bottom-100);
            //StClausAuto(hdc, rect.right-60, 10);
            //StClausAuto(hdc, rect.right - 60, rect.bottom - 100);
            //StClausAuto(hdc, rect.right/2, rect.bottom/2);


            ////task2
            //int x = 10, n = 0;
            //while (n<8)
            //{
            //    StClausAuto(hdc, x, 10);
            //    x += 40;
            //    n += 1;
            //}

            ////task3
            //int y = 100;
            //n = 0;
            //while (n<4)
            //{
            //    StClausAuto(hdc, x, y);
            //    y += 100;
            //    n += 1;
            //}

            ////task4
            //y = 200, x = 40, n = 0;
            //while (n < 4)
            //{
            //    StClausAuto(hdc, x, y);
            //    x += 40;
            //    y += 100;
            //    n += 1;
            //}

            ////task5
            //int x = 10, y = 10;
            //for (int i = 0; i < 4; i++)
            //{
            //    for (int i = 0; i < 8; i++)
            //    {
            //        StClausAuto(hdc, x, y);
            //        x += 40;
            //    }
            //    x = 10;
            //    y += 80;
            //}

           // //task6-7
           // Snowman(hdc, 10, 10);

           //// task8

           // //task8.1
           // RECT rect;
           // GetClientRect(hWnd, &rect);
           // Snowman(hdc, 10, 10);
           // Snowman(hdc, 10, rect.bottom-150);
           // Snowman(hdc, rect.right-100, 10);
           // Snowman(hdc, rect.right - 100, rect.bottom - 150);
           // Snowman(hdc, rect.right/2, rect.bottom/2);


           // //task8.2
           // int x = 10, n = 0;
           // while (n<8)
           // {
           //     Snowman(hdc, x, 10);
           //     x += 40;
           //     n += 1;
           // }

           // //task8.3
           //int  y = 100;
           // n = 0;
           // while (n<4)
           // {
           //     Snowman(hdc, x, y);
           //     y += 100;
           //     n += 1;
           // }

           // //task8.4
           // y = 200;
           // x = 40, n = 0;
           // while (n < 4)
           // {
           //     Snowman(hdc, x, y);
           //     x += 40;
           //     y += 100;
           //     n += 1;
           // }

            ////task8.5
            //int x = 10, y = 10;
            //for (int i = 0; i < 4; i++)
            //{
            //    for (int i = 0; i < 8; i++)
            //    {
            //        Snowman(hdc, x, y);
            //        x += 40;
            //    }
            //    x = 10;
            //    y += 80;
            //}

           // hometask

            ////task1
           /* RECT rect;
            GetClientRect(hWnd, &rect);
            Logo(hdc, 10, 10);
            Logo(hdc, 10, rect.bottom-100);
            Logo(hdc, rect.right-300, 10);
            Logo(hdc, rect.right - 300, rect.bottom - 100);
            Logo(hdc, rect.right/2, rect.bottom/2);*/


            ////task2
            //int x = 0, n = 0;
            //while (n<8)
            //{
            //    Logo(hdc, x, 10);
            //    x += 110;
            //    n += 1;
            //}

            ////task3
            //int y = 100;
            //n = 0;
            //while (n<4)
            //{
            //    Logo(hdc, x, y);
            //    y += 100;
            //    n += 1;
            //}

            ////task4
            //y = 200, x = 40, n = 0;
            //while (n < 4)
            //{
            //    Logo(hdc, x, y);
            //    x += 110;
            //    y += 100;
            //    n += 1;
            //}

            //task5
            int x = 10, y = 10;
            for (int i = 0; i < 4; i++)
            {
                for (int i = 0; i < 8; i++)
                {
                    Logo(hdc, x, y);
                    x += 110;
                }
                x = 10;
                y += 80;
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
