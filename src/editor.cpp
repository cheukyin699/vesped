#include <fstream>
#include <iostream>

#include "editor.h"

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
    if (line == "list") {
        list();
        return;
    }

    if (line == "quit") {
        isRunning = false;
        return;
    }

    if (line == "save") {
        save();
        return;
    }

    // Editing commands
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

void Editor::save() {
    if (filename == "") {
        err("Error: No filename; please input filename");
        return;
    }
    ofstream f(filename.c_str());

    if (f.good()) {
        for (unsigned ln = 0; ln < buffer.size(); ln++)
            f << buffer[ln] << endl;
    } else {
        err("Error: Cannot open file");
    }

    f.close();

    cout << OK_STAT << endl;
}
