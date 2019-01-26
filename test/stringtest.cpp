#include "../src/String.h"
#include "./cli-textformatpp/src/textformatpp.h"
#include <iostream>
#include <vector>

void message(bool condition, std::string msg) {
    if(condition) {
        std::cout << text::green("ACCEPT: ") << text::green(msg) << std::endl;
    } else {
        std::cout << text::red("DENIED: ") << text::red(msg) << std::endl;
    }
}

void t_toStdStr() {
    message(String("hallo").toStdStr() == std::string("hallo"),
            "toStdStr");
} 

void t_toCStr() {
    const char* c = "hallo";
    message(String("hallo").toCStr() == c, "toCStr");
}

void t_toCArr() {
    std::string s = "hallo";
    std::vector<char> vec = String("hallo").toCharArr();
    std::vector<char> tvec;
    for(char c : s) {
        tvec.push_back(c);
    }
    message(vec == tvec, "toCArr");
} 

void t_empty() {
    message(String("").isEmpty(), "isEmpty");
}

void t_emptyOrWS() {
    message(String("   ").isEmptyOrWhiteSpace() && String("").isEmptyOrWhiteSpace(),
            "isEmptyOrWhiteSpace");
}

void t_compare_equals() {
    String s = "You are great";
    String st = "You are great";
    std::string str = "You are great";
    message(s.compare(st) && s.compare(str), "Compare/Equals");
}

void t_length_size() {
    String s = "hallo";
    std::string str = "hallo";
    message(s.length() == str.length(), "length/size");
}

void t_concat() {
    String s1 = String("hello").concat(String(" you"));
    String s2 = String("hello you");
    bool t1 = s1 == s2;
    bool t2 = s1 == std::string("hello you");
    message(t1 == t2, "Concat");
}

void t_copyTo() {
    std::string str;
    String("hello").copyTo(str);
    message(str == "hello", "CopyTo");
}

void t_count() {
    String s1("l");
    std::string s2 = "l";
    String s3("hello");
    bool t1 = s3.count(s1) == 2;
    bool t2 = s3.count(s2) == 2;
    bool t3 = s3.count("l") == 2;
    message(t1 == t2 == t3, "count");
}

void t_find_findAll() {
    static const int arr[] = {2, 3}; // 2 and 3 are pos of 'l' in hello
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::vector<int> vec1 = String("hello").find("l");
    std::vector<int> vec2 = String("hello").find(std::string("l"));
    std::vector<int> vec3 = String("hello").find(String("l"));

    bool t1 = vec == vec1;
    bool t2 = vec == vec2;
    bool t3 = vec == vec3;

    message(t1 == t2 == t3, "find/findAll");
}

void t_findFirst_indexOf() {
    
}

void t_findLast_lastIndexOf() {

}

int main(void)
{
    t_toStdStr();
    t_toCStr();
    t_toCArr();
    t_empty();
    t_emptyOrWS();
    t_compare_equals();
    t_length_size();
    t_concat();
    t_copyTo();
    t_find_findAll();
}
