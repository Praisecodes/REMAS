#pragma once

#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#include <Windows.h>
#include <stdlib.h>


LRESULT CALLBACK PasswordProc(HWND, UINT, WPARAM, LPARAM);

bool check_value = true;
bool reset_value = false;
HWND passwordWindow;

void Body(HWND);

void DestroyWindows(HWND window1, HWND window2)
{
	DestroyWindow(window1);
	DestroyWindow(window2);
}

void PasswordSystem(HINSTANCE instance)
{
	WNDCLASS wc = {};

	wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 39));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = instance;
	wc.lpfnWndProc = PasswordProc;
	wc.lpszClassName = L"name";

	RegisterClass(&wc);

	passwordWindow = CreateWindowEx(0, L"name", L"Password", WS_MINIMIZEBOX | WS_SYSMENU |  WS_VISIBLE, 500, 300, 400, 240, NULL, NULL, instance, NULL);

	MSG msg = {};

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

HFONT Signfont = CreateFont(40, 20, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
	ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("CALIBRI"));

HFONT signSector = CreateFont(30, 0, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
	ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("CALIBRI"));

HFONT editFont = CreateFont(30, 0, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
	ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("CALIBRI"));

HWND edit;

constexpr auto OnClick_Continue = 1;
constexpr auto OnClick_Reset = 2;

LRESULT CALLBACK PasswordProc(HWND hwnd, UINT mas, WPARAM wp, LPARAM lp)
{
	switch (mas)
	{
	case WM_CREATE:
		Body(hwnd);
		break;

	case WM_CTLCOLORSTATIC:
		SetBkMode((HDC)wp, TRANSPARENT);
		SetTextColor((HDC)wp, RGB(255, 255, 255));

		return GetClassLongPtr(hwnd, GCL_HBRBACKGROUND);
		break;

	case WM_COMMAND:
		switch (wp)
		{
		case OnClick_Continue:
		{
			//const int _size = sizeof(edit);

			char PasswordItself[] = "Hello";

			char PasswordValue[100];

			GetWindowTextA(edit, PasswordValue, 100);

			if (strcmp(PasswordValue, PasswordItself) ==  0)
			{
				DestroyWindows(passwordWindow,NULL);
				check_value = false;
			}

			else {
				MessageBox(NULL, L"Wrong Password", L"Incorrect Password", MB_OK);
			}
		}
			break;
		case OnClick_Reset:
		{
			if (MessageBox(NULL, L"Dear user, please be informed that by clicking on the reset button the password window will be closed and the reset window will be opened.\n\nAlso note that after you have changed your password the window will be closed automatically, that proves your password was changed successfully.\n\nYou can click on Cancel to cancel this and use the existing password.\nIf you click OK there's no going back.",
				L"Info", MB_OKCANCEL | MB_ICONINFORMATION) == IDOK)
			{
				reset_value = true;
				DestroyWindow(passwordWindow);
			}
		}
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, mas, wp, lp);
		break;
	}

	return 0;
}

void Body(HWND hwnd)
{
	//Sign saying Password
	HWND Sign = CreateWindowEx(0, L"STATIC", L"INPUT PASSWORD", WS_CHILD | WS_VISIBLE, 55, 0, 300, 50, hwnd, NULL, NULL, NULL);
	SendMessage(Sign, WM_SETFONT, (WPARAM)Signfont, MAKELPARAM(TRUE, 0));

	//Border around password sector
	CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | SS_SUNKEN, 5, 70, 375, 50, hwnd, NULL, NULL, NULL);

	//Sign to show this is where you enter password
	HWND pword = CreateWindowEx(0, L"STATIC", L"Password:", WS_CHILD | WS_VISIBLE, 15, 80, 110, 30, hwnd, NULL, NULL, NULL);
	SendMessage(pword, WM_SETFONT, (WPARAM)signSector, MAKELPARAM(TRUE, 0));

	//Space for user to type password
	edit = CreateWindowEx(0, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | ES_PASSWORD | ES_AUTOHSCROLL, 138, 80, 230, 30, hwnd, NULL, NULL, NULL);
	SendMessage(edit, WM_SETFONT, (WPARAM)editFont, MAKELPARAM(TRUE, 0));

	/*
	* From this point you get the buttons that are used in the password system
	*/

	//Button for Reset
	HWND reset = CreateWindowEx(0, L"BUTTON", L"RESET", WS_CHILD | WS_VISIBLE | BS_FLAT, 0, 152, 110, 50, hwnd, (HMENU)OnClick_Reset, NULL, NULL);
	SendMessage(reset, WM_SETFONT, (WPARAM)editFont, MAKELPARAM(TRUE, 0));

	//Button for Continue
	HWND Continue = CreateWindowEx(0, L"BUTTON", L"CONTINUE", WS_CHILD | WS_VISIBLE | BS_FLAT, 271, 152, 113, 50, hwnd, (HMENU)OnClick_Continue,
		NULL, NULL);
	SendMessage(Continue, WM_SETFONT, (WPARAM)editFont, MAKELPARAM(TRUE, 0));
}
