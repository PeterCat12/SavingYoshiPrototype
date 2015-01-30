//-----------------------------------------------------------------
// Bitmap Manager
// C++ Source - Bitmap.h
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "BitmapManager.h"

//-----------------------------------------------------------------
// Sprite Constructor(s)/Destructor
//-----------------------------------------------------------------
BitmapManager::BitmapManager()
{
}

BitmapManager::~BitmapManager()
{
	m_pBitmaps.clear();
}

//-----------------------------------------------------------------
// Bitmap Manager General Methods
//-----------------------------------------------------------------
void BitmapManager::addBitmap(Bitmap& pBitmap)
{
	//Push back the bitmap
	m_pBitmaps.push_back(&pBitmap);
}

void BitmapManager::CleanupBitmaps()
{
	std::list<Bitmap*>::iterator biBitmap = m_pBitmaps.begin();
	while (biBitmap != m_pBitmaps.end() )
	{
		delete(*biBitmap);	
		biBitmap = m_pBitmaps.erase(biBitmap);
	}
}

