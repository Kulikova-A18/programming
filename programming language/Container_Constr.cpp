#include "Container.h"
#include "iostream"
void Clear(Container *&c)
{
	Container *temp;
	temp = c->Next;
	while (temp != c){
		c->Next = temp->Next;
		delete temp;
		temp = c->Next;
	}
	delete c;
	c = nullptr;
};
void Init(Container &c)
{
	c.Next = &c;
	c.L = NULL;
};
