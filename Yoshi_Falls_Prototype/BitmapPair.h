//-----------------------------------------------------------------
// BitmapPair Object
// C++ Header - Yoshi Falls.h
//-----------------------------------------------------------------

#ifndef BITMAP_PAIR_H
#define	BITMAP_PAIR_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Bitmap.h"

//-----------------------------------------------------------------
//Bitmap Pair Class
//-----------------------------------------------------------------

class BitmapPair
{
protected:
	// Member variables
	Bitmap* m_pbSmall;
	Bitmap*	m_pbBig;
	int m_iNumFrames;

public:

	// Constructor(s)/Destructor
	BitmapPair(Bitmap* pSmall, Bitmap* pBig, int iNumFrames);
	~BitmapPair(); //Should destrucotr alert the BM manager to delete these guy when I'm done? 

	// General Methods --None Needed right now

	// Accessor Methods
	Bitmap* GetSmall() {return m_pbSmall;}
	Bitmap*	GetBig() {return m_pbBig;}		
	int		getNumFrames() {return m_iNumFrames;}

private:
	//Prevent default constructor use
	BitmapPair();

};
#endif