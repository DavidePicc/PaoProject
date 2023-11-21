#include <string>
#include "generate.h"

namespace comodo{
    char setSesso(){
        return generaNumeroCasuale<int>(0, 1)==0 ? 'M' : 'F';
    }
}