#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

class CTeam;

class CAssignor {
    
public:
                                    CAssignor       ( string file_name );
    
    bool                            Load            ( void );
    bool                            Set             ( int  );
    bool                            Empty           ( void );
    
    unsigned                        YoungestTeam    ( void );
    pair< unsigned, string >        OldestPerson    ( void );
    
private:
    
    string                          file_name;
    multimap< unsigned, string >      people;
    vector< CTeam >                teams;
};

CAssignor::CAssignor ( string file_name )
: file_name( file_name ) { }

bool CAssignor::Load ( void ) {
    
    string name, birth_date;
    unsigned year;
    
    ifstream in( file_name );
    
    if ( !in.is_open() ) return false;
    
    while ( in.good() ) {
        
        getline( in, name, ',' );
        getline( in, birth_date );
        
        year = stoul( birth_date.substr( birth_date.size() - 4, 4 ), NULL, 0);
        
        people.insert( make_pair( name, year ) );
    }
    
    in.close();
    return true;
}

bool CAssignor::Set ( int team_num ) {
    
    for ( int i = 0; i < team_num; i++ ) {
        
        teams.push_back( CTeam( i ) );
    }
}

bool CAssignor::Empty ( void ) {
    
    while ( !people.empty() ) {
        
        teams[ YoungestTeam() ].Add( OldestPerson() );
    }
    
    return true;
}

unsigned CAssignor::YoungestTeam ( void ) {
    
    CTeam min = teams.front();
    
    for ( auto const team: teams ) {
        
        if ( min.Mean() < team.Mean() )
        {
            min = team;
        }
    }
    
    return min.Id();
}

pair< unsigned, string > CAssignor::OldestPerson ( void ) {
    
    
}



class CPerson {
    
public:
    
    CPerson ( string name, string birth_date );
    
    bool            BirthDateToAge  ( void );
    unsigned        Age             ( void ) const { return age; }
    unsigned        Year            ( void ) const { return birth_year; }
    string          Name            ( void ) const { return name; }
    
private:
    
    string                          name;
    string                          birth_date;
    unsigned                        age;
    unsigned                        birth_year;
};

CPerson::CPerson ( string name, string birth_date )
: name( name ), birth_date( birth_date ) { }


 
class CTeam {
    
public:
                    CTeam            ( unsigned id );
    
    unsigned        Id              ( void ) const;
    unsigned        Sum             ( void ) const;
    float           Mean            ( void ) const;
    void            Print           ( void ) const;
    
    void            Add             ( pair< unsigned, string> x );
    
private:
    
    unsigned                        id;
    multimap< unsigned, string >      people;
};

CTeam::CTeam ( unsigned id )
: id( id ) { }

unsigned CTeam::Id ( void ) const {
    return id;
}

unsigned CTeam::Sum ( void ) const {
    
    unsigned sum = 0;
    
    for ( auto const i: people ) {
        
        sum += i.first;
    }
    
    return sum;
}

float CTeam::Mean ( void ) const {
    
    return Sum() / people.size();
}

void CTeam::Print ( void ) const {
    
    cout << "Oddíl č." << id + 1 << ":" << endl;
    
    for ( auto const i: people )
        cout << i.first << ", " << i.second << endl;

}

void CTeam::Add ( pair< unsigned, string> x ) {
    people.insert( x );
}



int main ( int argc, char * argv[] ) {
    
    // minimální množství argumentů
    if ( argc != 3 )
    {
        cout << "Usage: " << argv[0] << "<number_of_teams>  file_name.txt" << endl;
        return 1;
    }
    
    // rozdělujeme do jednoho až dvanácti týmů
    if ( atoi( argv[1] ) < 1 || atoi( argv[1] ) > 12 )
    {
        cout << "For my purposes we need to assign people to < 1, 12 > teams." << endl;
        return 2;
    }
    
    CAssignor ass( argv[2] );
    
    ass.Load();
    ass.Set( atoi( argv[1] ) );
    ass.Empty();
    
    return 0;
}
