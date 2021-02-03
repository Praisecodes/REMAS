#pragma once

#include "Calculator.h"

LRESULT CALLBACK mainProc(HWND, UINT, WPARAM, LPARAM);
void Buttons(HWND);
void Statics(HWND);
HWND RemasApp;
HWND buttonClear, buttonTotal, buttonPurchase, buttonMenu, hold;

HFONT buttons = CreateFont(30, 15, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
	CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Arial Black"));

void MainApp(HINSTANCE hinstancef) {
	WNDCLASS main = {};

	int HEIGHT = GetSystemMetrics(SM_CYSCREEN);
	int WIDTH = GetSystemMetrics(SM_CXSCREEN);

	main.hbrBackground = CreateSolidBrush(RGB(0, 0, 39));
	main.hCursor = LoadCursor(NULL, IDC_ARROW);
	main.hInstance = hinstancef;
	main.lpfnWndProc = mainProc;
	main.lpszClassName = L"mainName";

	RegisterClass(&main);

	RemasApp = CreateWindowEx(0, L"mainName", L"Remas 1.0.0", WS_MINIMIZEBOX | WS_SYSMENU | WS_VISIBLE, 0, 0, WIDTH, HEIGHT,
		NULL, NULL, hinstancef, NULL);

	MSG Mainmsg = {};

	while (GetMessage(&Mainmsg, NULL, 0, 0))
	{
		TranslateMessage(&Mainmsg);
		DispatchMessage(&Mainmsg);
	}
}

LRESULT CALLBACK mainProc(HWND hwnd2, UINT mas2, WPARAM wp2, LPARAM lp2)
{
	switch (mas2)
	{
	case WM_CREATE:
		Calculator(hwnd2);
		Buttons(hwnd2);
		Statics(hwnd2);
		break;

	case WM_COMMAND:
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd2, mas2, wp2, lp2);
		break;
	}

	return 0;
}

void Buttons(HWND hwnd)
{
	//Button saying CLEAR
	buttonClear = CreateWindowEx(0, L"BUTTON", L"CLEAR", WS_CHILD | WS_VISIBLE | BS_FLAT, 1000, 688, 120, 40, hwnd, NULL, NULL, NULL);
	SendMessage(buttonClear, WM_SETFONT, (WPARAM)buttons, MAKELPARAM(TRUE, 0));

	//Button saying TOTAL
	buttonTotal = CreateWindowEx(0, L"BUTTON", L"TOTAL", WS_CHILD | WS_VISIBLE | BS_FLAT, 1170, 688, 120, 40, hwnd, NULL, NULL, NULL);
	SendMessage(buttonTotal, WM_SETFONT, (WPARAM)buttons, MAKELPARAM(TRUE, 0));

	//Button saying PURCHASE
	buttonPurchase = CreateWindowEx(0, L"BUTTON", L"PURCHASE", WS_CHILD | WS_VISIBLE | BS_FLAT, 770, 610, 180, 40, hwnd, NULL, NULL, NULL);
	SendMessage(buttonPurchase, WM_SETFONT, (WPARAM)buttons, MAKELPARAM(TRUE, 0));

	//Button saying MENU
	buttonMenu = CreateWindowEx(0, L"BUTTON", L"MENU", WS_CHILD | WS_VISIBLE | BS_FLAT, 20, 20, 120, 40, hwnd, NULL, NULL, NULL);
	SendMessage(buttonMenu, WM_SETFONT, (WPARAM)buttons, MAKELPARAM(TRUE, 0));
}

void Statics(HWND hwnd)
{
	hold = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE, 160, 100, 800, 500, hwnd, NULL, NULL, NULL);
}
