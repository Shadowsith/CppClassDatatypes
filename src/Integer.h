#ifndef INTEGER_H
#define INTEGER_H

#include <string>
#include <cstdlib>
#include <bitset>
#include <iostream>

class Integer {

    private:
    _internal = 0;

    public:
    Integer() {}
    Integer(int i) { _internal = i }
    Integer(const char* cs) {
        _internal = atoi(cs);
    }
    Integer(std::string s) { 
        _internal = std::stoi(s);
    }

    int intValue() {
        return _internal;
    }
    int longValue() {
        return static_cast<long>(_internal);
    }

    bool compareTo(int i) {
        return _internal == i;
    } 

    bool compareTo(Integer &i) {
        return _internal == i._internal;
    }

    double doubleValue() {
        return static_cast<double>(_internal);
    }

    float floatValue() {
        return static_cast<float>(_internal);
    }

    static int parse(const char* cs) {
        return atoi(cs);
    }

    static int parse(std::string s) {
        return std::stoi(s);
    }

    static int parse(float f) {
        return static_cast<int>(f);
    }

    static int parse(double d) {
        return static_cast<int>(d);
    }

    static int reverse(int i) {
        int reversedNumber = 0, remainder = 0;
        while(i != 0) {
            remainder = i%10;
            reversedNumber = reversedNumber*10 + remainder;
            i /= 10;
        } 
        return reversedNumber;       
    }

    static std::string toBinaryString(int i) {
        return std::bitset<64>(i).to_string();
    }

    static std::string toHexString(std::string s) {
    }

    static std::string toOctalString(std::string s) {
    }

    static std::string toString() {
        return std::to_string(_internal);
    }

};

#endif //INTEGER_H 


