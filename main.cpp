#include "iostream"
#include "cstdlib"
#include "sud.h"

using namespace std;

int main()
{	
	srand(time(NULL));
	
	Sud sud;
	sud.init();
	
	Player antos("Antos", 10, 2, 1, 100);
	antos.takeItem(sud.getItem(rand() % sud.howMuchItems()));
	
	return 0;
}
