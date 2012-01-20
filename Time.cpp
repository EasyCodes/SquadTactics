#include "Time.h"


Time::Time(){}
int Time::get_time()
{
	return time;
}
int Time::Start(void * arg)
{
   Arg(arg); // store user data
   time = 0;
	while (1>0)
	{
		wait(1);
		time++;
	}
   return 0;
}

void Time::Run(void * arg)
{
   Setup();
   Execute( arg );
}

/*static */
void Time::EntryPoint(void * pthis)
{
   Time * pt = (Time*)pthis;
   
   pt->Start( pt );
}

void Time::Setup()
{
        
}

void Time::Execute(void* arg)
{
        // Your code goes here
}