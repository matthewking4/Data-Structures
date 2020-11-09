#pragma once
#include "BasePage.h"
using namespace std;

// New Class and inherit Base Page
class ViewPage : public BasePage {
public:
	// Invoke inheritted constructor and asign its public value
	ViewPage(int p) : BasePage(p) {
		title = "View Page";
	}
};
