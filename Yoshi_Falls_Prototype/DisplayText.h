//-----------------------------------------------------------------
// Display Text Class
// C++ Header - FontSelect.h
//-----------------------------------------------------------------

#ifndef DISPLAYTEXT_H
#define DISPLAYTEXT_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include <windows.h>
#include <math.h>
#include <stdio.h>



//-----------------------------------------------------------------
// Custom Data Types
//-----------------------------------------------------------------


//-----------------------------------------------------------------
// Font Class
//-----------------------------------------------------------------
class DisplayText
{

public:
	// General Methds
	static void Display_Text(HDC hDC,TCHAR szTEXT[164],LPCSTR fontName,int size, COLORREF TextColor,
		int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);
	static void Display_Timer(HDC hDC, float curElapsedTime, LPCSTR fontName, int size, COLORREF TextColor, 
		int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);
	
	//static void DisplayAlarm(HDC hDC, 
private:
	DisplayText();
	~DisplayText();
};
#endif