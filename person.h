#ifndef _PERSON_
#define _PERSON_

#include <string>
#include <vector>
#include <map>

using namespace std;

/*
 *
 *
 *
 *
 *
 */

class CPerson {
    
public:
                    
                            CPerson         ( void );
    
                            CPerson         ( string    name,
                                              bool      male,
                                              unsigned  age );
        
    string                  Name            ( void ) const { return name; }
    
    bool                    isMale          ( void ) const { return male; }
    bool                    isFemale        ( void ) const { return !male; }
    
    unsigned                Age             ( void ) const { return age; }
    
    vector< CPerson >     & Friends         ( void ) { return friends; }
    
private:
    
    string                  name;
    bool                    male;
    unsigned                age;
    
    vector< CPerson >       friends;
};

#endif /* _PERSON_ */
