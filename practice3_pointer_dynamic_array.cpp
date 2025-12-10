#include <iostream>
using namespace std;

// Part C: Function with pointer parameter
void doubleValue(int* ptr) {
    *ptr = *ptr * 2;  // Doubles the value at the given address
}

int main() {
    // ==========================================
    // PART A: Basic Pointers
    // ==========================================
    cout << "=== PART A: Basic Pointers ===" << endl;

    int var = 42;       // Declare an integer variable
    int* ptr = &var;    // Declare a pointer pointing to var

    cout << "Variable value (var): " << var << endl;
    cout << "Variable address (&var): " << &var << endl;
    cout << "Pointer value (ptr): " << ptr << endl;
    cout << "Dereferenced pointer (*ptr): " << *ptr << endl;
    cout << endl;

    // ==========================================
    // PART B: Dynamic Array
    // ==========================================
    cout << "=== PART B: Dynamic Array ===" << endl;

    // Dynamically allocate an array of 5 integers
    int* arr = new int[5];

    // Fill using pointer arithmetic (not array notation)
    for (int i = 0; i < 5; i++) {
        *(arr + i) = (i + 1) * 10;  // Values: 10, 20, 30, 40, 50
    }

    // Print values using pointer arithmetic
    cout << "Array values (using pointer arithmetic):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(arr + " << i << ") = " << *(arr + i) << endl;
    }

    // Properly deallocate using delete[]
    delete[] arr;
    arr = nullptr;  // Set to nullptr after deletion (see Part D)
    cout << "Array deallocated successfully." << endl;
    cout << endl;

    // ==========================================
    // PART C: Function with Pointer Parameter
    // ==========================================
    cout << "=== PART C: Function with Pointer Parameter ===" << endl;

    int num = 25;
    cout << "Before doubleValue(): num = " << num << endl;

    doubleValue(&num);  // Pass address of num

    cout << "After doubleValue(): num = " << num << endl;
    cout << "(Demonstrates that the original variable was modified)" << endl;
    cout << endl;

    // ==========================================
    // PART D: Avoid Memory Issues (with explanations)
    // ==========================================
    cout << "=== PART D: Memory Issues (see comments in code) ===" << endl;

    /*
     * MEMORY LEAK:
     * A memory leak occurs when dynamically allocated memory is not deallocated
     * (using delete or delete[]) before the pointer to it goes out of scope or
     * is reassigned. The memory remains allocated but becomes inaccessible,
     * causing the program to consume more and more memory over time.
     *
     * Example of a memory leak:
     *   int* p = new int[100];
     *   p = new int[200];  // LEAK! The first allocation is now lost
     *   // Or simply forgetting to call delete[] before the function ends
     */

    /*
     * DANGLING POINTER:
     * A dangling pointer is a pointer that points to memory that has been
     * deallocated (freed). Accessing a dangling pointer leads to undefined
     * behavior - it may crash, return garbage values, or appear to work
     * but cause subtle bugs.
     *
     * Example of a dangling pointer:
     *   int* p = new int(42);
     *   delete p;          // Memory is freed
     *   cout << *p;        // DANGER! p is now a dangling pointer
     */

    // Demonstrating proper pointer handling after deletion:
    int* safePtr = new int(100);
    cout << "Before delete: *safePtr = " << *safePtr << endl;

    delete safePtr;
    safePtr = nullptr;  // Set to nullptr after deletion to avoid dangling pointer

    cout << "After delete: safePtr set to nullptr" << endl;

    // Now we can safely check before using:
    if (safePtr != nullptr) {
        cout << *safePtr << endl;
    } else {
        cout << "Pointer is null - safe to detect!" << endl;
    }

    return 0;
}
