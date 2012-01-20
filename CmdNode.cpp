#include "CmdNode.h"
#include <iostream>

CmdNode::CmdNode(int x)
{
	cmd = x;
	next = NULL;
}
CmdNode::CmdNode(int x, CmdNode * y)
{
	cmd = x;
	next = y;
}
