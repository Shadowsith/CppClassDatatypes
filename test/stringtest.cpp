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
    int i = 4;
    String s("hello you");
    int i1 = s.findFirst("o");
    int i2 = s.findFirst(std::string("o"));
    int i3 = s.findFirst(String("o"));
    bool t = (i == i1) && (i == i2) && (i == i3);

    message(t, "findFirst/indexOf");
}

void t_findLast_lastIndexOf() {
    int i = 7;
    String s("hello you");
    int i1 = s.findLast("o");
    int i2 = s.findLast(std::string("o"));
    int i3 = s.findLast(String("o"));
    bool t = (i == i1) && (i == i2) && (i == i3);

    message(t, "findLast/lastIndexOf");
}

void t_replace() {
    String s = "hello";
}


void t_split() {
    static const std::string arr[] = {"you", "are", "the", "greatest"}; 
    std::vector<std::string> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    String s = "you are the greatest";

    std::string ds = " ";
    String dS = " ";
    const char* dcst = " ";
    char dc = ' '; 

    std::vector<std::string> vec1 = s.split(ds);
    std::vector<std::string> vec2 = s.split(dS);
    std::vector<std::string> vec3 = s.split(dcst);
    std::vector<std::string> vec4 = s.split(dc);
    std::vector<std::string> vec5 = s.split(" ");
    std::vector<std::string> vec6 = s.split(' ');

    bool t1 = (vec == vec1) && (vec == vec2) && (vec == vec3) && (vec == vec4);
    bool t2 = (vec == vec5) && (vec == vec6);

    message(t1 == t2, "split");
}

void t_swap() {
    String s1 = "hallo";
    String s2 = "bye";
    s1.swap(s2);

    String s3 = "ciao";
    std::string s4 = "see you";
    s3.swap(s4);

    bool t1 = (s1 == "bye") && (s2 == "hallo");
    bool t2 = (s3 == "see you") && (s4 == "ciao");
    message(t1 == t2, "swap");
}

void t_toUpper() {
    String s = "hello";
    s.toUpper();
    message(s == "HELLO", "toUpper");
}

void t_toLower() {
    String s = "HELLO";
    s.toLower();
    message(s == "hello", "toLower");
}

void t_trim() {
    String s = "   hello     ";
    s.trim();
    message(s == "hello", "trim");
}

void t_trimLeft() {
    String s = "   hello     ";
    s.trimLeft();
    message(s == "hello     ", "trimLeft");
}

void t_trimRight() {
    String s = "   hello     ";
    s.trimRight();
    message(s == "   hello", "trimRight");
}

void t_fillLeft_padLeft() {
    String s = "111";
    s.fillLeft(3,'X');
    message(s == "XXX111", "fillLeft/padLeft");
}

void t_fillRight_padRight() {
    String s = "111";
    s.fillRight(3, 'X');
    message(s == "111XXX", "fillRight/padRigth");
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
    t_findFirst_indexOf();
    t_findLast_lastIndexOf();
    t_split();
    t_swap();
    t_toUpper();
    t_toLower();
    t_trim();
    t_trimLeft();
    t_trimRight();
    t_fillLeft_padLeft();
    t_fillRight_padRight();
}
