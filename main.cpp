/*
* This is a resturant management system made by Praise Codes.
* This system algorithms was all thought out by Praise Codes and he is using Win32 API C++ to make this.
* 
* All the code in this app was written by Praise Codes and also thought out by him.
*/


//Including the file that has all other info needed for this app to function.
#include "Mian App.h"


/*
* This is the linkage between the main app and the password system.
* The code seen here is simply to link the main app and the password system.
* 
* You should find just conditional statements in this section, the main code was handled in Password System.h and Main App.h.
*/
//The main entry point for this program where everything is linked up to.
int WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR args, int nCmdShow)
{
	if (check_value == true)
	{
		PasswordSystem(hinst);
	}
	if (check_value == false)
	{
		MainApp(hinst);
	}
	return 0;
}
