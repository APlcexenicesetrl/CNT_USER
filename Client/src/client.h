#pragma once

#include "win.h"

class client {
private:
	String CNT_Path;
public:
	client(String _RUNPATH) : CNT_Path(_RUNPATH);
	~client();

	void install(String);
	void uninstall(String);
private:

};