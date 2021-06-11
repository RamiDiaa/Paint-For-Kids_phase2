#ifndef OPERATORS_H
#define OPERATORS_H

#include <fstream>
#include "DEFS.h"
using namespace std;
ostream& operator<<(ostream &fout,Point p);
istream& operator>>(istream &fin,Point &p);
ostream& operator<<(ostream &out,color c);
istream& operator>>(istream &in, color &c);
bool operator==(color a, color b);
#endif