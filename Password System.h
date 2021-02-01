#pragma once

#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#include <Windows.h>
#include <stdlib.h>

LRESULT CALLBACK PasswordProc(HWND, UINT, WPARAM, LPARAM);

bool check_value = true;
HWND passwordWindow,resetMain;

void Body(HWND);
void Reset(HINSTANCE);
void ResetWindow(HWND);
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

	Reset(instance);

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
				DestroyWindows(passwordWindow, resetMain);
				check_value = false;
			}

			else {
				MessageBox(NULL, L"Wrong Password", L"Incorrect Password", MB_OK);
			}
		}
			break;
		case OnClick_Reset:
		{
			ResetWindow(hwnd);
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
	CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 5, 70, 375, 50, hwnd, NULL, NULL, NULL);

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
	HWND reset = CreateWindowEx(0, L"BUTTON", L"RESET", WS_CHILD | WS_VISIBLE | BS_FLAT, 5, 150, 110, 50, hwnd, (HMENU)OnClick_Reset, NULL, NULL);
	SendMessage(reset, WM_SETFONT, (WPARAM)editFont, MAKELPARAM(TRUE, 0));

	//Button for Continue
	HWND Continue = CreateWindowEx(0, L"BUTTON", L"CONTINUE", WS_CHILD | WS_VISIBLE | BS_FLAT, 267, 150, 113, 50, hwnd, (HMENU)OnClick_Continue,
		NULL, NULL);
	SendMessage(Continue, WM_SETFONT, (WPARAM)editFont, MAKELPARAM(TRUE, 0));
}


/*
* This part handles the reset button.
* 
* Whenever the reset button is pushed, everything in there begins to function from here.
* All the designs of the reset window and it's functions as well as linking it with the main password system will be done from here.
*/

//Reset window procedure
LRESULT CALLBACK ResetProc(HWND, UINT, WPARAM, LPARAM);

//Main Entry and Registration of Reset window.
void Reset(HINSTANCE ResetInstance)
{
	WNDCLASS reset = {};

	reset.hbrBackground = CreateSolidBrush(RGB(0, 0, 39));
	reset.hCursor = LoadCursor(NULL, IDC_ARROW);
	reset.hInstance = ResetInstance;
	reset.lpfnWndProc = ResetProc;
	reset.lpszClassName = L"ResetName";

	RegisterClass(&reset);

	MSG resetmsg = {};

	while (GetMessage(&resetmsg, NULL, 0, 0))
	{
		TranslateMessage(&resetmsg);
		DispatchMessage(&resetmsg);
	}
}

void ResetWindow(HWND resethwnd)
{
	resetMain = CreateWindowEx(0, L"ResetName", L"Reset Password", WS_MINIMIZEBOX | WS_VISIBLE | WS_SYSMENU, 400, 200, 400, 500,
		resethwnd, NULL, NULL, NULL);
	EnableWindow(passwordWindow, false);
}

LRESULT CALLBACK ResetProc(HWND resethandle, UINT resetmassage, WPARAM resetWp, LPARAM resetLp)
{
	switch (resetmassage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		EnableWindow(passwordWindow, true);
		break;
	default:
		return DefWindowProc(resethandle, resetmassage, resetWp, resetLp);
		break;
	}

	return 0;
}
