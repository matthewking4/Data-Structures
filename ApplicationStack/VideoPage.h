#pragma once
#include "BasePage.h"
using namespace std;

// New Class and inherit Base Page
class VideoPage : public BasePage {
public:
    // Invoke inheritted constructor and asign its public value
    VideoPage(int p) : BasePage(p) {
        title = "Video Page";
    }
};
