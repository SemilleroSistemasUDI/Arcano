// Optimizacion.cpp : Define el punto de entrada para la aplicación de analisis de trafico de una red.
//

// Cabeceras precompiladas denominadas Win32.pch
#include "stdafx.h"
#include "Optimizacion.h"

#define MAX_LOADSTRING 100

// Variables Globales:
HINSTANCE hInst;                                // instancia actual
WCHAR szTitle[MAX_LOADSTRING];                  // El texto de la barra de título
WCHAR szWindowClass[MAX_LOADSTRING];            // el nombre de clase de la ventana principal

// Remitir las declaraciones de funciones incluidas en este módulo de código:
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

    // TODO: Colocar aquí el código.

    // Inicializar strings globales
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_OPTIMIZACION, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Realizar operaciones de inicialización de la aplicación:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OPTIMIZACION));

    MSG msg;

    // Bucle principal de mensajes (Main message loop):
	//
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
//  FUNCION: MyRegisterClass()
//
//  PROPOSITO: Registra la clase window.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OPTIMIZACION));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OPTIMIZACION);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCION: InitInstance(HINSTANCE, int)
//
//   PROPOSITO: Guarda el manejador de la instancia 'instance handle' y crea la ventana principal (main window)
//
//   COMENTARIOS:
//
//        En esta función, ahorramos el identificador de instancia en una variable global, creamos y
//        mostramos la ventana principal del programa.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Almacenamos el manejador de la instancia 'instance handle' en la variable global

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
//  FUNCION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PROPOSITO:  Procesa los mensajes para la ventana principal (main window).
//
//  WM_COMMAND  - procesar el menú de la aplicación
//  WM_PAINT    - Pintar la ventana principal
//  WM_DESTROY  - Enviar un mensaje salir y volver
//
//  COMENTARIOS
//		 Todas las aplicaciones basadas en Win32 deben tener una función de procedimiento de ventana.
//		 Esta función normalmente se denomina WndProc.
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analizar las selecciones del menú:
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
            // TODO: Agregar cualquier codigo de dibujo que use hdc aquí...

			// Manejador de mensajes para boton de cargar archivo (Load File button)
			HWND hwndButton = CreateWindow(
				L"BUTTON",  // Clase predefinida; Unicode assumed 
				L"Load file",      // Texto del Botoon 
				WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Estilos 
				10,         // Posicion en X 
				10,         // Posicion en Y 
				100,        // Ancho del boton
				32,        // Alto del Boton
				hWnd,		// Ventana Padre
				NULL,       // Sin menu
				(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
				NULL);      // No es necesario el puntero
			// 


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

// Manejador de mensajes para la caja acerca de (about box).
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