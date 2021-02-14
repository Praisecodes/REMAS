#pragma once

#include <string>
#include "WinBuCom.h"
#include "resource.h"

LRESULT CALLBACK mainProc(HWND, UINT, WPARAM, LPARAM);
void Buttons(HWND);
void Statics(HWND);
void ItemNumberPicks(HWND);
void ItemAmounts(HWND);
HWND RemasApp;


int calculations = 0;
int Answer = 0;

constexpr auto TotalClick = 22;
constexpr auto MenuClick = 23;
constexpr auto PurClick = 24;
constexpr auto ClearClick = 25;

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
	main.hIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(MAKEICON), IMAGE_ICON, 100, 100, 0);

	RegisterClass(&main);

	RemasApp = CreateWindowEx(0, L"mainName", L"Remas 1.0.0", WS_MINIMIZEBOX | WS_SYSMENU | WS_VISIBLE, 0, 0, WIDTH, HEIGHT,
		RemasApp, NULL, hinstancef, NULL);

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
		ItemNumberPicks(hwnd2);
		ItemAmounts(hwnd2);
		break;

	case WM_DRAWITEM:
	{
		LPDRAWITEMSTRUCT lpds = (DRAWITEMSTRUCT*)lp2;
		if (lpds->hwndItem == buttonClear)
		{
			SIZE size;
			GetTextExtentPoint32A(lpds->hDC, "CLEAR", strlen("CLEAR"), &size);
			SetTextColor(lpds->hDC, RGB(255, 255, 255));
			SetBkColor(lpds->hDC, RGB(0, 0, 160));
			ExtTextOutA(lpds->hDC, (lpds->rcItem.left + 10), (lpds->rcItem.top + 7), ETO_OPAQUE, &lpds->rcItem,
				"CLEAR", strlen("CLEAR"), NULL);
		}

		if (lpds->hwndItem == buttonMenu)
		{
			SIZE size;
			GetTextExtentPoint32A(lpds->hDC, "MENU", strlen("MENU"), &size);
			SetTextColor(lpds->hDC, RGB(255, 255, 255));
			SetBkColor(lpds->hDC, RGB(0, 0, 160));
			ExtTextOutA(lpds->hDC, (lpds->rcItem.left + 14), (lpds->rcItem.top + 5), ETO_OPAQUE, &lpds->rcItem,
				"MENU", strlen("MENU"), NULL);
		}

		if (lpds->hwndItem == buttonPurchase)
		{
			SIZE size;
			GetTextExtentPoint32A(lpds->hDC, "PURCHASE", strlen("PURCHASE"), &size);
			SetTextColor(lpds->hDC, RGB(255, 255, 255));
			SetBkColor(lpds->hDC, RGB(0, 0, 160));
			ExtTextOutA(lpds->hDC, (lpds->rcItem.left + 7), (lpds->rcItem.top + 5), ETO_OPAQUE, &lpds->rcItem,
				"PURCHASE", strlen("PURCHASE"), NULL);
		}

		if (lpds->hwndItem == buttonTotal)
		{
			SetTextColor(lpds->hDC, RGB(255, 255, 255));
			SetBkColor(lpds->hDC, RGB(0, 0, 160));
			ExtTextOutA(lpds->hDC, (lpds->rcItem.left + 10), (lpds->rcItem.top + 7), ETO_OPAQUE, &lpds->rcItem,
				"TOTAL", strlen("TOTAL"), NULL);
		}

		if (lpds->hwndItem == hold || lpds->hwndItem == holder || lpds->hwndItem == holds)
		{
			SetBkMode(lpds->hDC, TRANSPARENT);
		}

		if (lpds->hwndItem == hold1)
		{
			SetBkMode(lpds->hDC, TRANSPARENT);
			SetTextColor(lpds->hDC, RGB(255, 255, 255));
			ExtTextOutA(lpds->hDC, (lpds->rcItem.left + 100), (lpds->rcItem.top + 10),0, &lpds->rcItem, "ITEMS", strlen("ITEMS"), NULL);
		}

		if (lpds->hwndItem == hold2)
		{
			SetBkMode(lpds->hDC, TRANSPARENT);
			SetTextColor(lpds->hDC, RGB(255, 255, 255));
			ExtTextOutA(lpds->hDC, (lpds->rcItem.left + 100), (lpds->rcItem.top + 10), 0, &lpds->rcItem, "PRICES", strlen("PRICES"), NULL);
		}

		if (lpds->hwndItem == hold3)
		{
			SetBkMode(lpds->hDC, TRANSPARENT);
			SetTextColor(lpds->hDC, RGB(255, 255, 255));
			ExtTextOutA(lpds->hDC, (lpds->rcItem.left + 60), (lpds->rcItem.top + 10), 0, &lpds->rcItem, "NO. OF ITEMS",
				strlen("NO. OF ITEMS"), NULL);
		}

		if (lpds->hwndItem == TotalSign)
		{
			SetBkMode(lpds->hDC, TRANSPARENT);
			SetTextColor(lpds->hDC, RGB(255, 255, 255));
			ExtTextOutA(lpds->hDC, (lpds->rcItem.left + 10), (lpds->rcItem.top + 5), 0, &lpds->rcItem, "TOTAL:",
				strlen("TOTAL:"), NULL);
		}

		if (lpds->hwndItem == SubTotalSign)
		{
			SetBkMode(lpds->hDC, TRANSPARENT);
			SetTextColor(lpds->hDC, RGB(255, 255, 255));
			ExtTextOutA(lpds->hDC, (lpds->rcItem.left + 10), (lpds->rcItem.top + 5), 0, &lpds->rcItem, "SUB-TOTAL:",
				strlen("SUB-TOTAL:"), NULL);
		}

		DrawEdge(lpds->hDC, &lpds->rcItem, (lpds->itemState & ODS_SELECTED ? EDGE_BUMP : EDGE_SUNKEN), BF_SOFT);
		return TRUE;
	}
		break;

	case WM_COMMAND:
		switch (wp2)
		{
		//Handling commands for calculator buttons start here
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
			char outting[100];
			GetWindowTextA(Screen, outting, 100);

			SetWindowTextA(ResultScreen, outting);
		}
			break;
		//Handling commands for calculator buttons end here

		//Handling commands for other buttons in the main window
		case ClearClick:
		{
			Clear();
		}
			break;

		case TotalClick:
		{
			Total();
		}
			break;

		case PurClick:
		{
			Purchase();
		}
			break;

		case MenuClick:
		{
			Menu();
		}
			break;

		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		check_value = true;
		break;

	default:
		/*
		* This code is to check if the value set in the total is zero.
		* If the value is zero then the clear button is disabled and cannot be used,
		* but once the value is greater than zero then the clear button is enabled.
		*/
		char TotalSpaceCheck[1000];
		GetWindowTextA(totalSpace, TotalSpaceCheck, 1000);
		if (strcmp(TotalSpaceCheck, "0") == 0)
		{
			EnableWindow(buttonClear, false);
		}
		else {
			EnableWindow(buttonClear, true);
		}

		/*
		* This checks if there's anything on the calculator screen.
		* If there's nothing on the calculator screen then the equal button is disabled so as to prevent crashing of the system.
		*/
		char CalcCheck[1000];
		GetWindowTextA(Screen, CalcCheck, 1000);
		if (strcmp(CalcCheck, "") == 0)
		{
			EnableWindow(equal, false);
		}
		else {
			EnableWindow(equal, true);
		}

		//This is simply for the system to handle all other window messages not handled by me, example: Making the window visible.
		return DefWindowProc(hwnd2, mas2, wp2, lp2);
		break;
	}

	return 0;
}

