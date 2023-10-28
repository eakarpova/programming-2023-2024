#include <iostream>
using namespace std;

// Function prototypes
void showMenu();
int getInput();
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);
void addMatrices(int matrix1[][3], int matrix2[][3], int result[][3]);
void subtractMatrices(int matrix1[][3], int matrix2[][3], int result[][3]);

int main() {
    int choice = 0;
    int num1, num2;
    int matrix1[3][3], matrix2[3][3], result[3][3];

    do {
        showMenu();
        choice = getInput();

        switch (choice) {
        case 1:
            cout << "Enter two numbers to add: ";
            cin >> num1 >> num2;
            cout << "Result: " << add(num1, num2) << endl;
            break;
        case 2:
            cout << "Enter two numbers to subtract: ";
            cin >> num1 >> num2;
            cout << "Result: " << subtract(num1, num2) << endl;
            break;
        case 3:
            cout << "Enter two numbers to multiply: ";
            cin >> num1 >> num2;
            cout << "Result: " << multiply(num1, num2) << endl;
            break;
        case 4:
            cout << "Enter two numbers to divide: ";
            cin >> num1 >> num2;
            cout << "Result: " << divide(num1, num2) << endl;
            break;
        case 5:
            cout << "Enter the first matrix (3x3):" << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cin >> matrix1[i][j];
                }
            }
            cout << "Enter the second matrix (3x3):" << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cin >> matrix2[i][j];
                }
            }
            addMatrices(matrix1, matrix2, result);
            cout << "Result:" << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 6:
            cout << "Enter the first matrix (3x3):" << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cin >> matrix1[i][j];
                }
            }
            cout << "Enter the second matrix (3x3):" << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cin >> matrix2[i][j];
                }
            }
            subtractMatrices(matrix1, matrix2, result);
            cout << "Result:" << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 7);

    return 0;
}

// Function definitions
void showMenu() {
    cout << "Menu:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Add matrices" << endl;
    cout << "6. Subtract matrices" << endl;
    cout << "7. Exit" << endl;
}

int getInput() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice > 7) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid input. Please enter a number between 1 and 7: ";
        cin >> choice;
    }
    return choice;
}

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    if (y == 0) {
        cout << "Error: division by zero" << endl;
        return 0;
    }
    return x / y;
}

void addMatrices(int matrix1[][3], int matrix2[][3], int result[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[][3], int matrix2[][3], int result[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}