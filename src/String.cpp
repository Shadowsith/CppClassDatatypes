#include "String.h"
#include <iostream>
#include <algorithm>

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

char String::charAt(const int pos) {
    return m_str.at(pos);
}

bool String::isEmpty() {
    return m_str.empty();
}

bool String::isEmptyOrWhiteSpace() {
    if(m_str.empty()) {
        return true;
    } else {
        if(m_str.find_first_not_of(' ') != std::string::npos){
            return false;
        }
        return true;
    }
}

bool String::compare(String &s) {
    if(m_str == s.toStdStr()) return true;
    else return false;
}

bool String::compare(const std::string &str) {
    if(m_str == str) return true;
    else return false;
}

inline bool String::equals(String &s) {
    return this->compare(s);
}

inline bool String::equals(const std::string &str) {
    return this->compare(str);
}

int String::length() {
    return m_str.length();
}

inline int String::size() {
    return this->length();
}

String String::concat(const String &s) {
    m_str += s.m_str;
    return String(m_str);
}

std::string String::concat(const std::string &str) {
    return m_str + str; 
}

void String::copyTo(String &s) {
    s.m_str = m_str;
}

void String::copyTo(std::string &to){
    to = m_str;
}

int String::count(const String s) {
    return this->find(s).size();
}

int String::count(const std::string s) {
    return this->find(s).size();
}

int String::count(const char* s) {
    return this->find(s).size(); 
}

std::vector<int> String::find(const std::string s) {
    std::vector<int> vec;
    std::size_t pos = m_str.find(s);
    while(pos != std::string::npos) {
        vec.push_back(pos);
        pos = m_str.find(s,pos+1);
    } return vec;
}

std::vector<int> String::find(const String s) {
    return this->find(s.m_str);
}

std::vector<int> String::find(const char* cstr) {
    return this->find(std::string(cstr)); 
}

inline std::vector<int> String::findAll(const String s) {
    return this->find(s);
}

inline std::vector<int> String::findAll(const std::string s){
    return this->find(s);
}

inline std::vector<int> String::findAll(const char* s) {
    return this->find(s);
}

int String::findFirst(const std::string s) {
    std::size_t pos = m_str.find(s);
    if(pos != std::string::npos){
        int i = static_cast<int>(pos);
        return i;
    } return 0;
}

int String::findFirst(const String s) {
    return this->findFirst(s.m_str);
}

int String::findFirst(const char* s) {
    return this->findFirst(std::string(s));
}

inline int String::indexOf(const String s) {
    return this->findFirst(s.m_str);
}

inline int String::indexOf(const std::string s) {
    return this->findFirst(s);
}

inline int String::indexOf(const char* s) {
    return this->findFirst(s);
}


int String::findLast(const std::string s) {
    std::size_t pos = m_str.rfind(s);
    if(pos != std::string::npos){
        int i = static_cast<int>(pos);
        return i;
    } return 0;
}

int String::findLast(const String s) {
    return this->findLast(s.m_str);
}

int String::findLast(const char* s) {
    return this->findLast(std::string(s));
}

inline int String::lastIndexOf(const String s){
    return this->findLast(s);
}
    
inline int String::lastIndexOf(const std::string s){
    return this->findLast(s);
}

inline int String::lastIndexOf(const char* s){
    return this->findLast(s);
}

std::string String::replace(const std::string oldstr, const std::string newstr){
    std::size_t pos = m_str.find(oldstr);
    while(pos != std::string::npos) {
        m_str.replace(pos, oldstr.length(), newstr);
        pos = m_str.find(oldstr,pos+1);
    }
    return m_str;
}

std::string String::replace(const String oldstr, const String newstr) {
    return this->replace(oldstr.m_str, newstr.m_str); 
}

std::string String::replace(const char* oldstr, const char* newstr) {
    return this->replace(std::string(oldstr), std::string(newstr));
}

std::string String::replaceFirst(const std::string oldstr, const std::string newstr){
    std::size_t pos = m_str.find(oldstr);
    if(pos != std::string::npos) {
        m_str.replace(pos, oldstr.length(), newstr);
    } return m_str;
}

std::string String::replaceFirst(const String oldstr, const String newstr) {
    return this->replaceFirst(oldstr.m_str, newstr.m_str); 
}

