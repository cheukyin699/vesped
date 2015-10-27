#include <fstream>
#include <iostream>

#include "editor.h"

using namespace std;

Editor::Editor() {
	isRunning = true;
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

	isRunning = true;
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
}

void Editor::list() {
	for (unsigned ln = 0; ln < buffer.size(); ln++) {
		cout << ln+1 << ": " << buffer[ln] << endl;
	}
	cout << OK_STAT << endl;
}
