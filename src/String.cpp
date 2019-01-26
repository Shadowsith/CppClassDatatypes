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

bool String::compare(const std::string &str) {
    if(m_str == str) return true;
    else return false;
}

bool String::equals(const std::string &str) {
    if(m_str.compare(str) == 0) return true;
    else false;
}

std::string String::concat(const std::string &str) {
    return m_str + str; 
}

void String::copyTo(std::string &to){
    to = m_str;
}

int String::count(const std::string searchStr) {
    return this->find(searchStr).size();; 
}

std::vector<int> String::find(const std::string search){
    std::vector<int> vec;
    std::size_t pos = m_str.find(search);
    while(pos != std::string::npos) {
        vec.push_back(pos);
        pos = m_str.find(search,pos+1);
    } return vec;
}

inline std::vector<int> String::findAll(const std::string search){
    return this->find(search);
}

int String::findFirst(std::string find){
    std::size_t pos = m_str.find(find);
    if(pos != std::string::npos){
        int i = static_cast<int>(pos);
        return i;
    } return 0;
}

inline int String::indexOf(const std::string find){
    return this->findFirst(find);
}

int String::findLast(const std::string find){
    std::size_t pos = m_str.rfind(find);
    if(pos != std::string::npos){
        int i = static_cast<int>(pos);
        return i;
    } return 0;
}
    
inline int String::lastIndexOf(const std::string find){
    return this->findLast(find);
}

std::string String::replace(const std::string oldstr, const std::string newstr){
    std::size_t pos = m_str.find(oldstr);
    while(pos != std::string::npos) {
        m_str.replace(pos, oldstr.length(), newstr);
        pos = m_str.find(oldstr,pos+1);
    }
    return m_str;
}

std::string String::replaceFirst(const std::string oldstr, const std::string newstr){
    std::size_t pos = m_str.find(oldstr);
    if(pos != std::string::npos) {
        m_str.replace(pos, oldstr.length(), newstr);
    } return m_str;
}

std::string String::replaceLast(const std::string oldstr, const std::string newstr){
    std::size_t pos = m_str.rfind(oldstr);
    if(pos != std::string::npos) {
        m_str.replace(pos, oldstr.length(), newstr);
    } return m_str;
}

std::string String::replaceHead(int headsize, const std::string newstr){
    m_str.erase(0,headsize);
    m_str = newstr + m_str;
    return m_str;
}

std::string String::replaceTail(int tailsize, const std::string newstr){
    m_str.erase(m_str.end()-tailsize, m_str.end());
    m_str += newstr;
    return m_str;
}

std::string String::erase(const std::string erasestr){
    std::string::size_type n = erasestr.length();
    for (std::string::size_type i = m_str.find(erasestr); i != std::string::npos; 
        i = m_str.find(erasestr)) {
        m_str.erase(i, n);    
    }
    return m_str;
} 

std::string String::eraseFirst(const std::string erasestr){
    std::size_t pos = m_str.find(erasestr);
    if(pos != std::string::npos){
        m_str.erase(pos, erasestr.length());
    } return m_str;
} 

std::string String::eraseLast(std::string erasestr){
    std::size_t pos = m_str.rfind(erasestr);
    if(pos != std::string::npos){
        m_str.erase(pos, erasestr.length());
    } return m_str;
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

void String::swap(std::string &str2) {
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

inline std::string String::padRight(int length, char fill){
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

String operator+ (String lhs, const String& rhs) {
    lhs += rhs;
    return lhs;
}

String& String::operator+= (const std::string str) {
    this->m_str += str;
    return *this;
}

String operator+ (String lhs, const std::string& rhs) {
    lhs += rhs;
    return lhs;
}

String& String::operator+= (const char* c) {
    std::string convert(c);
    this->m_str += convert;
    return *this;
}

String operator+ (String lhs, const char* rhs) {
    lhs += rhs;
    return lhs;
}

String& String::operator+= (const char c) {
    this->m_str += c;
    return *this;
}

String operator+ (String lhs, const char rhs) {
    lhs += rhs;
    return lhs;
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
