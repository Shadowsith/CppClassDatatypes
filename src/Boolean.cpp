#include "Boolean.h"

Boolean::Boolean() {}

Boolean::Boolean(int i) {
    if(i == 0) {
        _internal = false;
    } else {
        _internal = true;
    }
}

Boolean::Boolean(const char* cs) {
    if(cs == "true") {
        _internal = true;
    } else {
        _internal = false;
    }
}

Boolean::Boolean(std::string s) {
    if(s == "true") {
        _internal = true;
    } else {
        _internal = false;
    }
}

bool Boolean::getValue() {
    return _internal;
}

bool Boolean::compareTo(Boolean b) {
    return (this->getValue() == b.getValue());
}

std::string Boolean::toString() {
    if(_internal) {
        return "true";
    } else {
        return "false";
    }
}

std::string Boolean::toString(Boolean b) {
    if(b.getValue()) {
        return "true";
    } else {
        return "false";
    }
}

std::string Boolean::toString(bool b) {
    if(b) {
        return "true";
    } else {
        return "false";
    }
}

static Boolean valueOf(bool b) {
    Boolean bo(b);
    return bo;
}

static Boolean valueOf(const char* cs) {
    Boolean bo(cs);
    return bo;
}

static Boolean valueOf(std::string s) {
    Boolean bo(s);
    return bo;
}
