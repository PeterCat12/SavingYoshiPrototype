//-----------------------------------------------------------------
// Yoshi Falls Application
// C++ Source - YoshiFalls.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "YoshiFalls.h"


//-----------------------------------------------------------------
// GameEngine Functions
//-----------------------------------------------------------------

BOOL GameInitialize(HINSTANCE hInstance)
{
	// Create the game engine
	// this is where I also create the width and height?
	g_pGame = new GameEngine(hInstance, TEXT("Yoshi Falls"),
		TEXT("Yoshi Falls"), NULL, NULL, 1280, 720);
	if(g_pGame == NULL)
		return FALSE;
	
	// Set the frame rate
	g_pGame->SetFrameRate(15);

	// Store the instance handle
	g_hInstance = hInstance;

	return TRUE;
}

void GameStart(HWND hWindow)
{
	// Seed the random number generator
	srand(GetTickCount());

	// Create the offscreen device context and bitmap
	g_hOffscreenDC = CreateCompatibleDC(GetDC(hWindow));
	g_hOffscreenBitmap = CreateCompatibleBitmap(GetDC(hWindow),
		g_pGame->GetWidth(), g_pGame->GetHeight());
	SelectObject(g_hOffscreenDC, g_hOffscreenBitmap);

	// Create the sound engine:
	//g_pSndEngine = irrklang::createIrrKlangDevice();
	//g_pSndTheme = g_pSndEngine->play2D("Theme.mp3",true,false,true);
	///g_pSndTheme->setVolume(0.5); 
	AudioMan::getSoundEngine()->play2D("Theme.mp3",true,false,false);
	AudioMan::getSoundEngine()->setSoundVolume(0.5);

	// Create and load the bitmaps
	HDC hDC = GetDC(hWindow);
	// only Loading the background right now...
	//Bitmap manager
	
	g_pBackground = new Bitmap(hDC, IDB_MainControlBackground, g_hInstance);
	g_pMainScreenBitmapBig = new Bitmap(hDC,IDB_BIGPILOT, g_hInstance);
	g_pMainScreenBitmapSmall = new Bitmap(hDC, IDB_SMALLPILOT, g_hInstance);
	g_pTopLeftBitmapSmall = new Bitmap(hDC, IDB_SMALLPOSITIVE, g_hInstance);
	g_pTopLeftBitmapBig = new Bitmap(hDC, IDB_BIGPOSITIVE, g_hInstance);
	g_pTopRightBitmapSmall = new Bitmap(hDC, IDB_SMALLNEGATIVE, g_hInstance);
	g_pTopRightBitmapBig  = new Bitmap(hDC, IDB_BIGNEGATIVE, g_hInstance);

	g_pGame->AddBitmap(*g_pBackground);  //Too ridiculous of a function call?
	g_pGame->AddBitmap(*g_pMainScreenBitmapBig);
	g_pGame->AddBitmap(*g_pMainScreenBitmapSmall);
	g_pGame->AddBitmap(*g_pTopLeftBitmapSmall);
	g_pGame->AddBitmap(*g_pTopLeftBitmapBig);
	g_pGame->AddBitmap(*g_pTopRightBitmapSmall);
	g_pGame->AddBitmap(*g_pTopRightBitmapBig);

	g_pComScreenMan = new ComScreenMan();

	RECT    rcBounds = { 0, 0, 1280, 720 };
	g_pScreen0 = new ComScreen(g_pMainScreenBitmapSmall,g_pMainScreenBitmapBig, 48, rcBounds, BIG);
//	g_pScreen0 = new ComScreen(g_pTopLeftBitmapSmall,g_pTopLeftBitmapBig, 48, rcBounds, BIG);

	//g_pScreen0->SetNumFrames(48);
	g_pScreen0->SetFrameDelay(0);
	g_pScreen0->SetPosition(640 - (g_pScreen0->GetWidth()/2),30);
	g_pScreen0->SetZOrder(2);
	g_pScreen0->SetHidden(FALSE);
	g_pComScreenMan->AddScreen(g_pScreen0,CENTER);
	g_pGame->AddSprite(g_pScreen0);
	//Add two more screens, With the same parameters,  
	RECT newBounds = {-1000, -1000, 3000, 3000};
	g_pScreen1 = new ComScreen(g_pTopLeftBitmapSmall,g_pTopLeftBitmapBig, 44, newBounds, SMALL); // Test out what happens when you leave off bounding rectangle... 
	//g_pScreen1->SetNumFrames(44);
	g_pScreen1->SetFrameDelay(0);
	g_pScreen1->SetPosition(42,50); //Right along the wall?
	g_pScreen1->SetZOrder(2);
	g_pScreen1->SetHidden(FALSE);
	g_pComScreenMan->AddScreen(g_pScreen1,TOP_LEFT);
	g_pGame->AddSprite(g_pScreen1);

	g_pScreen2 = new ComScreen(g_pTopRightBitmapSmall,g_pTopRightBitmapBig,58, newBounds, SMALL); // Test out what happens when you leave off bounding rectangle... 
	//g_pScreen2->SetNumFrames(58);
	g_pScreen2->SetFrameDelay(0);
	g_pScreen2->SetPosition(982,50); 
	g_pScreen2->SetZOrder(2);
	g_pScreen2->SetHidden(FALSE);
	g_pComScreenMan->AddScreen(g_pScreen2, TOP_RIGHT);
	g_pGame->AddSprite(g_pScreen2);

	Timer::StartClock();

}