void Buttons(HWND hwnd)
{
	//Button saying CLEAR
	buttonClear = CreateWindowEx(0, L"BUTTON", L"CLEAR", WS_CHILD | WS_VISIBLE | BS_FLAT | BS_OWNERDRAW, 1000, 688, 120, 40,
		hwnd, (HMENU)ClearClick, (HINSTANCE)GetWindowLong(hwnd,GWLP_HINSTANCE), NULL);
	SendMessage(buttonClear, WM_SETFONT, (WPARAM)buttons, MAKELPARAM(TRUE, 0));

	//Button saying TOTAL
	buttonTotal = CreateWindowEx(0, L"BUTTON", L"TOTAL", WS_CHILD | WS_VISIBLE | BS_FLAT | BS_OWNERDRAW, 1170, 688, 120, 40,
		hwnd, (HMENU)TotalClick, (HINSTANCE)GetWindowLong(hwnd,GWLP_HINSTANCE), NULL);
	SendMessage(buttonTotal, WM_SETFONT, (WPARAM)buttons, MAKELPARAM(TRUE, 0));

	//Button saying PURCHASE
	buttonPurchase = CreateWindowEx(0, L"BUTTON", L"PURCHASE", WS_CHILD | WS_VISIBLE | BS_FLAT | BS_OWNERDRAW, 770, 610, 180, 40,
		hwnd, (HMENU)PurClick, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(buttonPurchase, WM_SETFONT, (WPARAM)buttons, MAKELPARAM(TRUE, 0));

	//Button saying MENU
	buttonMenu = CreateWindowEx(0, L"BUTTON", L"MENU", WS_CHILD | WS_VISIBLE | BS_FLAT | BS_OWNERDRAW, 20, 20, 120, 40,
		hwnd, (HMENU)MenuClick, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(buttonMenu, WM_SETFONT, (WPARAM)buttons, MAKELPARAM(TRUE, 0));
}

void Statics(HWND hwnd)
{
	//This is the control under ITEMS
	hold = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_OWNERDRAW | WS_BORDER, 160, 150, 267, 450, hwnd, NULL,
		(HINSTANCE)GetWindowLong(hwnd,GWLP_HINSTANCE), NULL);

	//This is the control that holds the Title ITEMS
	hold1 = CreateWindowEx(0, L"STATIC", L"ITEMS", WS_CHILD | WS_VISIBLE | SS_OWNERDRAW | WS_BORDER, 160, 100, 267, 50, hwnd, NULL,
		(HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(hold1, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//This is the control under PRICES
	holder = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_OWNERDRAW | WS_BORDER, 427, 150, 267, 450, hwnd, NULL,
		(HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);

	//This is the control that holds the Title PRICES
	hold2 = CreateWindowEx(0, L"STATIC", L"PRICES", WS_CHILD | WS_VISIBLE | SS_OWNERDRAW | WS_BORDER, 427, 100, 267, 50, hwnd, NULL,
		(HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(hold2, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//This is the control under NO. OF ITEMS
	holds = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_OWNERDRAW | WS_BORDER, 694, 150, 266, 450, hwnd, NULL,
		(HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);

	//This is the control that holds the Title NO. OF ITEMS
	hold3 = CreateWindowEx(0, L"STATIC", L"NO. OF ITEMS", WS_CHILD | WS_VISIBLE | SS_OWNERDRAW | WS_BORDER, 694, 100, 266, 50, hwnd, NULL,
		(HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(hold3, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//This is the sign saying TOTAL:
	TotalSign = CreateWindowEx(0, L"STATIC", L"TOTAL:", WS_CHILD | WS_VISIBLE | SS_OWNERDRAW, 160, 688, 130, 40, hwnd, NULL,
		(HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(TotalSign, WM_SETFONT, (WPARAM)buttons, MAKELPARAM(TRUE, 0));

	//Space to show the total amount
	totalSpace = CreateWindowEx(0, L"EDIT", L"0", WS_CHILD | WS_VISIBLE | ES_READONLY | ES_AUTOHSCROLL | WS_BORDER | ES_RIGHT, 290, 688, 170,
		40, hwnd, NULL, NULL, NULL);
	SendMessage(totalSpace, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//This is the sign saying SUB-TOTAL:
	SubTotalSign = CreateWindowEx(0, L"STATIC", L"TOTAL:", WS_CHILD | WS_VISIBLE | SS_OWNERDRAW, 500, 688, 200, 40, hwnd, NULL,
		(HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(SubTotalSign, WM_SETFONT, (WPARAM)buttons, MAKELPARAM(TRUE, 0));

	//Space to show the sub-total amount
	subTotalSpace = CreateWindowEx(0, L"EDIT", L"0", WS_CHILD | WS_VISIBLE | ES_READONLY | ES_AUTOHSCROLL | WS_BORDER | ES_RIGHT, 700, 688, 170,
		40, hwnd, NULL, NULL, NULL);
	SendMessage(subTotalSpace, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));
}

void ItemNumberPicks(HWND hwnd)
{
	//Edit control for the first item
	Pick1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"0", WS_CHILD | WS_VISIBLE, 754, 180, 170, 30, hwnd, NULL, NULL, NULL);
	SendMessage(Pick1, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Edit control for the second item
	Pick2 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"0", WS_CHILD | WS_VISIBLE, 754, 250, 170, 30, hwnd, NULL, NULL, NULL);
	SendMessage(Pick2, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Edit control for the third item
	Pick3 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"0", WS_CHILD | WS_VISIBLE, 754, 320, 170, 30, hwnd, NULL, NULL, NULL);
	SendMessage(Pick3, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Edit control for the fourth item
	Pick4 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"0", WS_CHILD | WS_VISIBLE, 754, 390, 170, 30, hwnd, NULL, NULL, NULL);
	SendMessage(Pick4, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Edit control for the fifth item
	Pick5 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"0", WS_CHILD | WS_VISIBLE, 754, 460, 170, 30, hwnd, NULL, NULL, NULL);
	SendMessage(Pick5, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Edit control for the sixth item
	Pick6 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"0", WS_CHILD | WS_VISIBLE, 754, 530, 170, 30, hwnd, NULL, NULL, NULL);
	SendMessage(Pick6, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));
}

void ItemAmounts(HWND hwnd)
{

}
