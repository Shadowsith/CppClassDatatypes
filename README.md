# CppDataTypesOOP 

A C++ STL library to get object orientated classes for the rudementary datetypes +
String class for std::string

This is a low priority project.
--- 

## Idea
The idea is simply to have class types like in C# or Java.

## Planned classes
* Boolean
* Character
* Integer
* Float
* Double
* Valueless?
* WideCharacter
* String

## Implemented classes
* Boolean (partly)
* String (partly)


## Usage

### Boolean


### String
String is a wrapper class for std::string and the method names are inspired by the
Java String and C# string implementations. A lot of method names are copied from Java
and C# or are synonyms like compare and equals.

Members:
* private: std::string m_str; --> m_str is base of all method operations

Constructors:
* String() --> creates String with m_str = ""; 
* String(const char\* cstr) --> Initialise m_str over const char\*
* String(std::string str); 

Methods (alphabetical order)

