///////////////////////////////////////////////////////////////////////////////
//operators
#include "operators.h"
ostream& operator<<(ostream &fout,Point p)
{
	fout<<p.x<<"\t"<<p.y;
	return fout;
}

istream& operator>>(istream &fin,Point &p)
{
	fin>>p.x>>p.y;
	return fin;
}

bool operator==(color a, color b)
{
	if(a.ucRed==b.ucRed && a.ucGreen==b.ucGreen && a.ucBlue==b.ucBlue)
		return true;
	else 
		return false;
}

ostream& operator<<(ostream &out,color c)
{
	if(c==BLACK)out<<"BLACK";
	else if(c==WHITE)out<<"WHITE";
	else if(c==BLUE)out<<"BLUE";
	else if(c==GREEN)out<<"GREEN";
	else if(c==RED)out<<"RED";
	else if(c==INDIAN)out<<"INDIAN";
	return out;
}

istream& operator>>(istream &in, color &c)
{
	string cs;
	in>>cs;

	if(cs=="BLACK") c=BLACK;
	else if(cs=="WHITE") c=WHITE;
	else if(cs=="BLUE") c=BLUE;
	else if(cs=="GREEN") c=GREEN;
	else if(cs=="RED") c=RED;
	else if(cs=="INDIAN") c=INDIAN;
	return in;
}
