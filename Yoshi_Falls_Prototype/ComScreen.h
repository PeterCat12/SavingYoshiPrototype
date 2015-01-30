//-----------------------------------------------------------------
// Com Screen Object
// C++ Header - Yoshi Falls.h
//-----------------------------------------------------------------

#ifndef COMSCREEN_H
#define	COMSCREEN_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Sprite.h"
#include "BitmapPair.h"

//-----------------------------------------------------------------
// Com-Screen Class
//-----------------------------------------------------------------
enum SCREENSTATE
{
	SMALL,
	BIG
};

class ComScreen : public Sprite
{
protected:
	// Member Variables
	SCREENSTATE m_eScreenState;
	BitmapPair* m_pBitmapPair;

public:
	// Constructor(s)/Destructor
	ComScreen(Bitmap* pSmallBitmap,Bitmap* pBigBitmap, int iNumFrames, SCREENSTATE state);  //Should make this private?
    ComScreen(Bitmap* pSmallBitmap,Bitmap* pBigBitmap, int iNumFrames, RECT& rcBounds,
		SCREENSTATE state, BOUNDSACTION baBoundsAction = BA_STOP);
    ComScreen(Bitmap* pSmallBitmap, Bitmap* pBigBitmap,int iNumFrames, POINT ptPosition, POINT ptVelocity, int iZOrder,
		RECT& rcBounds,SCREENSTATE state, BOUNDSACTION baBoundsAction = BA_STOP);
	virtual ~ComScreen();

	// General Methods
	virtual SPRITEACTION  Update();  //Mess with this update function in order to set cycle through delays, etc
	//void				  SwapBitmap(Bitmap* bitmap);

	// Accessor Methods
	void setScreenState(SCREENSTATE state) { m_eScreenState = state; }
	SCREENSTATE getScreenState() { return m_eScreenState; }
	void setBitmapPair(BitmapPair& pBitmapPair) { m_pBitmapPair = &pBitmapPair; }
	BitmapPair* getBitmapPair() {return m_pBitmapPair;}
};

#endif