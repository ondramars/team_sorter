#import "team.h"

CTeam::CTeam ( unsigned id )
: id( id ) {
    
}

unsigned CTeam::Id ( void ) const {
    return id;
}

unsigned CTeam::AgeSum ( void ) const {
    
    unsigned sum = 0;
    
    for ( CPerson i: people )
        sum += i.Age();
    
    return sum;
}

unsigned CTeam::Size ( void ) const {
    
    return people.size();
}

float CTeam::Mean ( void ) const {
    
    if ( people.size() == 0 ) return 20;
    return ( (float) AgeSum() / (float) people.size() );
}

void CTeam::AddPerson ( CPerson & x ) {
    
    people.push_back( x );
}

void CTeam::Print ( void ) const {
    
    cout << "Oddíl č." << Id()+1 << " (průměrný věk " << Mean() << "):" << endl;
    
    for ( CPerson i: people )
        cout << " - " << i.Age() << " let, " << i.Name() << endl;
    cout << endl;
}
