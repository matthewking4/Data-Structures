#pragma once
#include "BasePage.h"
using namespace std;

// New Class and inherit Base Page
class VideoPage : public BasePage {
public:
    // Invoke inherited constructor and assign its public value
    VideoPage(int p) : BasePage(p) {
        title = "Video Page";
    }
};
