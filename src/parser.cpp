#include <cctype>
#include <cstdlib>
#include <iostream>

#include "parser.h"

void Parser::parse() {
    string tmp = "";
    bool isNumeric = true, getCMD = true;

    for (string::iterator it = raw.begin(); it != raw.end(); it++) {
        // You are finished getting the first word (which is the command)
        if (getCMD && *it == ' ')       getCMD = false;
        // If it isn't a number
        if (getCMD && !isdigit(*it))    isNumeric = false;
        // If you have finished getting the command, put it as content
        if (!getCMD)
            content += *it;
        else
            tmp += *it;
    }

    trimContent();

    // Edit the line
    if (isNumeric) {
        cmd = EditLine;
        lineno = atoi(tmp.c_str());
        return;
    }

    // List command
    if (tmp == "list" || tmp == "l") {
        cmd = List;
        parseContent(cmd);
        return;
    }

    // Insert command
    if (tmp == "insert" || tmp == "ins") {
        cmd = Insert;
        parseContent(cmd);
        return;
    }

    // Save command
    if (tmp == "save" || tmp == "s") {
        cmd = Save;
        parseContent(cmd);
        return;
    }
}

void Parser::trimContent() {
    string tmp = "";
    unsigned i = 0;
    for (; content[i] == ' '; i++) {}
    unsigned start = i;
    for (i = content.length()-1; content[i] == ' '; i--) {}

    content = content.substr(start, i);
}

void Parser::parseContent(Command c) {
    switch (c) {
    case List:
        break;
    case Insert:
        break;
    case EditLine:
        break;
    default:
        break;
    }
}
