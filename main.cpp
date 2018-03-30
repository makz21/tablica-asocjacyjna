#include <iostream>
using namespace std;
#include "asocjacja.h"


int
main ()
{
  asocjacjaMale a1;
  a1["pies"] = 1;
  a1["kot"] = 2;
    cout<<endl << "Asocjacja z malymi albo duzymi literami:" << " "  << a1["pies"] << " " << a1["KOT"] << endl;
  
  asocjacjaDuze b1;
  b1["PIES"] = 1;
  b1["KOT"] = 3;
    cout <<"Asocjacja z malymi i duzymi literami:" << " "  << b1["pies"] << " " << b1["kot"] << endl;
  
  b1["pies"]++;
    cout << "Zwiekszanie wartosci przypisanej do klucza:"<< " " << b1["pies"] << endl<<endl;


}
