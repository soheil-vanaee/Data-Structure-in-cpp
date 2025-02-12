#include <iostream>
using namespace std;

const int SIZE = 4; // Array size constant. The array will contain 4 elements
int arr[SIZE] = {13, 15, 197, 25}; // Initialize the array with some default values. The array has a fixed size of 4.

// Function to print the elements of the array
// This function iterates through the entire array and prints each element in a new line.
// It does not modify the array, but simply reads and displays its contents.
// The time complexity of this operation is O(n), where n is the size of the array.
void printArray() {
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << endl;
    }
}

// Function to insert a value at a specific index (position) in the array
// This function inserts the specified value 'key' into the array at the given position 'place'.
// If the position is out of bounds (less than 0 or greater than SIZE), an error message is displayed.
// To make room for the new element, the function shifts all elements starting from the last valid index 
// one position to the right. After making space, it inserts the new element at the given position.
// The time complexity of this operation is O(n) because of the need to shift elements.
void insertarr(int arr[], int key, int place) {
    // Check if the provided index for insertion is valid.
    // Insertion position must be between 0 and SIZE inclusive.
    if (place < 0 || place > SIZE) {
        cout << "Invalid insertion position!" << endl;
        return; // Exit early if the position is invalid
    }

    // We need to make room for the new element by shifting elements starting from the end of the array
    // This ensures that we do not overwrite any existing elements when inserting at a specific position.
    for (int i = SIZE - 1; i > place; i--) {
        arr[i] = arr[i - 1]; 
    }
    
    // Now that there is enough space, insert the new element at the specified index
    arr[place] = key;
}

// Function to delete an element from the array at a specific index (position)
// This function removes the element at the specified position and shifts all subsequent elements one position to the left.
// If the position is invalid (either less than 0 or greater than or equal to SIZE), an error message is displayed.
// After shifting the elements, the last element is optionally reset to zero, which can be considered as cleanup.
// The time complexity of this operation is O(n) due to the need to shift elements.
void delarr(int arr[], int rmplace) {
    // Check if the provided index for removal is valid.
    if (rmplace < 0 || rmplace >= SIZE) {
        cout << "Invalid deletion position!" << endl;
        return; // Exit early if the position is invalid
    }

    // After deletion, we need to shift all subsequent elements one position to the left to fill the gap
    for (int i = rmplace; i < SIZE - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Optional: After shifting, we can set the last element of the array to zero (or any other value) as a cleanup step
    // This is useful if you need to maintain a consistent state in the array after deletion.
    arr[SIZE - 1] = 0; 
}

// Function to perform a linear search for an element in the array
// This function iterates through the array from the first element to the last and compares each element to the target value.
// If a match is found, it returns the index of the first occurrence of the element.
// If no match is found, it returns -1 to indicate that the element is not present in the array.
// The time complexity of this search is O(n), meaning it may have to check all elements in the worst case.
int linearSearch(int arr[], int find) {
    // Iterate through the array from the first element to the last
    for (int i = 0; i < SIZE; i++) { 
        // If the element matches the search value, return the index where it was found
        if (arr[i] == find) {
            cout << "Element found! Index is: " << i << endl;
            return i; // Return the index of the found element
        }
    }
    // If the loop completes without finding the element, return -1 to indicate failure
    cout << "Element not found!" << endl;
    return -1; // Return -1 to indicate the element was not found
}

int main() {
    // Print the initial array
    cout << "Initial array: " << endl;
    printArray();

    // Define the key value to be inserted and the position at which to insert it
    int key = 1; // The value to be inserted into the array
    int place = 2; // The index where the value 'key' should be inserted

    // Call insertarr function to insert the value into the array at the given position
    insertarr(arr, key, place);

    // Print the array after the insertion to confirm that the element was added
    cout << "Array after insertion: " << endl;
    printArray();

    // Define the position from which we want to delete an element
    int rmplace = 2; // The index of the element to be removed

    // Call delarr function to delete the element at the given position
    delarr(arr, rmplace);

    // Print the array after the deletion to confirm that the element was removed
    cout << "Array after deletion: " << endl;
    printArray();

    // Define the element we want to search for in the array
    int find = 12; // The value to be searched in the array

    // Call linearSearch function to search for the value
    linearSearch(arr, find);

    return 0; // Return from main function
}
