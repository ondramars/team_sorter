#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

#import "team.h"

class CAssigner {
    
public:
                                    CAssigner       ( string file_name, unsigned teams );
    
    bool                            Load            ( void );
    bool                            Set             ( void );
    bool                            Empty           ( void );
    
    unsigned                        YoungestTeam    ( void );
    bool                            OldestPerson    ( CPerson & x );
    
    void                            Print           ( void ) const;
    
private:
    unsigned                        NUM_OF_TEAMS;
    unsigned                        MAX_NUM_OF_MEMBERS;
    
    string                          file_name;
    vector< CPerson >               people;
    vector< CTeam >                 teams;
};
