//-----------------------------------------------------------------
// Bitmap Pair Object
// C++ Source - BitmapPair.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "BitmapPair.h"

//-----------------------------------------------------------------
// BitmapPair Constructor(s)/Destructor
//-----------------------------------------------------------------
BitmapPair::BitmapPair(Bitmap* pSmall, Bitmap* pBig, int iNumFrames)
{
	m_pbSmall = pSmall;
	m_pbBig = pBig;
	m_iNumFrames = iNumFrames;
}

BitmapPair::~BitmapPair()
{
}
