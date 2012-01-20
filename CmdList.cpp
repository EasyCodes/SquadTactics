#include "CmdList.h"
#include "CmdNode.h"


CmdList::CmdList()
{
	head = NULL;
}
void CmdList::addCmd(int cmd)
{  
	CmdNode * temp;
	if(head == NULL)
	{
		head = new CmdNode(cmd, NULL);
	}
    else		
	{
		temp = head;	
		while(temp->next !=NULL){temp = temp->next;}
		temp->next = new CmdNode(cmd, NULL);
	}
}
int CmdList::getCmd()
{
	CmdNode * temp;
	temp = head;
	if(head == NULL)
	{
		cout <<"NULL command";
		return NULL;
	}
	else
	{
		while(temp->next != NULL)
		{
			if (temp->next == NULL)
			{
				return temp->cmd;
				break;
			}

		}
		return -2;
	}
	return -2;
}
CmdNode * CmdList::getNext()
{
	CmdNode * temp;
	temp = head;
	if(head == NULL)
	{
		cout <<"Head is NULL";
	}
	if(temp->next == NULL)
	{
		cout <<"Next is NULL";
		return temp->next;
	}
	else
	{
		return temp->next;
	}
}
CmdNode * CmdList::getHead()
{
	return head;
}
/*
void CmdList::delCmd()
{  
	CmdNode * temp;
	if(head == NULL)
	{
		cout << "CmdList Empty";
	}
    else		
	{
		temp = head;	
		while(temp->next !=NULL){temp = temp->next;}
		temp->next = new CmdNode(cmd, NULL);
	}
}
*/
void CmdList::print()
 {
	 CmdNode * p;
	 p = head;
	 while(p != NULL)
	 {
		 cout << p->cmd << "\n";
		 p = p->next;
	 }
 }