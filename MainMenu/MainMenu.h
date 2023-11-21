#pragma once

#include <iostream>
#include <string>

class MainMenu
{
    public:
    MainMenu();
    ~MainMenu();
    void renderTitle() const; //static
    void renderBlankNames() const; //static
    // void updatedNameMenu(); //will update current display

    void draftMenu();   //will update current display
    //void activeDraftMenu();   //will update current display

    // void battleScreenMenu();    //will update current display
    void renderEndScreen();   //will update current display
    void renderCredits() const; //static
};

