#pragma once
#include "BasePage.h"
using namespace std;

// New Class and inherit Base Page
class ViewPage : public BasePage {
public:
	// Invoke inherited constructor and assign its public value
	ViewPage(int p) : BasePage(p) {
		title = "View Page";
	}
};
