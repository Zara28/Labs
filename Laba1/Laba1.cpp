// Laba1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Laba1.h"

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
    LoadStringW(hInstance, IDC_LABA1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA1));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LABA1);
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
                else if(i > 7)
                {
                    Ellipse(hdc, 600 + 30 * (9-i+1), 360, 650 + 30 *(9- i+1), 410);
                }
                else
                {
                    Ellipse(hdc, 600 + 30 * (i/2-1), 330, 650 +30 *(i/2-1), 380);
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


          /*  MoveToEx(hdc, 50, 50, NULL);
            Ellipse(hdc, 50, 50, 300, 200);

            Ellipse(hdc, 60, 60, 290, 130);
            Ellipse(hdc, 130, 50, 220, 200);*/
            
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
