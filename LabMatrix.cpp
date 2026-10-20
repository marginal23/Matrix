/*******************************
* Автор: Сатин Владимир        *
* Вариант: 10                  *
* Название: Обработка массивов *
*******************************/
#include <iostream>
#include <vector>
using namespace std;

int max(vector<int> nums) {
    int first = nums[0];

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] > first) {
            first = nums[j];
        }
    }

    return first;
}

int min(vector<int> nums) {
    int first = nums[0];

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] < first) {
            first = nums[j];
        }
    }

    return first;
}

int main() {
    int rows, columns;

    cout << "rows = ";
    cin >> rows;

    cout << "columns = ";
    cin >> columns;

    vector<vector<int>> MatrixB(rows, vector<int>(columns));

    // Input the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> MatrixB[i][j];
        }
    }

    // Print the original matrix
    cout << "\nOriginal matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << MatrixB[i][j] << "\t";
        }
        cout << endl;
    }

    // Find the maximum and minimum in each row and swap them
    for (int i = 0; i < rows; i++) {
        int maxValue = max(MatrixB[i]);
        int minValue = min(MatrixB[i]);

        int maxIndex = 0;
        int minIndex = 0;

        // Find the index of the maximum element
        for (int j = 0; j < columns; j++) {
            if (MatrixB[i][j] == maxValue) {
                maxIndex = j;
                break;
            }
        }

        // Find the index of the minimum element
        for (int j = 0; j < columns; j++) {
            if (MatrixB[i][j] == minValue) {
                minIndex = j;
                break;
            }
        }

        // Swap the maximum and minimum elements
        swap(MatrixB[i][maxIndex], MatrixB[i][minIndex]);
    }

    // Print the modified matrix
    cout << "\nModified matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << MatrixB[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}