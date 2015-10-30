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

    // Edit the line
    if (isNumeric) {
        cmd = EditLine;
        lineno = atoi(tmp.c_str());
        return;
    }
}
