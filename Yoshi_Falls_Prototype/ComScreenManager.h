//-----------------------------------------------------------------
// Com Screen Manager Singleton
// C++ Header - Yoshi Falls.h
//-----------------------------------------------------------------

#ifndef COMSCREEN_MAN_H
#define	COMSCREEN__MAN_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "ComScreen.h"

//-----------------------------------------------------------------
// Com-Screen Manager Class
//-----------------------------------------------------------------

//If you want to add more screen, YOU MUST make changes to the screen_Name Enum. Is this bad design?
enum SCREEN_NAME
{
	TOP_LEFT = 0,
	BOTTOM_LEFT = 1,
	CENTER = 2,
	TOP_RIGHT = 3,
	BOTTOM_RIGHT = 4
};

// Enum hack? Meyer says not to use #defines?
enum NUM_SCREENS
{
	NUM_SCREENS = 5
};

class ComScreenMan
{
protected:
	// Member Variables
	// For now, This manager just holds references to already created screens
	//When screens constructor is called, they add themselves to the manager?
	ComScreen* m_pComScreen[NUM_SCREENS]; 

public:
	// Constructor(s)/Destructor
	ComScreenMan();
	~ComScreenMan();
	
	//General Methods
	BOOL BecomeMainScreen(ComScreen* pComScreen);
	BOOL AddScreen(ComScreen* pComScreen, SCREEN_NAME screenName);
	ComScreen* getScreen(SCREEN_NAME screenName);
	ComScreen* isPointInComScreen(const int x, const int y);

private:
	//Helper Methods
	void SwapBitmapPairs(ComScreen& Screen1, ComScreen& Screen2);
};
#endif