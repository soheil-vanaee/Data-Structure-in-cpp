## Arrays

In this code, I have implemented the **Array** data structure. Arrays are commonly used to store data that has a fixed size and consists of elements of the same type (e.g., integers).

To access elements of an array, we can use the **index**, which starts from 0 and increments by 1 for each element. 

In this code:
- The function **`printArray`** is used to traverse the array and display all of its elements. It has a time complexity of O(n), meaning that it processes each element of the array once.
- The function **`insertarr`** is used to insert a new element at a specific position in the array. Since arrays have a fixed size, adding an element requires shifting the existing elements to the right, which results in a time complexity of O(n), making it less efficient than other data structures for insertion.
- The function **`delarr`** removes an element from the array and replaces it with zero. This function also has a time complexity of O(n) because it requires shifting elements to the left to fill the gap after the element is removed.
- Finally, the **linear search** is implemented with a time complexity of O(n). It checks each element of the array sequentially and returns the index of the first matching element. This search continues until it either finds the element or completes the search without success. In a subsequent file, I will implement a more efficient search algorithm that has a time complexity of O(log n), which performs much faster.

---

## Binary Search

Binary Search is an improvement on the array search that works faster than linear search. However, there is an important caveat.

As shown in this code, I created an array with random elements. The issue with Binary Search is that the array must be **sorted** for it to work correctly. If the data is not sorted, the time spent sorting the array might negate the advantages of binary search.

After sorting the array, we can perform binary search. In this process, we divide the array into two parts, then compare the middle element to the target. Based on the result, we either search in the left half (if the target is smaller) or the right half (if the target is larger). This process continues, halving the search space with each step, until we find the target element.

---

This version keeps the explanation concise while maintaining clarity and providing detailed insights into the performance and limitations of arrays and search algorithms.