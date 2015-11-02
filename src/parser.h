#ifndef PARSER_H
#define PARSER_H

#include <string>

using namespace std;

enum Command {List, Save, Insert, EditLine};
enum NType {Number, Comma, Content};

struct Node {
    Node *parent, *lchild, *rchild;
    NType type;
    string raw;
};

class Parser {
private:
    string raw;

public:
    Command cmd;
    unsigned lineno;
    string content;
    Node *root;

    Parser(string s): raw(s), root(NULL) {};

    void parse();
    void parseContent(Command);
    void trimContent();

};

#endif
