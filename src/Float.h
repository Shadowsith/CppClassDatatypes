#ifndef FLOAT_H
#define FLOAT_H

#include "Datatype.h"
#include <string>
#include <cstdlib>

class Float : Datatype {
    private:
    float _internal = 0.0;

    public:
    Float() {}
    Float(float f) { _internal = f }

    short shortValue() {
        return static_cast<short>(_internal);
    }

    int intValue() {
        return static_cast<int>(_internal);
    }

    long longValue() {
        return static_cast<long>(_internal);
    }

    double doubleValue() {
        return static_cast<double>(_internal);
    }

    static float parse(short s) {
        return static_cast<float>(s);
    }

    static float parse(int i) {
        return static_cast<float>(i);
    }

    static float parse(long l) {
        return static_cast<float>(l);
    }

    static float parse(double d) {
        return static_cast<float>(d);
    }

    static float parse(const char* s) {
        return std::atof(s);
    }

    static float parse(std::string s) {
        return std::stof(s);
    }

    std::string toString() {
        return std::to_string(_internal);
    }
}

#endif //FLOAT_H 


