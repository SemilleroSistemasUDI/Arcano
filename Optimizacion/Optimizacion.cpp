// Optimizacion.cpp: define el punto de entrada de la aplicación.
//

#include "stdafx.h"
#include "Optimizacion.h"
#include "commdlg.h"
#include <iostream>
#include <fstream>
#include <string>

#define MAX_LOADSTRING 100
#define ID_EXA 1
#define ID_PROC 2

using namespace std;

// Variables para usar el cuadro de dialog de openFile:
OPENFILENAME ofn;											// Instancia de la clase OPENFILENAME
TCHAR szFilters[] = _T("Archivos de texto (*.txt)\0*.txt\0\0");		// Filtro de fichero a seleccionar
TCHAR szFilePathName[_MAX_PATH] = _T("");							// Path del archivo seleccionado
//Variables de los elementos creados:
HWND TxtPath;								//	Instancia de la caja de texto Path 
HWND BtnExamine;							//	Instancia del boton Examinar
HWND lblFilter;								//	Instancia del label filtro
HWND TxtFilter;								//	Instancia de la caja de texto para los filtros
HWND BtnProcess;							//	Instancia del boton Procesar
// Variable para la manipulación de archivos
ifstream fe;
ofstream fs;
string cadena;
// Variables globales:
HINSTANCE hInst;                                // Instancia actual
WCHAR szTitle[MAX_LOADSTRING];                  // Texto de la barra de título
WCHAR szWindowClass[MAX_LOADSTRING];            // nombre de clase de la ventana principal

// Declaraciones de funciones adelantadas incluidas en este módulo de código:
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

	// TODO: colocar código aquí.

	// Inicializar cadenas globales
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_OPTIMIZACION, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Realizar la inicialización de la aplicación:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OPTIMIZACION));

	MSG msg;

	// Bucle principal de mensajes:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCIÓN: MyRegisterClass()
//
//  PROPÓSITO: registrar la clase de ventana.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OPTIMIZACION));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_OPTIMIZACION);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCIÓN: InitInstance(HINSTANCE, int)
//
//   PROPÓSITO: guardar el identificador de instancia y crear la ventana principal
//
//   COMENTARIOS:
//
//        En esta función, se guarda el identificador de instancia en una variable común y
//        se crea y muestra la ventana principal del programa.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Almacenar identificador de instancia en una variable global

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
//  FUNCIÓN: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PROPÓSITO:  procesar mensajes de la ventana principal.
//
//  WM_COMMAND  - procesar el menú de aplicaciones
//  WM_PAINT    - Pintar la ventana principal
//  WM_DESTROY  - publicar un mensaje de salida y volver
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Analizar las selecciones de menú:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_EXA:
			BOOL rc;
			ZeroMemory(&ofn, sizeof(ofn));				// Rellena el bloque de memoria con 0
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hWnd;						// Definir el dueño del cuadro de dialog
			ofn.lpstrFilter = szFilters;				// Filtro de las extenciones 
			ofn.lpstrFile = szFilePathName;				// Esto contine el nombre del archivo
			ofn.lpstrDefExt = _T("txt");				// Se define la extension
			ofn.nMaxFile = _MAX_PATH;					// Tamaño del buffer para contener el archivo
			ofn.lpstrTitle = _T("Abrir Archivo");		// Titulo del cuadro de dialog
			ofn.Flags = OFN_FILEMUSTEXIST;				// Bandera para determinar si el archivo existe al momento de digitarlo en la caja de texto del cuadro de dialog
			rc = GetOpenFileName(&ofn);
			if (rc)
			{
				SetWindowText(TxtPath, szFilePathName); // Asignamos el path del archivo seleccionado a la caja de texto
			}
			break;
		case ID_PROC:
			char str[_MAX_PATH];
			char strCompare[_MAX_PATH];
			int exist;
			GetWindowTextA(TxtFilter, strCompare, _MAX_PATH);    // Obteniendo el valor del campo de texto de filtro
			fe.open(szFilePathName); // Abrir archivo seleccionado
			if (fe.is_open())		//	comprobar si el archivo esta abierto
			{
				while (getline(fe, cadena)) // Recorrer linea a linea el archivo
				{
					// TODO: Falta construir el analisis de busqueda
				}
				// TODO: Salida de archivo
				/*fs.open("Analisis.txt");
				fs << exist << endl;
				fs.close();*/
				fe.close(); // Cerrar Archivo de lectura
				MessageBox(hWnd, L"Archivo creado satisfactoriamente", L"Salida de Archivo", MB_OK | MB_ICONINFORMATION);
			}
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
		// TODO: Agregar cualquier código de dibujo que use hDC aquí...

		BtnExamine = CreateWindow(
			L"BUTTON", L"Examinar",	// TYPE, TEXT
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT,
			10, 10, 100, 40, // X, Y , WIDTH, HEIGHT
			hWnd, (HMENU)ID_EXA, //OWNER, ID 
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);

		TxtPath = CreateWindow(
			L"EDIT", L"", // TYPE, TEXT
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOVSCROLL | ES_LEFT | ES_MULTILINE | ES_READONLY,
			120, 20, 350, 20,// X, Y , WIDTH, HEIGHT
			hWnd, NULL, //OWNER, ID
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);

		lblFilter = CreateWindow(
			L"STATIC", L"FILTRO:",// TYPE, TEXT
			SS_SIMPLE | WS_VISIBLE | WS_CHILD,
			480, 20, 50, 40,// X, Y , WIDTH, HEIGHT
			hWnd, NULL, //OWNER, ID
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);

		TxtFilter = CreateWindow(
			L"EDIT", L"",// TYPE, TEXT
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOVSCROLL | ES_LEFT | ES_MULTILINE,
			540, 20, 350, 20,// X, Y , WIDTH, HEIGHT
			hWnd, NULL, // OWNER, ID
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);

		BtnProcess = CreateWindow(
			L"BUTTON", L"PROCESAR",// TYPE, TEXT
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT,
			900, 10, 100, 40,// X, Y , WIDTH, HEIGHT
			hWnd, (HMENU)ID_PROC, // OWNER, ID
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		// END paint
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

// Controlador de mensajes del cuadro Acerca de.
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
