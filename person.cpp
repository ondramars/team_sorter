#import "person.h"

CPerson::CPerson ( void ) {
    
}

CPerson::CPerson ( string    name,
                   bool      male,
                   unsigned  age )
: name( name ), male( male ), age( age ) {
    
}

