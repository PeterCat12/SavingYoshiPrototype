//-----------------------------------------------------------------
// ComScreen Manager
// C++ Source - Sprite.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "ComScreenManager.h"
//#include <stdio.h>
//#include <Windows.h>
//#include <iostream>
//#include <sstream>


//-----------------------------------------------------------------
// ComScreen Constructor(s)/Destructor
//-----------------------------------------------------------------
ComScreenMan::ComScreenMan()
{
	for(int i = 0; i < NUM_SCREENS; i++)
	{
		m_pComScreen[i] = 0;
	}
}

ComScreenMan::~ComScreenMan()
{
	// Deletion of screens is done elsewhere, all you have to do is set them to null?
	// Not sure if this is correct....
	for(int i = 0; i < NUM_SCREENS; i++)
	{
		m_pComScreen[i] = 0;
	}
}

//-----------------------------------------------------------------
// ComScreenManager General Methods
//-----------------------------------------------------------------

//HAVE TO TEST THIS FUNCTION
BOOL ComScreenMan::BecomeMainScreen(ComScreen* pComScreen)
{
	// Swap screen with main screen
	if(pComScreen->getScreenState() == SMALL) // Will always be passed a comScreen that is small
	{
		//Swap bitmap pairs
		SwapBitmapPairs(*pComScreen,*m_pComScreen[CENTER]);
		pComScreen->SwapBitmap(*pComScreen->getBitmapPair()->GetSmall());
		pComScreen->ResetNumFrames(pComScreen->getBitmapPair()->getNumFrames()); //Reset the number of frames available
		m_pComScreen[CENTER]->SwapBitmap(*m_pComScreen[CENTER]->getBitmapPair()->GetBig());
		m_pComScreen[CENTER]->ResetNumFrames(m_pComScreen[CENTER]->getBitmapPair()->getNumFrames());

		return TRUE;
	}
	return FALSE;
}

BOOL ComScreenMan::AddScreen(ComScreen* pComScreen, SCREEN_NAME screenName)
{
	//Add Screen to ComScreen Manager
	if(getScreen(screenName) == 0)
	{
		m_pComScreen[screenName] = pComScreen; //Can I use enums like that?? that'd be pretty cool if I could...
		if(screenName == CENTER)
			pComScreen->setScreenState(BIG);
		else
			pComScreen->setScreenState(SMALL);
		//Added screen successfully
		return TRUE;
	}
	else
		//Screen not added
		return FALSE;
}


ComScreen* ComScreenMan::getScreen(SCREEN_NAME screenName)
{
	//Return reference to specified screen
	switch (screenName)
	{
		case TOP_LEFT:
			if(m_pComScreen[0] != 0) //Make sure the screen is there
				return m_pComScreen[0];
			break;
		case BOTTOM_LEFT:
			if(m_pComScreen[1] != 0) //Make sure the screen is there
				return m_pComScreen[1];
			break;
		case CENTER:
			if(m_pComScreen[2] != 0) //Make sure the screen is there
				return m_pComScreen[2];
			break;
		case TOP_RIGHT:
			if(m_pComScreen[3] != 0) //Make sure the screen is there
				return m_pComScreen[3];
			break;
		case BOTTOM_RIGHT:
			if(m_pComScreen[4] != 0) //Make sure the screen is there
				return m_pComScreen[4];
			break;
	}
	return 0;
}

ComScreen* ComScreenMan::isPointInComScreen(const int x, const int y)
{
	//Cycle through ComScreens
	for(int i = 0; i < NUM_SCREENS; i++)
	{
		if(m_pComScreen[i] != 0)
		{
			if( !m_pComScreen[i]->IsHidden() && (m_pComScreen[i])->IsPointInside(x, y))
			{
				// if the screen is the center screen, then do nothing
				if(i == 2)// Uses a magic number.... Not sure how to avoid this... mod it?
					return 0;
				// else return the comScreen?
				else
					return m_pComScreen[i];
			}
		}
	}
	return 0;
}
//-----------------------------------------------------------------
// ComScreen Manager Helper Methods
//-----------------------------------------------------------------
void ComScreenMan::SwapBitmapPairs(ComScreen& Screen1, ComScreen& Screen2)
{
	//Shallow copy
	BitmapPair *temp = Screen1.getBitmapPair();
	Screen1.setBitmapPair(*Screen2.getBitmapPair());
	Screen2.setBitmapPair(*temp);
}