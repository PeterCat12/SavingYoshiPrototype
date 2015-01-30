//-----------------------------------------------------------------
// ComScreen Object
// C++ Source - Sprite.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "ComScreen.h"

//-----------------------------------------------------------------
// ComScreen Constructor(s)/Destructor
//-----------------------------------------------------------------
ComScreen::ComScreen(Bitmap* pSmallBitmap,Bitmap* pBigBitmap,int iNumFrames, SCREENSTATE state)
	: Sprite( state == BIG ? pBigBitmap : pSmallBitmap)
{
	m_pBitmapPair = new BitmapPair(pSmallBitmap, pBigBitmap, iNumFrames);
	SetNumFrames(iNumFrames);
}

ComScreen::ComScreen(Bitmap* pSmallBitmap,Bitmap* pBigBitmap, int iNumFrames, RECT& rcBounds,  SCREENSTATE state, BOUNDSACTION baBoundsAction)
	: Sprite( state == BIG ? pBigBitmap : pSmallBitmap, rcBounds, baBoundsAction)
{
	m_pBitmapPair = new BitmapPair(pSmallBitmap, pBigBitmap, iNumFrames);
	SetNumFrames(iNumFrames);
}

ComScreen::ComScreen(Bitmap* pSmallBitmap, Bitmap* pBigBitmap, int iNumFrames, POINT ptPosition, POINT ptVelocity, int iZOrder,
		RECT& rcBounds,SCREENSTATE state, BOUNDSACTION baBoundsAction)
	: Sprite(state == BIG ? pBigBitmap : pSmallBitmap, ptPosition, ptVelocity, iZOrder, rcBounds, baBoundsAction)
{
	m_pBitmapPair = new BitmapPair(pSmallBitmap, pBigBitmap, iNumFrames);
	SetNumFrames(iNumFrames);
}

ComScreen::~ComScreen()
{
}

//-----------------------------------------------------------------
// ComSCreen General Methods
//-----------------------------------------------------------------

SPRITEACTION ComScreen::Update()
{
	return Sprite::Update();
}


//void ComScreen::SwapBitmap(Bitmap* pBitmap)
//{
//}