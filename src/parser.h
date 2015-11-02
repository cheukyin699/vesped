#ifndef PARSER_H
#define PARSER_H

#include <string>

using namespace std;

enum Command {List, Save, Insert, EditLine};

class Parser {
private:
    string raw;

public:
    Command cmd;
    unsigned lineno;
    string content;

    Parser(string s): raw(s) {};

    void parse();
    void trimContent();

};

#endif
