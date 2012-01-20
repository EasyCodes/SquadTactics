#ifndef CMDLIST_H
#define CMDLIST_H
#include "CmdNode.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class CmdList {
CmdNode *head;
  public:
	  CmdList();
	  void addCmd(int cmd);
	  void delCmd();
	  void print();
	  int getCmd();
	  CmdNode * getNext();
	  CmdNode * getHead();
};


#endif