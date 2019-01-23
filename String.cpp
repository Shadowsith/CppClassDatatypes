#include "String.h"

String::String() { m_str = ""; }

String::String(std::string str) {
    m_str = str;
}

String::String(const char* cm_str) {
    m_str = std::string(cm_str);
}

std::string String::toStdStr() {
    return m_str;
}

const char* String::toCStr() {
    return m_str.c_str();
}

std::vector<char> String::toCharArr() {
    std::vector<char> vec;
    for(char c : m_str) {
        vec.push_back(c);
    }
    return vec;
}

bool String::isEmpty() {
    if(m_str == "") {
        return true;
    } else { 
        return false;
    }
}

bool String::isEmptyOrWhiteSpace() {
    
}

bool String::compare(const std::string &str) {
    if(m_str == str) {
        return true;
    } else {
        return false;
    }
}


//operator overloading


String::operator std::string() const{
    return m_str;
}

String String::operator= (String &s){
    return s.m_str;
}

void String::operator= (std::string str){
    m_str = str;
}

void String::operator= (const char* c){
    m_str = std::string(c);
}

bool String::operator== (const String &s){
    return (m_str.compare(s.m_str) == 0);
}

bool String::operator== (const std::string &str){
    return (m_str.compare(str) == 0);
}

bool String::operator== (const char* c){
    for(int i = 0; i < m_str.length(); i++){
        if(m_str[i] != c[i]){
            return false;
        }
    }
    return true;
}

bool String::operator!= (const String& S){
    return (m_str.compare(S.m_str) != 0);
}

bool String::operator!= (const std::string str){
    return (m_str.compare(str) != 0);
}

bool String::operator!= (const char* c){
    for(int i = 0; i < m_str.length(); i++){
        if(m_str[i] != c[i]){
            return true;
        }
    }
    return false;
}

String& String::operator+= (const String &S){
    this->m_str += S.m_str; 
    return *this;
}

String operator+ (String lhs, const String& rhs)
{
    lhs += rhs;
    return lhs;
}

String& String::operator+= (const std::string str){
    this->m_str += str;
    return *this;
}

String operator+ (String lhs, const std::string& rhs){
    lhs += rhs;
    return lhs;
}

String& String::operator+= (const char* c){
    std::string convert(c);
    this->m_str += convert;
    return *this;
}

String operator+ (String lhs, const char* rhs){
    lhs += rhs;
    return lhs;
}

String& String::operator+= (const char c){
    this->m_str += c;
    return *this;
}

String operator+ (String lhs, const char rhs){
    lhs += rhs;
    return lhs;
}

char& String::operator[] (int pos){
    return this->m_str[pos];
}

// shows member m_str for std::cout 
std::ostream& operator<< (std::ostream &out, const String &S){
   out << S.m_str; 
   return out;
}

std::istream& operator>> (std::istream &is, String &S){
    char* input = new char[256];
    is.getline(input,256);
    std::string convert(input);
    S = convert;
    return is;
}
