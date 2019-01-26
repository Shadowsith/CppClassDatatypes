#ifndef INTEGER_H
#define INTEGER_H

#include <string>

class Integer {

    private:
        _internal = 0;

    public:
        Integer();
        Integer(int value);
        Integer(const char* cs);
        Integer(std::string s);

        int intValue();
        int longValue();

        bool compareTo(int i); 
        bool compareTo(Integer i);
        double doubleValue();
        float floatValue();

        static int parse(int i);
        static int parse(const char* cs);
        static int parse(std::string s);
        static int parse(float f);
        static int parse(double d);
        static int reverse(int i);

        static std::string toBinaryString(int i);
        static std::string toHexString(std::string s);
        static std::string toOctalString(std::string s);
        static std::string toString();
        

};

#endif //INTEGER_H 


