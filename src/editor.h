#ifndef EDITOR_H
#define EDITOR_H

#include <vector>
#include <string>

#define OK_STAT		"Ok"

using namespace std;

class Editor {
private:
	vector<string> buffer;
	unsigned long curr_line;

	void list();

public:
	bool isRunning;

	Editor();
	Editor(string);

	void handleInput(string);
};

#endif
