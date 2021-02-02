#pragma once

#include "Mian App.h"


/*
* This part handles the reset button.
*
* Whenever the reset button is pushed, everything in there begins to function from here.
* All the designs of the reset window and it's functions as well as linking it with the main password system will be done from here.
*/

HWND resetMain;

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

	resetMain = CreateWindowEx(0, L"ResetName", L"Reset Password", WS_MINIMIZEBOX | WS_VISIBLE | WS_SYSMENU, 400, 200, 400, 500,
		NULL, NULL, ResetInstance, NULL);

	MSG resetmsg = {};

	while (GetMessage(&resetmsg, NULL, 0, 0))
	{
		TranslateMessage(&resetmsg);
		DispatchMessage(&resetmsg);
	}
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
