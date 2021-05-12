#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <unistd.h>

#import "assigner.h"

int main ( int argc, char * argv[] ) {
    
    // minimální množství argumentů
    if ( argc != 3 )
    {
        cout << "Usage: " << argv[0] << "<number_of_teams>  file_name.txt" << endl;
        return 1;
    }
    
    // rozdělujeme do jednoho až dvanácti týmů
    if ( stoul( argv[1] ) < 1 || stoul( argv[1] ) > 12 )
    {
        cout << "For my purposes we need to assign people to < 1, 12 > teams." << endl;
        return 2;
    }
    
    CAssigner ass( argv[2], stoul( argv[1] ) );
    
    unsigned int wait = 1000000;
    unsigned int WAIT = 2000000;
    
    ass.Load();
    /*
    usleep(wait);
    cout << endl <<  "Rozřazuji do 6 oddílů." << endl << "...0% roztříděno" << endl << endl;
    usleep(wait);
    cout << "Zpracovávám žádosti na kamarády v oddílu..." << endl;
    usleep(WAIT);
    cout << "...38% roztříděno" << endl << endl;
    usleep(wait);
    cout << "Počítám toleranci osobností podle znamení horoskopu..." << endl;
    usleep(WAIT);
    cout << "...45% roztříděno" << endl << endl;
    usleep(wait);
    cout << "Vyrovnávám průměrné věky oddílů..." << endl;
    usleep(WAIT);
    cout << "...63% roztříděno" << endl << endl;
    usleep(wait);
    cout << "Vyřizuji požadavky na vedoucí..." << endl;
    usleep(WAIT);
    cout << "...69% roztříděno" << endl << endl;
    usleep(wait);
    cout << "Doplňuji volná místa na pokojích podle pohlaví..." << endl;
    usleep(WAIT);
    cout << "...87% roztříděno" << endl << endl;
    usleep(wait);
    cout << "Vyrovnávám průměrné věky oddílů..." << endl;
    usleep(WAIT);
    cout << "...98% roztříděno" << endl << endl;
    usleep(wait);
    cout << "Přiřazuji Mariovi smrady, které nikdo nechce..." << endl;
    usleep(WAIT);
    cout << "...100% roztříděno" << endl << endl;
    usleep(wait);
    cout << "HOTOVO" << endl;
    */
    ass.Set();
    ass.Empty();
    
    ass.Print();
    
    return 0;
}
