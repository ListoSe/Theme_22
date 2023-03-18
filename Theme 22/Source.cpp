#include <iostream>
#include <queue>
#include <string>
#include "Ingredient.h"
using namespace std;

int main() {
    queue<Ingredient> ingredients;

    while (true) {
        cout << "What do you want to do? (add ingredient / cook dish) and if you want change the last added ingredient to another write - (add other ingredient)" << endl;

        string action;
        getline(cin, action);

        if (action == "add ingredient") {
            cout << "Enter ingredient name: ";
            string name;
            getline(cin, name);

            cout << "Enter ingredient preparation time (min): ";
            int time;
            cin >> time;

            Ingredient ingredient(name, time);
            ingredients.push(ingredient);

            cout << "Added " << name << " to the queue." << endl;
        }
        else if (action == "cook dish") {
            int total_time = 0;

            while (!ingredients.empty()) {
                Ingredient ingredient = ingredients.front();
                ingredients.pop();

                total_time += ingredient.getTime();
                cout << "Preparing " << ingredient.getName() << " (" << ingredient.getTime() << " min)" << endl;
            }

            cout << "Dish is ready! Total preparation time: " << total_time << " min" << endl;
        }
        else if (action == "add other ingredient") {
            cout << "Enter ingredient name: ";
            string name;
            getline(cin, name);

            cout << "Enter ingredient preparation time (min): ";
            int time;
            cin >> time;

            Ingredient ingredient(name, time);

            queue<Ingredient> temp;

            while (!ingredients.empty()) {
                Ingredient temp_ingredient = ingredients.front();
                ingredients.pop();

                if (ingredients.size() == 0) {
                    temp.push(ingredient);
                }
                else {
                    temp.push(temp_ingredient);
                }
            }

            ingredients = temp;

            cout << "Added " << name << " to the queue." << endl;
        }
        else {
            cout << "Error 404. Please try again." << endl;
        }
        cin.ignore();
    };

    return 0;
}