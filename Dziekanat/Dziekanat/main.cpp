#include "funkcje.h"
#include "struktury.h"
#include <vld.h>

int main(int argc, char * argv[])
{
	Student * pGlowa = nullptr;
	int rozkaz = 1;

	while (rozkaz + 1 < argc)           
	{
		std::string s = argv[rozkaz];        
		if (s == "i") 
		{                                       
			rozkaz++;
			WczytajZPliku(argv[rozkaz], pGlowa);
		}
		rozkaz++;
	}

	ZapiszDoPliku(pGlowa);
	CzyscStudentow(pGlowa);

	return 0;
}


	