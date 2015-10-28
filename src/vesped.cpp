#include <iostream>

#include "editor.h"

#define VESPED_VERSION        "v0.1.0"

int main(int argc, char *argv[]) {
    Editor *ed = new Editor(argv[1]);

    // Display info
    cout << "VESPED " VESPED_VERSION << endl;

    string line = "";

    while (ed->isRunning) {
        // Take command input
        getline(cin, line);

        ed->handleInput(line);
    }

    return 0;
}
