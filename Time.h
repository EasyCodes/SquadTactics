#ifndef TIME_H
#define TIME_H
#include "STCMD.h"

class Time{

  public:
	//Start Game Time
	Time();
	int Start(void * arg);
	//What time is it?
	int get_time();
	//Game Time!

  protected:
	void Run(void * arg);
    static void EntryPoint(void*);
    virtual void Setup();
    virtual void Execute(void*);
    void * Arg() const {return Arg_;}
    void Arg(void* a){Arg_ = a;}
  private:
	int time;
	int TimeId_;
    void * Arg_;
};


#endif


