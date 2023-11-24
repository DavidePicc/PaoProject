#include <string>
#include "generate.h"

namespace comodo{
    char setSesso(){
        return generaNumeroCasuale(0, 10) < 5 ? 'M' : 'F';
    }
}