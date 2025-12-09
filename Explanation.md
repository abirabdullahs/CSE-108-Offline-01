```cpp```
```#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Figure {
private:
    // TODO: Declare row variable (int type)
    // Purpose: stores number of points in the figure
    
    // TODO: Declare col variable (int type)
    // Purpose: stores dimension of the figure space
    
    // TODO: Declare name variable (string type)
    // Purpose: stores name like "Line2D", "Triangle3D", etc.
    
    // TODO: Declare matrix variable (T** type - 2D dynamic array)
    // Purpose: stores the coordinate points of the figure
    
    
    // ========== Helper Functions (for Code Reuse) ==========
    
    // TODO: Create allocateMatrix() function
    // What to do:
    // 1. Allocate memory for matrix[row][col]
    // 2. Use dynamic memory allocation (new operator)
    void allocateMatrix() {
        // Your code here
    }
    
    
    // TODO: Create deallocateMatrix() function
    // What to do:
    // 1. Check if matrix is not null
    // 2. Delete each row first (delete[] matrix[i])
    // 3. Then delete the matrix itself (delete[] matrix)
    // 4. Set matrix = nullptr
    void deallocateMatrix() {
        // Your code here
    }
    
    
    // TODO: Create setNameAutomatically() function
    // What to do:
    // 1. Check row value (2, 3, or 4)
    // 2. Check col value (2 or 3)
    // 3. Set name accordingly:
    //    - row=2, col=2 → "Line2D"
    //    - row=2, col=3 → "Line3D"
    //    - row=3, col=2 → "Triangle2D"
    //    - row=3, col=3 → "Triangle3D"
    //    - row=4, col=2 → "Rectangle2D"
    //    - row=4, col=3 → "Rectangle3D"
    void setNameAutomatically() {
        // Your code here
    }

public:
    // ========== Constructor 1: Default Constructor ==========
    // TODO: Implement default constructor
    // What to do:
    // 1. Set row = 0
    // 2. Set col = 0
    // 3. Set name = "" (empty string)
    // 4. Set matrix = nullptr
    Figure() {
        // Your code here
    }
    
    
    // ========== Constructor 2: Parameterized Constructor ==========
    // TODO: Implement parameterized constructor
    // Parameters:
    // - r: number of rows (points)
    // - c: number of columns (dimensions)
    // - arr: 1D array containing all coordinate values
    //
    // What to do:
    // 1. Set row = r
    // 2. Set col = c
    // 3. Call allocateMatrix() to allocate memory
    // 4. Convert 1D array to 2D matrix:
    //    - Use a loop with index variable
    //    - For each position (i,j): matrix[i][j] = arr[index++]
    //    - Example: arr[] = {x1,y1,x2,y2,x3,y3}
    //      becomes: matrix[0][0]=x1, matrix[0][1]=y1,
    //               matrix[1][0]=x2, matrix[1][1]=y2, etc.
    // 5. Call setNameAutomatically() to set the name
    Figure(int r, int c, T* arr) {
        // Your code here
    }
    
    
    // ========== Constructor 3: Clone/Copy Constructor ==========
    // TODO: Implement copy constructor
    // Parameter:
    // - other: reference to another Figure object (const Figure& other)
    //
    // What to do:
    // 1. Copy row from other.row
    // 2. Copy col from other.col
    // 3. Copy name from other.name
    // 4. Check if other.matrix is not null
    // 5. If not null:
    //    - Call allocateMatrix() to allocate new memory
    //    - Use nested loops to copy all elements from other.matrix
    // 6. If null:
    //    - Set matrix = nullptr
    // 
    // NOTE: This must be a DEEP COPY, not shallow copy
    Figure(const Figure& other) {
        // Your code here
    }
    
    
    // ========== Destructor ==========
    // TODO: Implement destructor
    // What to do:
    // 1. Display destruction message: "[name] has been destroyed"
    //    Example: "Triangle2D has been destroyed"
    // 2. Check if matrix is not null
    // 3. If not null, set all matrix elements to zero using nested loops
    // 4. Call deallocateMatrix() to free memory
    // 5. Set row = 0
    // 6. Set col = 0
    ~Figure() {
        // Your code here
    }
    
    
    // ========== Method 1: getSum() without parameters ==========
    // TODO: Implement getSum() that returns sum of ALL elements
    // What to do:
    // 1. Simply call getSum(row, col) and return its result
    // 2. This demonstrates CODE REUSE
    //
    // Return type: T (template type)
    T getSum() {
        // Your code here
    }
    
    
    // ========== Method 2: getSum(m, n) with parameters ==========
    // TODO: Implement getSum(m, n) for partial sum
    // Parameters:
    // - m: number of rows to include (0 to m-1)
    // - n: number of columns to include (0 to n-1)
    //
    // What to do:
    // 1. Validate input:
    //    - Check if m > row OR n > col OR m < 0 OR n < 0
    //    - If invalid, print error message and return 0
    //    - Error message: "Error: Invalid range! m must be <= [row] and n must be <= [col]"
    // 2. If valid:
    //    - Create variable sum = 0
    //    - Use nested loops: i from 0 to m-1, j from 0 to n-1
    //    - Add matrix[i][j] to sum
    //    - Return sum
    //
    // Return type: T (template type)
    T getSum(int m, int n) {
        // Your code here
    }
    
    
    // ========== Getter Methods (for Encapsulation) ==========
    // TODO: Implement getter methods to access private variables
    
    // Returns the value of row
    int getRow() const {
        // Your code here
    }
    
    // Returns the value of col
    int getCol() const {
        // Your code here
    }
    
    // Returns the value of name
    string getName() const {
        // Your code here
    }
    
    
    // ========== Display Method (Optional but useful) ==========
    // TODO: Implement display() to show figure details
    // What to do:
    // 1. Print the name of the figure
    // 2. Print "Rows: [row], Cols: [col]"
    // 3. Print "Matrix:" 
    // 4. Use nested loops to print all matrix elements
    //    - Each row on a new line
    //    - Elements separated by space
    void display() {
        // Your code here
    }
};


// ========== Main Function ==========
int main() {
    
    // ========== Test 1: Default Constructor ==========
    // TODO: Test default constructor
    // What to do:
    // 1. Create a Figure object using default constructor
    // 2. Print its row, col values using getter methods
    // 3. Verify they are 0
    cout << "===== Test 1: Default Constructor =====" << endl;
    // Your code here
    
    
    // ========== Test 2: Parameterized Constructor - Triangle 2D ==========
    // TODO: Create a Triangle in 2D space
    // What to do:
    // 1. Create array: int arr1[] = {0, 0, 3, 0, 1, 4};
    //    This represents points: (0,0), (3,0), (1,4)
    // 2. Create Figure object: Figure<int> triangle2D(3, 2, arr1);
    // 3. Call display() to show the matrix
    // 4. Call getSum() and print the result (should be 8)
    // 5. Call getSum(2, 2) and print the result (should be 3)
    cout << "\n===== Test 2: Triangle 2D =====" << endl;
    // Your code here
    
    
    // ========== Test 3: Parameterized Constructor - Line 3D ==========
    // TODO: Create a Line in 3D space
    // What to do:
    // 1. Create array: int arr2[] = {1, 2, 3, 4, 5, 6};
    //    This represents points: (1,2,3), (4,5,6)
    // 2. Create Figure object: Figure<int> line3D(2, 3, arr2);
    // 3. Call display() to show the matrix
    // 4. Call getSum() and print the result (should be 21)
    cout << "\n===== Test 3: Line 3D =====" << endl;
    // Your code here
    
    
    // ========== Test 4: Parameterized Constructor - Rectangle 2D ==========
    // TODO: Create a Rectangle in 2D space
    // What to do:
    // 1. Create array: int arr3[] = {0, 0, 5, 0, 5, 3, 0, 3};
    //    This represents points: (0,0), (5,0), (5,3), (0,3)
    // 2. Create Figure object: Figure<int> rect2D(4, 2, arr3);
    // 3. Call display() to show the matrix
    // 4. Call getSum() and print the result (should be 16)
    // 5. Call getSum(3, 2) and print the result (should be 13)
    cout << "\n===== Test 4: Rectangle 2D =====" << endl;
    // Your code here
    
    
    // ========== Test 5: Clone Constructor ==========
    // TODO: Test copy constructor
    // What to do:
    // 1. Create a clone of triangle2D: Figure<int> clonedTriangle(triangle2D);
    // 2. Call display() on clonedTriangle
    // 3. Verify that it has same values as original
    // 4. Call getSum() and verify result matches original
    cout << "\n===== Test 5: Clone Constructor =====" << endl;
    // Your code here
    
    
    // ========== Test 6: Error Handling in getSum(m, n) ==========
    // TODO: Test error handling
    // What to do:
    // 1. Try to call getSum(5, 5) on triangle2D (which has only 3 rows, 2 cols)
    // 2. Should print error message
    // 3. Try negative values: getSum(-1, 2)
    // 4. Should print error message
    cout << "\n===== Test 6: Error Handling =====" << endl;
    // Your code here
    
    
    // ========== Test 7: Template with Float Type ==========
    // TODO: Test template functionality with float
    // What to do:
    // 1. Create array: float arr4[] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5};
    // 2. Create Figure<float> object: triangleFloat(3, 2, arr4);
    // 3. Call display()
    // 4. Call getSum() and print result (should be 18.0)
    cout << "\n===== Test 7: Template with Float =====" << endl;
    // Your code here
    
    
    // ========== Test 8: Destructor ==========
    // TODO: Destructor will be called automatically
    // What to do:
    // 1. When program ends, all objects go out of scope
    // 2. Destructors will be called automatically
    // 3. You should see destruction messages printed
    // 4. Messages should be in reverse order of creation
    cout << "\n===== Program Ending - Destructors will be called =====" << endl;
    
    return 0;
}


// ========== Additional Notes ==========

MARKS DISTRIBUTION:
1. Encapsulation (3 marks)
   - All variables are private
   - Getter methods provided
   - Proper data hiding

2. Default Constructor (1 mark)
   - Initializes all values to zero/null

3. Parameterized Constructor (4 marks)
   - Takes r, c, and array as parameters
   - Converts 1D array to 2D matrix
   - Sets name automatically

4. Clone Constructor (2 marks)
   - Creates deep copy of object
   - Allocates new memory

5. Destructor (3 marks)
   - Prints destruction message
   - Sets all elements to zero
   - Deallocates memory

6. getSum() without parameters (2 marks)
   - Returns sum of all elements
   - Uses code reuse

7. getSum(m, n) with parameters (2 marks)
   - Returns partial sum
   - Validates input
   - Handles errors

8. Code Reuse (2 marks)
   - Helper functions used
   - No code duplication
   - getSum() calls getSum(m, n)

9. main() function (2 marks)
   - Tests all functionalities
   - Shows proper output

TOTAL: 20 marks

```
