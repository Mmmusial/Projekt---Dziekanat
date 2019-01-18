#ifndef struktury_h
#define struktury_h
#include <vld.h>
#include <string>

struct Ocena
{
	std::string prowadzacy, przedmiot, data; 
	float ocena;
	Ocena * pNast; 
};

struct Student
{
	std::string imie, nazwisko;
	int nrAlbumu;
	Ocena * pOGlowa; 
	Student * pNast; 
};

#endif