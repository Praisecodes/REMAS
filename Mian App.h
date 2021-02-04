#pragma once

#include <string>
#include "Calculator.h"

LRESULT CALLBACK mainProc(HWND, UINT, WPARAM, LPARAM);
void Buttons(HWND);
void Statics(HWND);
HWND RemasApp;
HWND buttonClear, buttonTotal, buttonPurchase, buttonMenu, hold;

int calculations = 0;
int Answer = 0;

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
		switch (wp2)
		{
		case bone:
		{
			char text[100];
			GetWindowTextA(one, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case btwo:
		{
			char text[100];
			GetWindowTextA(two, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bthree:
		{
			char text[100];
			GetWindowTextA(three, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bfour:
		{
			char text[100];
			GetWindowTextA(four, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bfive:
		{
			char text[100];
			GetWindowTextA(five, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bsix:
		{
			char text[100];
			GetWindowTextA(six, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bseven:
		{
			char text[100];
			GetWindowTextA(seven, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case beight:
		{
			char text[100];
			GetWindowTextA(eight, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bnine:
		{
			char text[100];
			GetWindowTextA(nine, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bzero:
		{
			char text[100];
			GetWindowTextA(zero, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bplus:
		{
			char text[100];
			GetWindowTextA(plus, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bminus:
		{
			char text[100];
			GetWindowTextA(minus, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case btimes:
		{
			char text[] = "*";

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bdivide:
		{
			char text[100];
			GetWindowTextA(divide, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bdot:
		{
			char text[100];
			GetWindowTextA(dot, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bBracketO:
		{
			char text[100];
			GetWindowTextA(bracketO, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bBracketC:
		{
			char text[100];
			GetWindowTextA(bracketC, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bmodulo:
		{
			char text[100];
			GetWindowTextA(modulo, text, 100);

			strcat_s(out, text);
			SetWindowTextA(Screen, out);
		}
			break;

		case bclear:
		{
			char out2[100];
			char clean[] = "";
			char ResultClean[] = "0";

			strcpy_s(out2, ResultClean);
			strcpy_s(out, clean);
			SetWindowTextA(Screen, out);
			SetWindowTextA(ResultScreen, out2);
		}
			break;

		case bequal:
		{
			
		}
			break;
		}
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
