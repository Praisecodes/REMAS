#pragma once

#include "Mian App.h"


/*
* This part handles the reset button.
*
* Whenever the reset button is pushed, everything in there begins to function from here.
* All the designs of the reset window and it's functions as well as linking it with the main password system will be done from here.
*/

//Reset window procedure
LRESULT CALLBACK ResetProc(HWND, UINT, WPARAM, LPARAM);
HWND resetMain;

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

	resetMain = CreateWindowEx(WS_EX_CLIENTEDGE, L"ResetName", L"Reset Password", WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU, 400, 200, 400, 500,
		NULL, NULL, ResetInstance, NULL);

	MSG resetmsg = {};

	while (GetMessage(&resetmsg, NULL, 0, 0))
	{
		TranslateMessage(&resetmsg);
		DispatchMessage(&resetmsg);
	}
}

void BodyReset(HWND);

HFONT resetSign = CreateFont(40, 20, 0, 0, FW_EXTRABOLD, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
	CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("CALIBRI"));

HFONT Signs = CreateFont(30, 15, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
	CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("CALIBRI"));

HFONT Spaces = CreateFont(25, 13, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
	CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("CALIBRI"));

LRESULT CALLBACK ResetProc(HWND resethandle, UINT resetmassage, WPARAM resetWp, LPARAM resetLp)
{
	switch (resetmassage)
	{
		//To create a nicely colored button for my Reset Window
	case WM_DRAWITEM:
	{
		LPDRAWITEMSTRUCT lpds = (DRAWITEMSTRUCT*)resetLp;
		SIZE size;
		GetTextExtentPoint32A(lpds->hDC, "Set Password", strlen("Set Password"), &size);
		SetTextColor(lpds->hDC, RGB(255, 255, 255));
		SetBkColor(lpds->hDC, RGB(0, 0, 160));
		ExtTextOutA(lpds->hDC, (lpds->rcItem.left + 8), (lpds->rcItem.top + 7), ETO_OPAQUE, &lpds->rcItem,
			"Set Password", strlen("Set Password"), NULL);

		DrawEdge(lpds->hDC, &lpds->rcItem, (lpds->itemState & ODS_SELECTED ? EDGE_RAISED : EDGE_SUNKEN), BF_RECT);

		return TRUE;
	}
		break;

	case WM_CTLCOLORSTATIC:
		SetBkMode((HDC)resetWp, TRANSPARENT);
		SetTextColor((HDC)resetWp, RGB(255, 255, 255));

		return GetClassLongPtr(resethandle, GCL_HBRBACKGROUND);
		break;

	case WM_CREATE:
		BodyReset(resethandle);
		break;

	case WM_COMMAND:
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(resethandle, resetmassage, resetWp, resetLp);
		break;
	}
	return 0;
}

void BodyReset(HWND hwnd)
{
	//Intro sign saying RESET PASSWORD and underlined
	HWND resetsign= CreateWindowEx(0, L"STATIC", L"RESET PASSWORD", WS_CHILD | WS_VISIBLE, 50, 0, 287, 40, hwnd, NULL, NULL, NULL);
	SendMessage(resetsign, WM_SETFONT, (WPARAM)resetSign, MAKELPARAM(TRUE, 0));

	//Sign saying Input former password
	HWND fpword = CreateWindowEx(0, L"STATIC", L"Input former password", WS_CHILD | WS_VISIBLE, 50, 60, 270, 40, hwnd, NULL, NULL, NULL);
	SendMessage(fpword, WM_SETFONT, (WPARAM)Signs, MAKELPARAM(TRUE, 0));
	
	//Space to input former password
	HWND fpwordEdit = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE, 28, 100, 330, 30, hwnd, NULL, NULL, NULL);
	SendMessage(fpwordEdit, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Sign saying Input new password
	HWND npword = CreateWindowEx(0, L"STATIC", L"Input new password", WS_CHILD | WS_VISIBLE, 60, 160, 270, 40, hwnd, NULL, NULL, NULL);
	SendMessage(npword, WM_SETFONT, (WPARAM)Signs, MAKELPARAM(TRUE, 0));

	//Space to input new password
	HWND npwordEdit = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE, 28, 200, 330, 30, hwnd, NULL, NULL, NULL);
	SendMessage(npwordEdit, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Sign saying Confirm new password
	HWND npwordCon = CreateWindowEx(0, L"STATIC", L"Confirm new password", WS_CHILD | WS_VISIBLE, 50, 270, 270, 40, hwnd, NULL, NULL, NULL);
	SendMessage(npwordCon, WM_SETFONT, (WPARAM)Signs, MAKELPARAM(TRUE, 0));

	//Space to confirm new password
	HWND npwordEditCon = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE, 28, 310, 330, 30, hwnd, NULL, NULL, NULL);
	SendMessage(npwordEditCon, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Button to finalize the password reset
	HWND setbutton = CreateWindowEx(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | BS_FLAT, 233, 421, 150, 40, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd,GWLP_HINSTANCE),
		NULL);
	SendMessage(setbutton, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));
}
