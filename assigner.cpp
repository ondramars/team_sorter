#import "assigner.h"

CAssigner::CAssigner ( string file_name, unsigned teams )
: file_name( file_name ), NUM_OF_TEAMS( teams ) {
    
}

bool CAssigner::Load ( void ) {
    
    string name, sex, age;
    unsigned age_num = 0;
    
    ifstream in( file_name );
    
    if ( !in.is_open() ) return false;
    
    while ( in.good() ) {
        
        getline( in, name, ',' );
        getline( in, age,  ',' );
        getline( in, sex );
        
        age_num = stoul( age );
        
        if ( sex == "muž" )
            people.emplace_back( CPerson( name, true, age_num ) );
        if ( sex == "žena")
            people.emplace_back( CPerson( name, false, age_num ) );
    }
    
    MAX_NUM_OF_MEMBERS = people.size() / NUM_OF_TEAMS;
    if ( people.size() % NUM_OF_TEAMS != 0 ) MAX_NUM_OF_MEMBERS++;
    
    cout << "Zaregistrováno " << people.size() << " dětí." << endl << endl;
    
    in.close();
    return true;
}

bool CAssigner::Set ( void ) {
    
    for ( int i = 0; i < NUM_OF_TEAMS; i++ ) {
        
        teams.emplace_back( CTeam( i ) );
    }
    
    return true;
}

bool CAssigner::Empty ( void ) {
    
    
    CPerson x;
    
    while ( !people.empty() ) {
        
        OldestPerson( x );
        
        teams[ YoungestTeam() ].AddPerson( x );
    }
    
    return true;
}

unsigned CAssigner::YoungestTeam ( void ) {
    
    CTeam min = teams.front();
    bool is_space = false;
    
    for ( auto const team: teams ) {
        
        if ( team.Size() < MAX_NUM_OF_MEMBERS )
        {
            min = team;
            is_space = true;
            break;
        }
    }
    
    if ( !is_space )
    {
        cout << "Fatal Error: Not enough space in teams for new person!" << endl;
        return 0;
    }
    
    for ( auto const team: teams ) {
        
        if ( min.Mean() < team.Mean() && team.Size() < MAX_NUM_OF_MEMBERS )
        {
            min = team;
        }
    }
    
    return min.Id();
}

bool CAssigner::OldestPerson ( CPerson & x ) {
    
    for ( int i = 15; i > 0; i--) {
        
        for ( int p = 0; p < people.size(); p++ ) {
            
            if ( people[p].Age() >= i ) {
                
                x = people[p];
                people.erase( people.begin()+p );
                return true;
            }
        }
    }
    
    return false;
}

void CAssigner::Print ( void ) const {
    
    for ( CTeam i: teams )
        i.Print();
}
