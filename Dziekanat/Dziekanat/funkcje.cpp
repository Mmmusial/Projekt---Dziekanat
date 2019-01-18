#include <fstream>
#include <vld.h>
#include "funkcje.h"
#include "struktury.h"

void WczytajZPliku(std::string nazwa, Student * & pGlowa)
{
	std::string imie, nazwisko, data, prowadzacy, przedmiot;
	float ocena;
	int	nrAlbumu;
	std::ifstream plik;
	plik.open(nazwa);
	if (plik.good())
	{
		std::getline(plik, przedmiot);
		std::getline(plik, prowadzacy);
		while (plik >> imie >> nazwisko >> nrAlbumu >> ocena >> data)
		{
			Student * pS = DodajStudenta(pGlowa, imie, nazwisko, nrAlbumu); 
			DodajOcene(pS->pOGlowa, prowadzacy, przedmiot, data, ocena); 
		}
		plik.close();
	}
}

void ZapiszDoPliku(Student * & pGlowa)
{
	if (pGlowa)
	{
		Student * pS = pGlowa;  
		while (pS)
		{
			std::ofstream plik;
			std::string s = std::to_string(pS->nrAlbumu); 
			plik.open(s + ".txt"); 
			if (plik.good())
			{
				plik << pS->imie << ' ' << pS->nazwisko << " nr albumu: " << pS->nrAlbumu << std::endl; 
				Ocena * pO = pS->pOGlowa;    
				SortujListeOcen(pS->pOGlowa); 
				while (pO)
				{
					plik << pO->prowadzacy << ' ' << pO->przedmiot << ' ' << pO->ocena << ' ' << pO->data << std::endl;  
					pO = pO->pNast; 
				}
				plik.close();
			}
			pS = pS->pNast;
		}
	}
}

Student * DodajStudenta(Student * & pGlowa, std::string imie, std::string nazwisko, int nrAlbumu)
{
	if (pGlowa)
	{
		if (pGlowa->nrAlbumu == nrAlbumu)
			return pGlowa;
		return DodajStudenta(pGlowa->pNast, imie, nazwisko, nrAlbumu); 
	}
	return pGlowa = new Student{ imie, nazwisko, nrAlbumu, nullptr, nullptr };
}

void DodajOcene(Ocena * & pGlowa, std::string prowadzacy, std::string przedmiot, std::string data, float ocena) 
{
	if (!pGlowa)
		pGlowa = new Ocena{ prowadzacy, przedmiot, data, ocena, nullptr };
	else
		DodajOcene(pGlowa->pNast, prowadzacy, przedmiot, data, ocena);
}

void SortujListeOcen(Ocena * & pGlowa)
{
	if (pGlowa)
	{
		Ocena * pI = nullptr;
		Ocena * pJ = nullptr;
		for (pI = pGlowa; pI; pI = pI->pNast)
			for (pJ = pI; pJ; pJ = pJ->pNast)
				if (pI->przedmiot.compare(pJ->przedmiot) > 0) 
				{
					std::swap(pI->data, pJ->data);
					std::swap(pI->ocena, pJ->ocena);
					std::swap(pI->prowadzacy, pJ->prowadzacy);
					std::swap(pI->przedmiot, pJ->przedmiot);
				}
	}
}

void CzyscOceny(Ocena * & pGlowa)
{
	if (pGlowa)
	{
		CzyscOceny(pGlowa->pNast);         
		delete pGlowa;
		pGlowa = nullptr;
	}
}

void CzyscStudentow(Student * & pGlowa)
{
	if (pGlowa)
	{
		CzyscStudentow(pGlowa->pNast);
		CzyscOceny(pGlowa->pOGlowa);
		delete pGlowa;
		pGlowa = nullptr;
	}
}