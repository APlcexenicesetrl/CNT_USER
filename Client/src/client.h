#pragma once

#include "win.h"

class client {
private:
	String CNT_Path;
	bool isFail = false;
public:
	client(String _RUNPATH) : CNT_Path(_RUNPATH) {
		if (!PathExists(CNT_DEFAULT_RUNPATH)) {
			logs.error("$CNT_PATH$ not found!");
			logs.error("Client init fail.");
			isFail = true;
		}
	}

	~client() {}

	void install(String);
	void uninstall(String);

	bool fail() const { return isFail; }
private:

};

