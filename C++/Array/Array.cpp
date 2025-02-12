#include <iostream>
using namespace std;

const int SIZE = 4; // Array size constant. The array will contain 4 elements
int arr[SIZE] = {13, 15, 197, 25}; // Initialize the array with some default values. The array has a fixed size of 4.

// Function to print the elements of the array
void printArray() {
    // Iterate over the entire array and print each element in a new line
    // This function does not modify the array, it simply reads and prints its contents.
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << endl;
    }
}

// Function to insert a value at a specific index (position) in the array
void insertarr(int arr[], int key, int place) {
    // Check if the provided index for insertion is valid.
    // Insertion position must be between 0 and SIZE inclusive.
    // If the position is out of bounds, display an error and return without making any changes.
    if (place < 0 || place > SIZE) {
        cout << "Invalid insertion position!" << endl;
        return; // Exit early if the position is invalid
    }

    // We need to make room for the new element by shifting elements starting from the end of the array
    // This ensures that we do not overwrite any existing elements when inserting at a specific position.
    for (int i = SIZE - 1; i > place; i--) {
        // Shift elements one position to the right to make space for the new element at the specified position
        arr[i] = arr[i - 1]; 
    }
    
    // Now that there is enough space, insert the new element at the specified index
    arr[place] = key;
}

// Function to delete an element from the array at a specific index (position)
void delarr(int arr[], int rmplace) {
    // Check if the provided index for removal is valid.
    // The position to be removed must be within the valid range of the array.
    if (rmplace < 0 || rmplace >= SIZE) {
        cout << "Invalid deletion position!" << endl;
        return; // Exit early if the position is invalid
    }

    // After deletion, we need to shift all subsequent elements one position to the left to fill the gap
    for (int i = rmplace; i < SIZE - 1; i++) {
        // Shift elements one position to the left to remove the element at 'rmplace'
        arr[i] = arr[i + 1];
    }

    // Optional: After shifting, we can set the last element of the array to zero (or any other value) as a cleanup step
    // This is useful if you need to maintain a consistent state in the array after deletion.
    arr[SIZE - 1] = 0; // This step is optional, as the last element is already logically removed.
}

// Function to perform a linear search for an element in the array
int linearSearch(int arr[], int find) {
    // Iterate through the array from the first element to the last
    // Linear search works by comparing each element to the search value.
    for (int i = 0; i < SIZE; i++) { 
        // If the element matches the search value, return the index where it was found
        if (arr[i] == find) {
            cout << "Element found! Index is: " << i << endl;
            return i; // Return the index of the found element
        }
    }
    // If the loop completes without finding the element, we return -1 to indicate failure
    cout << "Element not found!" << endl; // Display message when element is not found in the array
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