void GameEnd()
{
	// Close the MIDI player for the background music
	g_pGame->CloseMIDIPlayer();

	// Cleanup the offscreen device context and bitmap
	DeleteObject(g_hOffscreenBitmap);
	DeleteDC(g_hOffscreenDC);
	
	//Clean up all bitmaps that have been put into it // Maybe addbitmap should be apart of the bm constructor?
	g_pGame->CleanupBitmaps();

	//Clean up the sprites  
	g_pGame->CleanupSprites();

	AudioMan::clear();
	AudioMan::drop();
	// Clean up the game engine
	delete g_pGame;
}

void GameActivate(HWND hWindow)
{
	// Resume the background music
	g_pGame->PlayMIDISong(TEXT(""), FALSE);
}

void GameDeactivate(HWND hWindow)
{
	// Pause the background music
	g_pGame->PauseMIDISong();
}

void GamePaint( HDC hDC)
{
	// Draw the background COM room
	g_pBackground->Draw(hDC, 0, 0);
	// Draw the sprites
	g_pGame->DrawSprites(hDC);

  	// Nothing else to draw yet
	
	//Draw debug areas where I want screens to go?
	HPEN hPen2 = CreatePen(PS_SOLID,5, RGB(255,0,255));
	HPEN hPen = (HPEN) SelectObject(hDC, hPen2);
	
	int sizeX, sizeY;
	sizeX = 600;
	sizeY = 480;

	//Rectangle(hDC, g_pGame->GetWidth()/2 -  sizeX/2, 30,(g_pGame->GetWidth()/2 -  sizeX/2) + sizeX , 30+sizeY);

	int sizeX2 = 256;
	int sizeY2 = 192;
	//Rectangle(hDC, 340/2 - sizeX2/2, 50, (340/2 - sizeX2/2) + sizeX2, 50 + sizeY2);

	//Bottom LEftScreen
	Rectangle(hDC, 340/2 - sizeX2/2, 298, (340/2 - sizeX2/2) + sizeX2, 298 + sizeY2);

	////TOP RIGHT
	//Rectangle(hDC, 1110 - sizeX2/2, 50, (1110 - sizeX2/2) + sizeX2, 50 + sizeY2);

	//BOTTOM RIGHT
	Rectangle(hDC, 1110 - sizeX2/2, 298, (1110 - sizeX2/2) + sizeX2, 298 + sizeY2);

	// Text Rectangle FOR FULL TEXT
	//Rectangle(hDC, 106, 540, 1174, 670);
	//	640 - (g_pScreen0->GetWidth()/2),50

	DeleteObject(hPen2);
	SelectObject(hDC, hPen);
	DisplayText::Display_Text(hDC,"This is a test. Nothing but a test! ANOTHER TEST ANOTHER TEST! ANOTHER TEST ANOTHER TEST! This is a test. Nothing but a test! ANOTHER TEST ANOTHER TEST!",
		"Digital-7",20,RGB(255,255,255), 106, 540, 1174, 670 ); 
	//DisplayText::Display_Text(hDC,"1:00:00","Digital-7",20,RGB(255,0,0),850,50,940,80);
	DisplayText::Display_Timer(hDC,Timer::TimeDifference(), "Digital-7",12,RGB(255,0,0),850,50,940,80);
	//_trace("This is just a test: %f\n", Timer::TimeDifference());

	float secondsPassed = Timer::TimeDifference();
}

void GameCycle()
{

	// Update the sprites
	g_pGame->UpdateSprites();

	// Obtain a device context for repainting the game
	HWND hWindow = g_pGame->GetWindow();
	HDC hDC = GetDC(hWindow);

	// Paint the game to offscreen device context
	GamePaint(g_hOffscreenDC);

	// Blit the offscreen bitmap to the game screen
	BitBlt(hDC, 0, 0, g_pGame->GetWidth(), g_pGame->GetHeight(),
		g_hOffscreenDC, 0, 0, SRCCOPY);

	// Cleanup
	ReleaseDC(hWindow, hDC);
}

void HandleKeys()
{
}

void MouseButtonDown(int x, int y, BOOL bLeft)
{
}

void MouseMove(int x, int y)
{
}

void MouseButtonUp(int x, int y, BOOL bLeft)
{
	//I just want to iterate through all the comScreens...
	if (g_pComScreenMan->isPointInComScreen(x,y) != 0)
	{
		 ComScreen* pScreen = g_pComScreenMan->isPointInComScreen(x,y);
		 int x = rand() % 3;
		 if(x == 0)
		{	//PlaySound((LPCSTR)IDW_SCREENSELECT, g_hInstance, SND_ASYNC | SND_RESOURCE);
				//g_pSndScreenSelect = g_pSndEngine->play2D("ScreenSwitch.wav",false,false,true);
				//g_pSndScreenSelect->setVolume(0.5); 
			AudioMan::getSoundEngine()->play2D("ScreenSwitch.wav", false,false,false);
		}		
		 else if(x == 1)
	 	{
				 //PlaySound((LPCSTR)IDW_SCREENSELECT2, g_hInstance, SND_ASYNC | SND_RESOURCE);
			AudioMan::getSoundEngine()->play2D("ScreenSwitch2.wav", false,false,false);
		}
		 else
		{
			 //PlaySound((LPCSTR)IDW_SCREENSELECT3, g_hInstance, SND_ASYNC | SND_RESOURCE);
			AudioMan::getSoundEngine()->play2D("ScreenSwitch3.wav", false,false,false);
		}
	g_pComScreenMan->BecomeMainScreen(pScreen);  //This is where things might go fucking haywire
	}
}

void HandleJoystick(JOYSTATE jsJoystickState)
{
}

BOOL SpriteCollision(Sprite* pSpriteHitter, Sprite* pSpriteHittee)
{
  return FALSE;
}

void SpriteDying(Sprite* pSpriteDying)
{
}