#include <iostream>
#include "String.h"

using namespace std;

void showMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Print current string\n";
    cout << "2. Get string length\n";
    cout << "3. Find substring\n";
    cout << "4. Remove substring\n";
    cout << "5. Insert substring\n";
    cout << "6. Concatenate with another string\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

int main() {
    int maxSize;
    cout << "Enter maximum size for the string (1-255): ";
    cin >> maxSize;

    String myStr(maxSize);
    cout << "Enter the initial string: ";
    cin >> myStr;

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Current string: [" << myStr << "]\n";
            break;
        case 2:
            cout << "Length: " << myStr.length() << " / " << myStr.getSize() << "\n";
            break;
        case 3: {
            String subStr(maxSize);
            cout << "Enter substring to find: ";
            cin >> subStr;
            int pos = myStr.find(subStr);
            if (pos != -1) cout << "Found at position (1-based): " << pos << "\n";
            else cout << "Substring not found.\n";
            break;
        }
        case 4: {
            int index, count;
            cout << "Enter start index (1-based) and count of characters to remove: ";
            cin >> index >> count;
            myStr.remove(index, count);
            cout << "String after removal: " << myStr << "\n";
            break;
        }
        case 5: {
            int index;
            String subStr(maxSize);
            cout << "Enter index (1-based) to insert at: ";
            cin >> index;
            cout << "Enter substring to insert: ";
            cin >> subStr;
            myStr.insert(index, subStr);
            cout << "String after insertion: " << myStr << "\n";
            break;
        }
        case 6: {
            String otherStr(maxSize);
            cout << "Enter string to concatenate: ";
            cin >> otherStr;
            myStr = myStr + otherStr;
            cout << "String after concatenation: " << myStr << "\n";
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}