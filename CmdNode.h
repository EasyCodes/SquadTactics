#ifndef CMDNODE_H
#define CMDNODE_H


class CmdNode {
  public:
	int cmd;
	CmdNode * next;
	CmdNode(int x);
	CmdNode(int x, CmdNode * y);
};


#endif