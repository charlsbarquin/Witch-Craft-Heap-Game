#include <iostream>     
#include <vector>       // For using vectors (dynamic arrays)
#include <algorithm>    // For algorithms like find(), sort()
#include <cstdlib>      // For rand(), srand()
#include <ctime>        // For time()
#include <windows.h>    // For SetConsoleOutputCP() on Windows (Unicode support)

using namespace std;    

// Template function to display elements of a vector
template <typename T>
void displayVector(const vector<T>& vec) {
    if (vec.empty()) {
        cout << "The vector is empty." << endl;
        return;
    }
    // Loop through the vector elements and display them
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            // Add a space between elements, but not after the last element
            cout << " ";
        }
    }
    cout << endl;
}

// Checks if a given number is present in the list
bool isInList(int num, const vector<int>& list) {
    return find(list.begin(), list.end(), num) != list.end();
}

// Removes a given number from the list if it exists
void removeFromList(int num, vector<int>& list) {
    auto it = find(list.begin(), list.end(), num);
    if (it != list.end()) {
        list.erase(it);
    }
}

// Removes the selected numbers from the main list and clears the selection vectors
void clearSelectedNumbers(vector<int>& oddNumbers, vector<int>& evenNumbers, vector<int>& numbers) {
    cout << "\nThe selected numbers are removed from your list!\n";
    // Remove each odd number from the main numbers list
    for (int num : oddNumbers) {
        removeFromList(num, numbers);
    }
    // Remove each even number from the main numbers list
    for (int num : evenNumbers) {
        removeFromList(num, numbers);
    }
    // Clear the selected numbers lists
    oddNumbers.clear();  // Clear the odd numbers list
    evenNumbers.clear(); // Clear the even numbers list
}

