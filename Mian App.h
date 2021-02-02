#pragma once

#include "Password System.h"

LRESULT CALLBACK mainProc(HWND, UINT, WPARAM, LPARAM);
HWND RemasApp;

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

	RemasApp = CreateWindowEx(0, L"mainName", L"Remas 1.0.0", WS_MINIMIZEBOX | WS_VISIBLE | WS_SYSMENU, 0, 0, WIDTH, HEIGHT,
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
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd2, mas2, wp2, lp2);
		break;
	}
	return 0;
}

