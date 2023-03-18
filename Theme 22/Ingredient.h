#pragma once
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Ingredient {

private:
    string namee;
    int timee;

public:
    Ingredient(string name, int time) : namee(name), timee(time){}

    string getName() const;

    int getTime() const;
};
