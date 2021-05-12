#ifndef _TEAM_
#define _TEAM_

#include <iostream>
#include <string>
#include <vector>
#include <map>

#import "person.h"

using namespace std;

/*
 *
 *
 *
 *
 *
 */

class CTeam {
    
public:
                            CTeam           ( unsigned id );
    
    unsigned                Id              ( void ) const;
    unsigned                AgeSum          ( void ) const;
    unsigned                Size            ( void ) const;
    float                   Mean            ( void ) const;
    void                    Print           ( void ) const;
    
    void                    AddPerson       ( CPerson & x );
    
private:
    
    unsigned                id;
    vector< CPerson >       people;
};

#endif /* _TEAM_ */
