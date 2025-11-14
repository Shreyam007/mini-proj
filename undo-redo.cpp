#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> undoStack;
    stack<string> redoStack;
    string text = "";
    int choice;

    while (true) {
        cout << "\n====== TEXT EDITOR MENU ======\n";
        cout << "1. Type new text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Show current text\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();  // to ignore leftover newline

        if (choice == 1) {
            string newText;
            cout << "Enter new text to add: ";
            getline(cin, newText);
            undoStack.push(text);   // save current state for undo
            text += newText;
            // clear redoStack (since new text invalidates redo)
            while (!redoStack.empty()) redoStack.pop();
            cout << "Text updated!\n";

        } else if (choice == 2) {
            if (!undoStack.empty()) {
                redoStack.push(text);
                text = undoStack.top();
                undoStack.pop();
                cout << "Undo successful.\n";
            } else {
                cout << "Nothing to undo!\n";
            }

        } else if (choice == 3) {
            if (!redoStack.empty()) {
                undoStack.push(text);
                text = redoStack.top();
                redoStack.pop();
                cout << "Redo successful.\n";
            } else {
                cout << "Nothing to redo!\n";
            }

        } else if (choice == 4) {
            cout << "\nCurrent Text: " << text << "\n";

        } else if (choice == 5) {
            cout << "Exiting editor... Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
