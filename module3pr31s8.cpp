// module3pr31s8.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "module3pr31s8.h"
#include "commdlg.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
SYSTEMTIME oldtime,newtime;
HWND hEditOldDate, hEditNewYear, hEditNewDay, hEditNewMonth,hEditNewHour,hEditNewMinute;
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
void                GetOldTime();
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
    LoadStringW(hInstance, IDC_MODULE3PR31S8, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MODULE3PR31S8));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MODULE3PR31S8));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MODULE3PR31S8);
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
   else {
       hEditOldDate= CreateWindowEx(0, L"Edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 10, 200, 30, hWnd, NULL, hInst, 0);
       CreateWindowEx(0, L"Static", L"День", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 60, 100, 20, hWnd, NULL, hInst, 0);
       hEditNewDay= CreateWindowEx(0, L"Edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 80, 100, 30, hWnd, NULL, hInst, 0);
       CreateWindowEx(0, L"Static", L"Месяц", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 60, 100, 20, hWnd, NULL, hInst, 0);
       hEditNewMonth= CreateWindowEx(0, L"Edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 80, 100, 30, hWnd, NULL, hInst, 0);
       CreateWindowEx(0, L"Static", L"Год", WS_VISIBLE | WS_CHILD | WS_BORDER, 230, 60, 100, 20, hWnd, NULL, hInst, 0);
       hEditNewYear= CreateWindowEx(0, L"Edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 230, 80, 100, 30, hWnd, NULL, hInst, 0);
       CreateWindowEx(0, L"Static", L"Часы", WS_VISIBLE | WS_CHILD | WS_BORDER, 340, 60, 100, 20, hWnd, NULL, hInst, 0);
       hEditNewHour= CreateWindowEx(0, L"Edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 340, 80, 100, 30, hWnd, NULL, hInst, 0);
       CreateWindowEx(0, L"Static", L"Минуты", WS_VISIBLE | WS_CHILD | WS_BORDER, 450, 60, 100, 20, hWnd, NULL, hInst, 0);
       hEditNewMinute= CreateWindowEx(0, L"Edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 450, 80, 100, 30, hWnd, NULL, hInst, 0);
        CreateWindowEx(0, L"Button", L"Изменить дату", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 200, 200, 30, hWnd, (HMENU)IDC_BUTTON1, hInst, 0);
       EnableWindow(hEditOldDate, FALSE);
       GetOldTime();
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
void GetOldTime() {
    GetSystemTime(&oldtime);
    wchar_t buf[250];
    wsprintf(buf, L"%d.%d.%d %d:%d", oldtime.wDay, oldtime.wMonth, oldtime.wYear, oldtime.wHour, oldtime.wMinute);
    SetWindowText(hEditOldDate, buf);
}
void SetNewTime() {
    int bufSize = GetWindowTextLength(hEditNewDay)+1;
    wchar_t* buf = new wchar_t(bufSize);
    GetWindowText(hEditNewDay, buf, bufSize);
    newtime.wDay = (WORD)buf;

    bufSize = GetWindowTextLength(hEditNewMonth) + 1;
    buf = new wchar_t(bufSize);
    GetWindowText(hEditNewMonth, buf, bufSize);
    newtime.wMonth = (WORD)buf;

    bufSize = GetWindowTextLength(hEditNewYear) + 1;
    buf = new wchar_t(bufSize);
    GetWindowText(hEditNewYear, buf, bufSize);
    newtime.wYear = (WORD)buf;

    bufSize = GetWindowTextLength(hEditNewHour) + 1;
    buf = new wchar_t(bufSize);
    GetWindowText(hEditNewHour, buf, bufSize);
    newtime.wHour = (WORD)buf;

    bufSize = GetWindowTextLength(hEditNewMinute) + 1;
    buf = new wchar_t(bufSize);
    GetWindowText(hEditNewMinute, buf, bufSize);
    newtime.wMinute = (WORD)buf;

    wchar_t buf2[250];
    wsprintf(buf2, L"%d.%d.%d %d:%d", newtime.wDay, newtime.wMonth, newtime.wYear, newtime.wHour, newtime.wMinute);
    SetWindowText(hEditOldDate, buf2);
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

            case IDC_BUTTON1: {
                SetNewTime();
            }
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
