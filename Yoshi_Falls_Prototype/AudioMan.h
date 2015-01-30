//-----------------------------------------------------------------
// Audio Manager
// C++ Header - Audio Manager.h
//-----------------------------------------------------------------

#ifndef AUDIOMAN_H
#define AUDIOMAN_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "irrKlang.h"

using namespace irrklang;

//-----------------------------------------------------------------
// Audio Manager Class
//-----------------------------------------------------------------
class AudioMan
{
public:

	// General Methods
	static ISoundEngine* getSoundEngine();
	static void drop();
	static void clear();

private:
	static AudioMan* getInstance();
	AudioMan();
	// Member variables;
	static bool m_bInstanceFlag;
	static AudioMan* m_sSingle;
	ISoundEngine* m_pSndEngine;
};
#endif