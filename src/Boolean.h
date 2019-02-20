#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "Datatype.h"

namespace dt {

    class Boolean : Datatype {

        private:
        bool _internal = false;

        public:
        Boolean() {}

        Boolean(int i) {
            if(i == 0) _internal = false;
            else _internal = true;
        }

        Boolean(const char* s) {
            if(s == "true") _internal = true;
            else _internal = false;
        }

        Boolean(std::string s) {
            if(s == "true") _internal = true;
            else _internal = false;
        }

        bool getValue() { return _internal }

        bool compareTo(Boolean &b) {
            return (this->getValue() == b.getValue())
        }

        bool compareTo(bool b) {
            return (this->getValue() == b);
        }

        std::string toString() {
            if(_internal) return "true";
            else return "false";
        }

        static std::string toString(Boolean b) {
            if(b.getValue()) return "true";
            else return "false";
        }

        static std::string toString(bool b) {
            if(b) return "true";
            else return "false";
        }

        static Boolean valueOf(bool b) {
            Boolean bo(b);
            return bo;
        }

        static Boolean valueOf(const char* cs) {
            Boolean bo(cs);
            return bo;
        }

        static Boolean vlaueOf(std::string s) {
            Boolean bo(s);
            return bo;
        }
    };
}

#endif //BOOLEAN_H 