std::string String::replaceFirst(const char* oldstr, const char* newstr) {
    return this->replaceFirst(std::string(oldstr), std::string(newstr));
}

std::string String::replaceLast(const std::string oldstr, const std::string newstr){
    std::size_t pos = m_str.rfind(oldstr);
    if(pos != std::string::npos) {
        m_str.replace(pos, oldstr.length(), newstr);
    } return m_str;
}

std::string String::replaceLast(const String oldstr, const String newstr) {
    return this->replaceLast(oldstr.m_str, newstr.m_str); 
}

std::string String::replaceLast(const char* oldstr, const char* newstr) {
    return this->replaceLast(std::string(oldstr), std::string(newstr));
}

std::string String::replaceHead(const int headsize, const std::string newstr){
    m_str.erase(0,headsize);
    m_str = newstr + m_str;
    return m_str;
}

std::string String::replaceHead(const int headsize, const String newstr){
    return this->replaceHead(headsize, newstr.m_str);
}

std::string String::replaceHead(const int headsize, const char* newstr){
    return this->replaceHead(headsize, std::string(newstr));
}

std::string String::replaceTail(const int tailsize, const std::string newstr){
    m_str.erase(m_str.end()-tailsize, m_str.end());
    m_str += newstr;
    return m_str;
}

std::string String::replaceTail(const int tailsize, const String newstr){
    return this->replaceTail(tailsize, newstr.m_str);
}

std::string String::replaceTail(const int tailsize, const char* newstr){
    return this->replaceTail(tailsize, std::string(newstr));
}

std::string String::erase(const std::string erasestr){
    std::string::size_type n = erasestr.length();
    for (std::string::size_type i = m_str.find(erasestr); i != std::string::npos; 
        i = m_str.find(erasestr)) {
        m_str.erase(i, n);    
    }
    return m_str;
} 

std::string String::erase(const String erasestr){
    return this->erase(erasestr.m_str);
}

std::string String::erase(const char* erasestr){
    return this->erase(std::string(erasestr));
}

std::string String::eraseFirst(const std::string erasestr){
    std::size_t pos = m_str.find(erasestr);
    if(pos != std::string::npos){
        m_str.erase(pos, erasestr.length());
    } return m_str;
} 

std::string String::eraseFirst(const String eraseFirststr){
    return this->eraseFirst(eraseFirststr.m_str);
}

std::string String::eraseFirst(const char* eraseFirststr){
    return this->eraseFirst(std::string(eraseFirststr));
}

std::string String::eraseLast(std::string erasestr){
    std::size_t pos = m_str.rfind(erasestr);
    if(pos != std::string::npos){
        m_str.erase(pos, erasestr.length());
    } return m_str;
} 

std::string String::eraseLast(const String eraseLaststr){
    return this->eraseLast(eraseLaststr.m_str);
}

std::string String::eraseLast(const char* eraseLaststr){
    return this->eraseLast(std::string(eraseLaststr));
}

std::string String::eraseHead(const int headsize){
    m_str.erase(0,headsize);
    return m_str;
}

std::string String::eraseTail(const int tailsize){
    m_str.erase(m_str.end()-tailsize, m_str.end());
    return m_str;
} 

