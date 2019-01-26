#ifndef DATATYPE_H
#define DATATYPE_H

#include <string>

namespace dt {

    class Datatype {
        public:
            virtual std::string toString() = 0;
    };
}

#endif
