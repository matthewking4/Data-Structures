#pragma once
#include "BasePage.h"
using namespace std;

class HomePage : public BasePage {
public:
	HomePage() : BasePage() {
		title = "Home Page";
	}
};
