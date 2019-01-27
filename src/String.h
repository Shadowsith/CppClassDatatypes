#ifndef STRING_H
#define STRING_H

#include <string>
#include <vector>
#include <any>

class String {

    private:
        std::string m_str;

    public:
        String();
        String(std::string str);
        String(const char* cstr);

        //casts 
        std::string toStdStr();
        const char* toCStr();
        std::vector<char> toCharArr();

        bool isEmpty();
        bool isEmptyOrWhiteSpace();
        bool compare(String &s);
        bool compare(const std::string &s);

        inline bool equals(String &s);
        inline bool equals(const std::string &s);

        int length();
        inline int size();

        // string formatting 
        String concat (const String &s);
        std::string concat(const std::string &s);

        void copyTo(String &s);
        void copyTo(std::string &s);
        
        int count(const String s);
        int count(const std::string s); 
        int count(const char* s); 

        std::vector<int> find(const String s);
        std::vector<int> find(const std::string s);
        std::vector<int> find(const char* s);

        inline std::vector<int> findAll(const String s);
        inline std::vector<int> findAll(const std::string cstr);
        inline std::vector<int> findAll(const char* cstr);

        int findFirst(const String s);
        int findFirst(const std::string s);
        int findFirst(const char* s);

        inline int indexOf(const String s);
        inline int indexOf(const std::string s);
        inline int indexOf(const char* s);

        int findLast(const String s);
        int findLast(const std::string s);
        int findLast(const char* s);

        inline int lastIndexOf(const String s);
        inline int lastIndexOf(const std::string s);
        inline int lastIndexOf(const char* s);

        std::string replace(std::string oldstr, std::string newstr);

        std::string replaceFirst(std::string oldstr, std::string newstr);
        std::string replaceLast(std::string oldstr, std::string newstr);
        std::string replaceHead(int headsize, std::string newstr);
        std::string replaceTail(int tailsize, std::string newstr);

        std::string erase(std::string erasestr); 
        std::string eraseFirst(std::string erasestr); 
        std::string eraseLast(std::string erasestr); 
        std::string eraseHead(int headsize); 
        std::string eraseTail(int tailsize); 

        std::vector<std::string> split(const std::string delimiter);
        void swap(std::string &str2);

        std::string toUpper();
        std::string toLower();

        std::string trim();
        std::string trimLeft();
        std::string trimRight();

        std::string fillLeft(int length, char fill);
        inline std::string padLeft(int length, char fill);
        std::string fillRight(int length, char fill);
        inline std::string padRight(int length, char fill);

        std::string normPathUnix();
        std::string normPathWindows();

        static std::string format(std::string formatText, std::string &str);
        static std::string format(std::string formatText, std::string &str1, std::string &str2);
        static std::string format(std::string formatText, std::string &str1, std::string &str2, std::string &str3);
        static std::string format(std::string formatText, std::vector<std::string> &strArr);

        //operators
        operator std::string() const; // save String obj to std::string
        String operator= (String &s);
        void operator= (std::string str); // save std::string to String
        void operator= (const char* c); // save char* to String

        bool operator== (const String &s); // String and String
        bool operator== (const std::string &str); // std::string and String
        bool operator== (const char* c);

        bool operator!= (const String& S);
        bool operator!= (const std::string str);
        bool operator!= (const char* c);

        String& operator+= (const String &S);
        String& operator+= (const std::string str);
        String& operator+= (const char* c);
        String& operator+= (const char c); 

        char& operator[] (int pos);

        friend std::ostream& operator<< (std::ostream &out, const String &S);
        friend std::istream& operator>> (std::istream &is, const String &S);
};

#endif