int main() {
    // Set console code page to UTF-8 for Unicode support (specifically for emojis)
    SetConsoleOutputCP(CP_UTF8);

    cout << "🧙‍♀️ Welcome to the Witch Craft Heap Game!   🧙‍♀️\n\n";

    // Seed the random number generator with current time
    srand(time(0));

    // Declare vectors to hold numbers
    vector<int> numbers;             // Combined list of all numbers
    vector<int> oddNumbers;          // List of random odd numbers
    vector<int> evenNumbers;         // List of random even numbers

    // Generate 15 unique random odd numbers between 1 and 50
    while (oddNumbers.size() < 15) {
        int num = rand() % 50 + 1;   // Generate a random number between 1 and 50
        if (num % 2 != 0 && find(oddNumbers.begin(), oddNumbers.end(), num) == oddNumbers.end()) {
            // If the number is odd and not already in the list, add it to oddNumbers
            oddNumbers.push_back(num);
        }
    }

    // Generate 15 unique random even numbers between 1 and 50
    while (evenNumbers.size() < 15) {
        int num = rand() % 50 + 1;   // Generate a random number between 1 and 50
        if (num % 2 == 0 && find(evenNumbers.begin(), evenNumbers.end(), num) == evenNumbers.end()) {
            // If the number is even and not already in the list, add it to evenNumbers
            evenNumbers.push_back(num);
        }
    }

    // Combine both lists to form the numbers list (all 30 numbers)
    numbers.insert(numbers.end(), oddNumbers.begin(), oddNumbers.end());
    numbers.insert(numbers.end(), evenNumbers.begin(), evenNumbers.end());

    // Display the combined list of numbers
    cout << "30 mystical numbers have been summoned:\n";
    displayVector(numbers);
    cout << "\nYou must pick 3 odd (offensive) and 3 even (defensive) numbers.\n";
    cout << "Choose wisely to help the witch organize her spells!\n\n";

    vector<int> selectedOddNumbers, selectedEvenNumbers; // Vectors to store user's selected numbers
    int attempts = 3;    // User has 3 attempts (lives)

    while (attempts > 0) {
        // Clear previous selections
        selectedOddNumbers.clear();
        selectedEvenNumbers.clear();

        // User picks 3 odd numbers
        for (int i = 0; i < 3; ++i) {
            int num;
            while (true) {
                cout << "Enter an odd number: ";
                cin >> num;

                // Validate input:
                //   - Number between 1 and 50
                //   - Odd number
                //   - Number is in the list
                if (num >= 1 && num <= 50 && num % 2 != 0 && isInList(num, numbers)) {
                    selectedOddNumbers.push_back(num);         // Add number to selected odd numbers
                    removeFromList(num, numbers);              // Remove number from main numbers list
                    cout << "✔️ " << num << " added to the offensive spells.\n";
                    break;
                } else if (num < 1 || num > 50) {
                    // Handle invalid range input
                    cout << "❌ Invalid input! Please enter a number between 1 and 50.\n";
                } else if (num % 2 == 0) {
                    // Handle even number input
                    cout << "❌ Invalid input! Please enter an odd number.\n";
                } else if (!isInList(num, numbers)) {
                    // Handle number not in list
                    cout << "❌ Invalid input! Please enter a number from the summoned list.\n";
                }
            }
        }

        // User picks 3 even numbers
        for (int i = 0; i < 3; ++i) {
            int num;
            while (true) {
                cout << "Enter an even number: ";
                cin >> num;

                // Validate input:
                //   - Number between 1 and 50
                //   - Even number
                //   - Number is in the list
                if (num >= 1 && num <= 50 && num % 2 == 0 && isInList(num, numbers)) {
                    selectedEvenNumbers.push_back(num);        // Add number to selected even numbers
                    removeFromList(num, numbers);              // Remove number from main numbers list
                    cout << "✔️ " << num << " added to the defensive spells.\n";
                    break;
                } else if (num < 1 || num > 50) {
                    // Handle invalid range input
                    cout << "❌ Invalid input! Please enter a number between 1 and 50.\n";
                } else if (num % 2 != 0) {
                    // Handle odd number input
                    cout << "❌ Invalid input! Please enter an even number.\n";
                } else if (!isInList(num, numbers)) {
                    // Handle number not in list
                    cout << "❌ Invalid input! Please enter a number from the summoned list.\n";
                }
            }
        }

        // Sort the selected numbers in ascending order
        sort(selectedOddNumbers.begin(), selectedOddNumbers.end());
        sort(selectedEvenNumbers.begin(), selectedEvenNumbers.end());

        // Display the sorted selections
        cout << "\n🔮 The Witch Craft Heap Sorting Ritual Begins 🔮\n";
        cout << "Sorted Offensive (Odd) Numbers: ";
        displayVector(selectedOddNumbers);
        cout << "Sorted Defensive (Even) Numbers: ";
        displayVector(selectedEvenNumbers);

        // Generate random monster power level between 120 and 250
        int monsterPower = rand() % 131 + 120; // rand() % 131 generates 0 to 130, so adding 120 gives 120 to 250
        cout << "\nA monstrous foe with a power level of " << monsterPower << " appears!\n";

        // Sum up the values of the selected numbers to get the user's total power
        int totalPower = 0;
        for (int num : selectedOddNumbers) totalPower += num;
        for (int num : selectedEvenNumbers) totalPower += num;

        cout << "\nYour combined magic power is " << totalPower << ".\n";

        if (totalPower < monsterPower) {
            // User's power is less than monster's power
            --attempts;  // Lose a life
            cout << "💔 Your power is insufficient! You lose 1 life.\n";

            // Remove the selected numbers from the game
            clearSelectedNumbers(selectedOddNumbers, selectedEvenNumbers, numbers);

            cout << "You have " << attempts << " lives remaining.\n";
        } else if (totalPower == monsterPower) {
            // User's power is equal to monster's power
            cout << "✨ You're an Average Player! You matched the monster's power! ✨\n";
            break;  // Exit the loop, game over with a neutral outcome
        } else {
            // User's power exceeds monster's power
            cout << "🎉 You are the Best! Your power exceeds the monster's! 🎉\n";
            break;  // Exit the loop, game over with victory
        }

        if (attempts > 0) {
            // Inform the user they have another chance
            cout << "\nThe witch grants you another chance to try again!\n";
        }
    }

    if (attempts == 0) {
        // User has no lives left, game over
        cout << "\nGame Over! The monster has defeated you. 🧙‍♀️💀\n";
    }

    return 0;  
}