std::vector<std::string> String::split(const std::string delimiter){
    std::vector<std::string> parts;
    std::string str = m_str;
    std::size_t pos = 0;
    std::string token;
    while((pos = str.find(delimiter)) != std::string::npos){
        token = str.substr(0,pos);
        parts.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    parts.push_back(str);
    return parts;
}

std::vector<std::string> String::split(const String delimiter) {
    return this->split(delimiter.m_str);
}

std::vector<std::string> String::split(const char* delimiter) {
    return this->split(std::string(delimiter));
}

std::vector<std::string> String::split(const char delimiter) {
    std::string s;
    s += delimiter;
    return this->split(s);
}

void String::swap(std::string &str2) {
    std::string str3 = m_str;
    m_str = str2;
    str2 = str3;
}

void String::swap(String &str2) {
    std::string str3 = m_str;
    m_str = str2;
    str2 = str3;
}

std::string String::toUpper(){
    std::transform(m_str.begin(), m_str.end(), m_str.begin(), ::toupper);  
    return m_str; 
}

std::string String::toLower(){
    std::transform(m_str.begin(), m_str.end(), m_str.begin(), ::tolower);  
    return m_str;
}

std::string String::trim() {
    //trim left side
    std::string::size_type trimIt = 0;
    for(std::string::size_type i = 0; i < m_str.length(); i++) {
        if(m_str[i] == ' ') {
            trimIt++;    
        } else break;
    }
    m_str.erase(0,trimIt);

    //trim right side
    trimIt = m_str.length();
    for(std::string::size_type i = m_str.length()-1; i > 0; i--) {
        if(m_str[i] == ' '){
            trimIt--;
        } else break;
    }
    m_str.erase(trimIt, m_str.length()-1);

    return m_str;
}

std::string String::trimLeft(){
    std::string::size_type trimIt = 0;
    for(std::string::size_type i = 0; i < m_str.length(); i++) {
        if(m_str[i] == ' ') {
            trimIt++;    
        } else break;
    }
    m_str.erase(0,trimIt);

    return m_str;
}

std::string String::trimRight(){
    std::string::size_type trimIt = m_str.length();
    while(m_str.rfind(" ") == m_str.length()-1){
        if(m_str.length() == 1){
            m_str.erase(0);
            break;
        }
        m_str.erase(m_str.length()-1);
    } return m_str;
}

std::string String::fillLeft(const int length, const char fill){
    for(int i = 0; i < length; i++){
        m_str.insert(m_str.begin(), fill);
    } return m_str;
}

inline std::string String::padLeft(const int length, const char fill){
    return this->fillLeft(length, fill);    
}

std::string String::fillRight(const int length, const char fill){
    for (int i = 0; i < length; i++) {
        m_str += fill;
    } return m_str;
}

inline std::string String::padRight(const int length, const char fill){
    return this->fillRight(length, fill);
}

std::string String::normPathUnix(){
    for(int i = 1; i < m_str.length(); i++){
        if(m_str.at(i) == m_str.at(i-1)){
            m_str.erase(i);
        }
    } return m_str;
}

std::string String::normPathWindows(){
    for(int i = 1; i < m_str.length(); i++) {
        if(m_str.at(i) == m_str.at(i-1)){
            m_str.erase(i);
        }
    } return m_str;
}

// formatting 



//operator overloading

String::operator std::string() const{
    return m_str;
}

String String::operator= (String &s) {
    return s.m_str;
}

void String::operator= (std::string str) {
    m_str = str;
}

void String::operator= (const char* c) {
    m_str = std::string(c);
}

bool String::operator== (const String &s) {
    return (m_str.compare(s.m_str) == 0);
}

bool String::operator== (const std::string &str) {
    return (m_str.compare(str) == 0);
}

bool String::operator== (const char* c) {
    for(int i = 0; i < m_str.length(); i++) {
        if(m_str[i] != c[i]) {
            return false;
        }
    }
    return true;
}

bool String::operator!= (const String& S) {
    return (m_str.compare(S.m_str) != 0);
}

bool String::operator!= (const std::string str) {
    return (m_str.compare(str) != 0);
}

bool String::operator!= (const char* c) {
    for(int i = 0; i < m_str.length(); i++) {
        if(m_str[i] != c[i]) {
            return true;
        }
    }
    return false;
}

String& String::operator+= (const String &S) {
    this->m_str += S.m_str; 
    return *this;
}

std::string String::operator+(const String &s) {
    return m_str + s.m_str;
}

std::string String::operator+(const std::string &s) {
    return m_str + s;
}

std::string String::operator+(const char* s) {
    return m_str + std::string(s);
}

String& String::operator+= (const std::string str) {
    this->m_str += str;
    return *this;
}

String& String::operator+= (const char* c) {
    std::string convert(c);
    this->m_str += convert;
    return *this;
}

String& String::operator+= (const char c) {
    this->m_str += c;
    return *this;
}

std::string String::operator*(String &s) {
    for(int i = 0; i < s.size(); i++) {
        m_str += s.m_str;
    } return m_str;
}

char& String::operator[] (int pos) {
    return this->m_str[pos];
}

// shows member m_str for std::cout 
std::ostream& operator<< (std::ostream &out, const String &S) {
   out << S.m_str; 
   return out;
}

std::istream& operator>> (std::istream &is, String &S) {
    char* input = new char[256];
    is.getline(input,256);
    std::string convert(input);
    S = convert;
    return is;
}
