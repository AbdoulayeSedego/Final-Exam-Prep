#include <iostream>
using namespace std;

// getting user input
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter grade " << (i + 1) << ": ";
        cin >> arr[i];
    }
}

// calculate the average grade of students
double calculateAverage(const int arr[], int size) {
    if (size <= 0) return 0.0;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    // to ensure floating-point division
    return static_cast<double>(sum) / size;
}

// find the highest grade
int findMax(const int arr[], int size) {
    if (size <= 0) return 0;

    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
// find the lowest grade
int findMin(const int arr[], int size) {
    if (size <= 0) return 0;
    int min = arr[0];
    for (int i = 1; i < size; i++){
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
// display all grades
void displayGrades(const int arr[], int size) {
    for (int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }

}

//main function
int main() {
    const int SIZE = 5;
    int grades[SIZE];

    // Get grades from user
    fillArray(grades, SIZE);

    // Display all grades
    cout << "\nAll grades:" << endl;
    displayGrades(grades, SIZE);

    // Display statistics
    cout << "\nStatistics:" << endl;
    cout << "Average: " << calculateAverage(grades, SIZE) << endl;
    cout << "Highest: " << findMax(grades, SIZE) << endl;
    cout << "Lowest: " << findMin(grades, SIZE) << endl;

    return 0;
}