#pragma once

#include "Password System.h"
#include "Reset.h"

HWND Screen, ResultScreen;
HWND one, two, three, four, five, six, seven, eight, nine, zero,plus,minus,divide,times,clear,bracketO,bracketC,equal,percent,dot;

void Calculator(HWND hwnd)
{
	//Static control to hold all elements of the calculator
	CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE, 1010, 100, 300, 500, hwnd, NULL, NULL, NULL);

	//Calculator screen
	Screen = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | SS_SUNKEN, 1010, 100, 300, 100, hwnd, NULL, NULL, NULL);

	//Screen for result
	ResultScreen = CreateWindowEx(0, L"STATIC", L"0", WS_CHILD | WS_VISIBLE | SS_RIGHT | SS_CENTERIMAGE, 1155, 155, 150, 40, hwnd, 
		NULL, NULL, NULL);
	SendMessage(ResultScreen, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Number 1 button in the calculator
	one = CreateWindowEx(0, L"BUTTON", L"1", WS_CHILD | WS_VISIBLE | BS_FLAT, 1010, 200, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(one, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Number 2 button in the calculator
	two = CreateWindowEx(0, L"BUTTON", L"2", WS_CHILD | WS_VISIBLE | BS_FLAT, 1085, 200, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(two, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Number 3 button in the calculator
	three = CreateWindowEx(0, L"BUTTON", L"3", WS_CHILD | WS_VISIBLE | BS_FLAT, 1160, 200, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(three, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//The addition (+) button in the calculator
	plus = CreateWindowEx(0, L"BUTTON", L"+", WS_CHILD | WS_VISIBLE | BS_FLAT, 1235, 200, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(plus, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Number 4 button in the calculator
	four = CreateWindowEx(0, L"BUTTON", L"4", WS_CHILD | WS_VISIBLE | BS_FLAT, 1010, 280, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(four, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Number 5 button in the calculator
	five = CreateWindowEx(0, L"BUTTON", L"5", WS_CHILD | WS_VISIBLE | BS_FLAT, 1085, 280, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(five, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Number 6 button in the calculator
	six = CreateWindowEx(0, L"BUTTON", L"6", WS_CHILD | WS_VISIBLE | BS_FLAT, 1160, 280, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(six, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//The subtraction (-) button in the calculator
	minus = CreateWindowEx(0, L"BUTTON", L"-", WS_CHILD | WS_VISIBLE | BS_FLAT, 1235, 280, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(minus, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Number 7 button in the calculator
	seven = CreateWindowEx(0, L"BUTTON", L"7", WS_CHILD | WS_VISIBLE | BS_FLAT, 1010, 360, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(seven, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Number 8 button in the calculator
	eight = CreateWindowEx(0, L"BUTTON", L"8", WS_CHILD | WS_VISIBLE | BS_FLAT, 1085, 360, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(eight, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Number 9 button in the calculator
	nine = CreateWindowEx(0, L"BUTTON", L"9", WS_CHILD | WS_VISIBLE | BS_FLAT, 1160, 360, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(nine, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//The multiplication (x) button in the calculator
	times = CreateWindowEx(0, L"BUTTON", L"x", WS_CHILD | WS_VISIBLE | BS_FLAT, 1235, 360, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(times, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//The percentage (%) button in the calculator
	percent = CreateWindowEx(0, L"BUTTON", L"%", WS_CHILD | WS_VISIBLE | BS_FLAT, 1010, 440, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(percent, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//Number 0 button in the calculator
	zero = CreateWindowEx(0, L"BUTTON", L"0", WS_CHILD | WS_VISIBLE | BS_FLAT, 1085, 440, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(zero, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//The decimal point (.) button in the calculator
	dot = CreateWindowEx(0, L"BUTTON", L".", WS_CHILD | WS_VISIBLE | BS_FLAT, 1160, 440, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(dot, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//The division (/) button in the calculator
	divide = CreateWindowEx(0, L"BUTTON", L"/", WS_CHILD | WS_VISIBLE | BS_FLAT, 1235, 440, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(divide, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//The clear (C) button in the calculator
	clear = CreateWindowEx(0, L"BUTTON", L"C", WS_CHILD | WS_VISIBLE | BS_FLAT, 1010, 520, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(clear, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//The opening bracket "(" button in the calculator
	bracketO = CreateWindowEx(0, L"BUTTON", L"(", WS_CHILD | WS_VISIBLE | BS_FLAT, 1085, 520, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(bracketO, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//The closing bracket ")" button in the calculator
	bracketC = CreateWindowEx(0, L"BUTTON", L")", WS_CHILD | WS_VISIBLE | BS_FLAT, 1160, 520, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(bracketC, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));

	//The equals (=) button in the calculator
	equal = CreateWindowEx(0, L"BUTTON", L"=", WS_CHILD | WS_VISIBLE | BS_FLAT, 1235, 520, 75, 80, hwnd, NULL, NULL, NULL);
	SendMessage(equal, WM_SETFONT, (WPARAM)Spaces, MAKELPARAM(TRUE, 0));
}
