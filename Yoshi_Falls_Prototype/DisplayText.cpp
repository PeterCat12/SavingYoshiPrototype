//-----------------------------------------------------------------
// DisplayText Object
// C++ Source - DrawText.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "DisplayText.h"

enum TextSize
{
	TEXT_SIZE = 164
};

//-----------------------------------------------------------------
// Constructor(s) / Destructors
//-----------------------------------------------------------------
DisplayText::DisplayText()
{
}

DisplayText::~DisplayText()
{
}

//-----------------------------------------------------------------
// Static Methods
//-----------------------------------------------------------------

void DisplayText::Display_Text(HDC hDC,TCHAR szTEXT[TEXT_SIZE],LPCSTR fontName, int size, COLORREF TextColor,
							   int topLeftX, int topLeftY, int bottomRightX, int bottomRightY)
{
	HFONT hf;
    long lfHeight;
    lfHeight = -MulDiv(size, GetDeviceCaps(hDC, LOGPIXELSY), 72);

	hf = CreateFont(lfHeight, 0, 0, 0, 0, FALSE, 0, 0, 0, 0, 0, 0, 0, fontName);

	HFONT hfOldFont = (HFONT) SelectObject(hDC, hf);
	// Sample Text Draw?z=
	TCHAR szTEXT_TO_DRAW[TEXT_SIZE];
	//RECT rect = {106, 540, 1174, 670};
	RECT drawRect = {topLeftX, topLeftY, bottomRightX, bottomRightY};

	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, TextColor );

	wsprintf(szTEXT_TO_DRAW, szTEXT);
	DrawText(hDC,szTEXT_TO_DRAW, -1, &drawRect, DT_WORDBREAK | DT_CENTER | DT_VCENTER ); 

	SelectObject(hDC, hfOldFont);
	DeleteObject(hf);
}

void DisplayText::Display_Timer(HDC hDC, float curElapsedTime,LPCSTR fontName, int size, COLORREF TextColor, 
		int topLeftX, int topLeftY, int bottomRightX, int bottomRightY)
{

	//float totalSeconds = (float) t2/CLOCKS_PER_SEC;
		float totalMilliseconds = curElapsedTime * (float) 60; 

		int minutes = (int) floor(curElapsedTime / 60);
		int seconds = (int) curElapsedTime - (minutes*60);
		int miliseconds = (int) totalMilliseconds - (minutes * 3600) - (seconds * 60);

		int timeMin = 5 - minutes;
		int timeSec = 60 - seconds;
		int timeMili = 60 - miliseconds;

		CHAR szTEXT[TEXT_SIZE];
		sprintf_s(szTEXT,TEXT_SIZE,"%d:%d:%d", timeMin,timeSec,timeMili);
		DisplayText::Display_Text(hDC,szTEXT,fontName,size,TextColor,topLeftX,topLeftY, bottomRightX,bottomRightY);
}