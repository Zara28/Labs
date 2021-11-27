// game_2d_arr.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "game_2d_arr.h"
#include "stdio.h"
#include "Header.h"
#include <stdlib.h>
#include <time.h>

#define MAX_LOADSTRING 100
bool move = true;
bool end = false;
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
    LoadStringW(hInstance, IDC_GAME2DARR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAME2DARR));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAME2DARR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GAME2DARR);
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
    case WM_CREATE:
        SetTimer(hWnd, 1, 5000, 0); // Запускаем таймер
        srand(time(NULL)); // Перезапуск генератора случайных чисел

        break;

    case WM_TIMER:
        if (move)
        {
            MoveMonsters(); // перемещаем монстров
        }
        InvalidateRect(hWnd, NULL, TRUE);

break;

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
        case 0x51:
            ReadFromFile();//Q быстрая загрузка последнего сохранения
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x53:
            WriteInFile();//S - save game
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x4D:
            randomMove(); //M - random move
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x48://H - hand of Midas
            MidasHandToRight();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x4e: // N - New  
            generateLevel();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x47:
            addGold(); // G - gold
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN:
            move = false;
            moveDown();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_LEFT:
            move = false;
            moveToLeft();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            move = false;
            moveUp();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:
            move = false;
            moveToRight();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 76:
            Create_wall_left();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 82:
            Create_wall_right();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 90:
            Destroy_wall_right();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 65:
            Destroy_wall(1);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 79:
            Destroy_wall(2);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 68:
            Destroy_wall_D();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 88:
            Double();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 48:
            Again();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 49:
            to_end();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }

        move = true;
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            if (!EndGame())
            {
                DrawField(hdc);
            }
            else
            {
                TCHAR  string1[] = _T("Game over");
                TextOut(hdc, 10, 20, (LPCWSTR)string1, _tcslen(string1));
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
