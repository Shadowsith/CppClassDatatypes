#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "Datatype.h"

namespace dt {

    class Boolean : Datatype {

        private:
            bool _internal = false;

        public:
            Boolean();
            Boolean(int value);
            Boolean(const char* value);
            Boolean(std::string value);

            bool getValue();
            bool compareTo(Boolean b);
            bool compareTo(bool b);
            std::string toString();
            static std::string toString(Boolean b);
            static std::string toString(bool b);
            static Boolean valueOf(bool b);
            static Boolean valueOf(const char* cs);
            static Boolean vlaueOf(std::string s);
    };
}

#endif //BOOLEAN_H 


