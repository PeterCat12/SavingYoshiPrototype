//-----------------------------------------------------------------
// Yoshi Falls Application
// C++ Header - Yoshi Falls.h
//-----------------------------------------------------------------

#ifndef YOSHIFALLS_H
#define YOSHIFALLS_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include <windows.h>
#include "Resource.h"
#include "GameEngine.h"
#include "Bitmap.h"
#include "Sprite.h"
#include "ComScreen.h"
#include "ComScreenManager.h"
#include "AudioMan.h"
#include "DisplayText.h"
#include "Timer.h"
#include "Trace.h"

//-----------------------------------------------------------------
// Global Variabls
//-----------------------------------------------------------------
HINSTANCE		g_hInstance;
GameEngine*		g_pGame;
HDC				g_hOffscreenDC;
HBITMAP			g_hOffscreenBitmap;
//-----------------------------------------------------------------
// Bitmaps Used
//-----------------------------------------------------------------

Bitmap*			g_pBackground;
//Change this to an array possibly
Bitmap*			g_pMainScreenBitmapBig;
Bitmap*			g_pMainScreenBitmapSmall;
Bitmap*			g_pTopLeftBitmapSmall;
Bitmap*			g_pTopLeftBitmapBig;
Bitmap*			g_pTopRightBitmapSmall;
Bitmap*			g_pTopRightBitmapBig;

//Bitmap*			g_pBottomLeftBitmap;
//Bitmap*			g_pBottomRightBitmap;

// Maybe change this to array... 
ComScreen*		g_pScreen0;
ComScreen*		g_pScreen1;
ComScreen*		g_pScreen2;
//ComScreen*		g_pScreen3;
//ComScreen*		g_pScreen4;

ComScreenMan*	g_pComScreenMan;

//-----------------------------------------------------------------
// Sound Engine Irrklang
//-----------------------------------------------------------------

#endif