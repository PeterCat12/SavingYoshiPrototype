//-----------------------------------------------------------------
// Timer Class
// C++ Header - Audio Manager.h
//-----------------------------------------------------------------

#ifndef TIMER_H
#define TIMER_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include <time.h>
#include <math.h>

typedef std::pair<int, int> Point;

//struct tmWrap
//{
//protected:
//	int sec;
//	int min;
//	int hour;
//	int mday;
//	int year;
//public:
//
//	tmWrap(tm* _tm)
//		:sec(_tm->tm_sec,_
//	{
//
//	}
//
//
//};


//-----------------------------------------------------------------
// Timer Class
//-----------------------------------------------------------------
class Timer
{
protected:
	//Member variables

	static double m_iSeconds; 
	static double m_iMinutes;
	static double m_iMili;
	static clock_t t1;
	static clock_t t2;
	static bool timerSet;


public:
	// Constructor(s)/ Destructors
	Timer(){};
	~Timer(){};

	// General Methods
	static void StartClock()
	{
		if(!timerSet)
		{
			t1 = clock();
			timerSet = true;
		}

	}

	static void StartClock(int NumMins, int NumSecs, int NumMili)
	{
		if(!timerSet)
		{
			t1 = clock();
			timerSet = true;
		}
	}

	static float TimeDifference()
	{
		t2 = clock() - t1;
		return (((float) t2)/CLOCKS_PER_SEC);
	}

	// Setters / Getters
	static void SetCountDown(int NumMinutes, int NumSeconds = 0, int NumMili = 0)
	{
		m_iMinutes = NumMinutes;
		m_iSeconds = NumSeconds; 
		m_iMili = NumMili;
	} ;
	
private:
};

clock_t Timer::t1;
clock_t Timer::t2;
bool    Timer::timerSet;
#endif


