#ifndef funkcje_h
#define funkcje_h
#include <vld.h>
#include "struktury.h"

/** Funkcja wczytuje dane z pliku o danej nazwie.
@param nazwa nazwa pliku
@param pGlowa glowa listy studentów
*/
void WczytajZPliku(std::string nazwa, Student * & pGlowa);

/** Funkcja zapisuje dane do pliku o danej nazwie.
@param pGlowa glowa listy studentów
*/
void ZapiszDoPliku(Student * & pGlowa);

/** Funkcja dodaje studenta do listy, lub jesli istnieje juz o danym nr albumu, to go znajduje.
@param pGlowa glowa listy studentów
@param imie imie dodawanego / szukanego studenta
@param nazwisko nazwisko dodawanego / szukanego studenta
@param nrAlbumu nr albumu dodawanego / szukanego studenta
@return wskaŸnik na studenta o danym nr albumu
*/
Student * DodajStudenta(Student * & pGlowa, std::string imie, std::string nazwisko, int nrAlbumu);

/** Funkcja dodaje ocene do listy ocen.
@param pGlowa glowa listy ocen
@param prowadzacy prowadz¹cy, który wystawi³ ocenê
@param przedmiot przedmiot, z którego jest ocena
@param data data wystawienia oceny
@param ocena ocena, która zosta³a wpisana
*/
void DodajOcene(Ocena * & pGlowa, std::string prowadzacy, std::string przedmiot, std::string data, float ocena);

/** Funkcja sortuje listê ocen (wg. nazwy przedmiotu).
@param pGlowa glowa listy ocen
*/
void SortujListeOcen(Ocena * & pGlowa);

/** Funkcja czyœci listê ocen.
@param pGlowa glowa listy ocen
*/
void CzyscOceny(Ocena * & pGlowa);

/** Funkcja czyœci listê studentów i wszystkie powiazane z nimi listy.
@param pGlowa glowa listy studentów
*/
void CzyscStudentow(Student * & pGlowa);

#endif