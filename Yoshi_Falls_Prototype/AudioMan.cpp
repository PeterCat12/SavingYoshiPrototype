//-----------------------------------------------------------------
// Audio Manager
// C++ Source - AudioMan.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "AudioMan.h"

//-----------------------------------------------------------------
// Static Variables
//-----------------------------------------------------------------
bool AudioMan::m_bInstanceFlag;

AudioMan* AudioMan::m_sSingle;

//-----------------------------------------------------------------
// AudioManager Constructor(s)/Destructor
//-----------------------------------------------------------------
AudioMan::AudioMan()
{
	m_pSndEngine =  irrklang::createIrrKlangDevice();
}

AudioMan* AudioMan::getInstance()
{
	if( ! m_bInstanceFlag)
	{
		m_sSingle = new AudioMan();
		m_bInstanceFlag = true;
		return m_sSingle;
	}
	else
	{
		return m_sSingle;
	}
}

ISoundEngine* AudioMan::getSoundEngine()
{
	return getInstance()->m_pSndEngine;
}

void AudioMan::clear()
{
	getInstance()->m_pSndEngine->removeAllSoundSources();
}

void AudioMan::drop()
{
	getInstance()->m_pSndEngine->drop();
}
