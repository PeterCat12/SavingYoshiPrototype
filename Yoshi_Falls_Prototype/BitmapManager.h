//-----------------------------------------------------------------
// Bitmap Manager
// C++ Header - Bitmap.h
//-----------------------------------------------------------------

#ifndef BITMAPMANAGER_H
#define BITMAPMANAGER_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Bitmap.h"
#include <list>
//-----------------------------------------------------------------
// Bitmap Manager Class
//-----------------------------------------------------------------
class BitmapManager
{
protected:
	// Member Variables
	std::list<Bitmap*> m_pBitmaps;

	// Constructor(s)/Destructors
public:
	BitmapManager();
	~BitmapManager();
	
	// General Methods
	void addBitmap(Bitmap& pBitmap); // Should there be a const there?
	void CleanupBitmaps();
	std::list<Bitmap*> getBitmapList() {return m_pBitmaps;} //Returns the list

};
#endif