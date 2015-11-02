#include <fstream>
#include <iostream>

#include "editor.h"
#include "parser.h"

using namespace std;

Editor::Editor() {
    filename = "";
    isRunning = true;
    prmpt = NORM_PRMPT;
}

Editor::Editor(string fn) {
    ifstream in(fn.c_str());

    if (in.good()) {
        string tmp = "";
        while(getline(in, tmp)) {
            buffer.push_back(tmp);
        }
    }

    in.close();

    filename = fn;
    isRunning = true;
    prmpt = NORM_PRMPT;
}

void Editor::handleInput(string line) {
    // Basic commands
    if (line == "list" || line == "l") {
        list();
        return;
    }

    if (line == "quit" || line == "q") {
        isRunning = false;
        return;
    }

    if (line == "save" || line == "s") {
        save();
        return;
    }

    // For more complex commands, do parsing
    Parser *p = new Parser(line);
    p->parse();

    switch (p->cmd) {
    case List:
        // list x, y
        break;
    case Save:
        // save filename
        save(p->content);
        break;
    case Insert:
        // insert line# line
        break;
    case EditLine:
        // line# line
        break;
    default:
        break;
    }
}

void Editor::list() {
    for (unsigned ln = 0; ln < buffer.size(); ln++) {
        cout << ln+1 << ": " << buffer[ln] << endl;
    }
    cout << OK_STAT << endl;
}

inline void Editor::err(string e) {
    cerr << e << endl;
}

inline void Editor::save() {
    save(filename);
}

void Editor::save(string fn) {
    if (fn == "") {
        err("Error: No filename; please input filename");
        return;
    }
    ofstream f(fn.c_str());

    if (f.good()) {
        for (unsigned ln = 0; ln < buffer.size(); ln++)
            f << buffer[ln] << endl;
    } else {
        err("Error: Cannot open file");
    }

    f.close();

    cout << "Saved as `" << fn << "'\n" << OK_STAT << endl;
}
