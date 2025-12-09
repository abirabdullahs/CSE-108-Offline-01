# C++ Figure Class - Problem Statement

## 📌 Problem Overview

You need to create a **template class** called `Figure` that represents geometric figures (like lines, triangles, rectangles) in 2D or 3D space. The class will store coordinate points in a dynamic 2D matrix and perform various operations on them.

---

## 🎯 Objectives

The main objectives of this assignment are to demonstrate:

1. **Encapsulation** - Using private data members with public getter methods
2. **Constructors** - Implementing default, parameterized, and copy constructors
3. **Destructor** - Proper memory deallocation and cleanup
4. **Dynamic Memory Management** - Using `new` and `delete` operators
5. **Templates** - Creating generic classes that work with different data types
6. **Code Reuse** - Writing functions that call other functions to avoid redundancy
7. **Error Handling** - Validating inputs and handling edge cases

---

## 📋 Class Requirements

### Private Data Members

Your `Figure` class must have the following **private** member variables:

| Variable | Type | Purpose |
|----------|------|---------|
| `row` | `int` | Stores the number of points in the figure |
| `col` | `int` | Stores the dimension of the space (2D or 3D) |
| `name` | `string` | Stores the name of the figure (e.g., "Line2D", "Triangle3D") |
| `matrix` | `T**` | 2D dynamic array storing coordinate points |

---

## 🔧 Required Functions

### Helper Functions (Private)

#### 1. `allocateMatrix()`
- **Purpose:** Allocate memory for the 2D matrix
- **Steps:**
  - Allocate memory for `row` number of rows
  - For each row, allocate memory for `col` number of columns
  - Use dynamic memory allocation with `new` operator

#### 2. `deallocateMatrix()`
- **Purpose:** Free the allocated memory safely
- **Steps:**
  - Check if matrix is not null
  - Delete each row using `delete[]`
  - Delete the matrix pointer array
  - Set matrix to `nullptr`

#### 3. `setNameAutomatically()`
- **Purpose:** Automatically set the figure name based on dimensions
- **Naming Rules:**

| Row | Col | Name |
|-----|-----|------|
| 2 | 2 | Line2D |
| 2 | 3 | Line3D |
| 3 | 2 | Triangle2D |
| 3 | 3 | Triangle3D |
| 4 | 2 | Rectangle2D |
| 4 | 3 | Rectangle3D |

---

### Public Constructors

#### 1. Default Constructor
- **Purpose:** Initialize an empty figure
- **Requirements:**
  - Set `row = 0`
  - Set `col = 0`
  - Set `name = ""`
  - Set `matrix = nullptr`

#### 2. Parameterized Constructor
- **Signature:** `Figure(int r, int c, T* arr)`
- **Parameters:**
  - `r` - number of points (rows)
  - `c` - dimension of space (columns)
  - `arr` - 1D array containing all coordinate values
- **Requirements:**
  - Set row and col values
  - Allocate memory for matrix
  - Convert 1D array to 2D matrix
  - Set name automatically

**Example Conversion:**
```
Input:  arr[] = {0, 0, 3, 0, 1, 4}
Output: matrix[0][0]=0, matrix[0][1]=0
        matrix[1][0]=3, matrix[1][1]=0
        matrix[2][0]=1, matrix[2][1]=4
```

#### 3. Copy Constructor (Deep Copy)
- **Signature:** `Figure(const Figure& other)`
- **Purpose:** Create an independent copy of an existing figure
- **Requirements:**
  - Copy row, col, and name from the other object
  - Allocate **new** memory for matrix
  - Copy all elements from other's matrix
  - Must be a **deep copy**, not a shallow copy

---

### Destructor

- **Purpose:** Clean up memory when object is destroyed
- **Requirements:**
  - Print destruction message: `"[name] has been destroyed"`
  - Set all matrix elements to zero
  - Call `deallocateMatrix()` to free memory
  - Reset row and col to 0

---

### Public Methods

#### 1. `getSum()` - Without Parameters
- **Return Type:** `T`
- **Purpose:** Calculate sum of ALL elements in the matrix
- **Implementation:** Call `getSum(row, col)` to demonstrate code reuse

#### 2. `getSum(int m, int n)` - With Parameters
- **Return Type:** `T`
- **Parameters:**
  - `m` - number of rows to include (0 to m-1)
  - `n` - number of columns to include (0 to n-1)
- **Purpose:** Calculate partial sum of first m rows and n columns
- **Requirements:**
  - Validate input: check if `m > row` OR `n > col` OR `m < 0` OR `n < 0`
  - If invalid, print error message and return 0
  - If valid, calculate and return the sum

**Error Message Format:**
```
Error: Invalid range! m must be <= [row] and n must be <= [col]
```

#### 3. Getter Methods (for Encapsulation)
- `int getRow() const` - Returns the row value
- `int getCol() const` - Returns the col value
- `string getName() const` - Returns the name

#### 4. `display()`
- **Purpose:** Display figure information
- **Output Format:**
  ```
  Figure: [name]
  Rows: [row], Cols: [col]
  Matrix:
  [matrix elements row by row]
  ```

---

## 🧪 Test Cases to Implement

### Test 1: Default Constructor
- Create a figure using default constructor
- Verify row and col are 0

### Test 2: Triangle in 2D Space
- **Input:** `{0, 0, 3, 0, 1, 4}` with 3 rows, 2 cols
- **Expected:**
  - Name: "Triangle2D"
  - Sum of all elements: 8
  - Sum of first 2 rows, 2 cols: 3

### Test 3: Line in 3D Space
- **Input:** `{1, 2, 3, 4, 5, 6}` with 2 rows, 3 cols
- **Expected:**
  - Name: "Line3D"
  - Sum of all elements: 21

### Test 4: Rectangle in 2D Space
- **Input:** `{0, 0, 5, 0, 5, 3, 0, 3}` with 4 rows, 2 cols
- **Expected:**
  - Name: "Rectangle2D"
  - Sum of all elements: 16
  - Sum of first 3 rows, 2 cols: 13

### Test 5: Copy Constructor (Deep Copy)
- Create a clone of the triangle from Test 2
- Verify it has the same values
- Verify it's an independent copy (deep copy)

### Test 6: Error Handling
- Call `getSum(5, 5)` on a 3×2 triangle
- Expected: Error message displayed
- Call `getSum(-1, 2)`
- Expected: Error message displayed

### Test 7: Template with Float Type
- **Input:** `{0.5, 1.5, 2.5, 3.5, 4.5, 5.5}` with 3 rows, 2 cols
- Create `Figure<float>` object
- **Expected:** Sum = 18.0

### Test 8: Destructor Verification
- When program ends, destructors should be called automatically
- Destruction messages should appear in **reverse order** of creation
- Example: If objects were created as A, B, C → destroyed as C, B, A

---

## 📊 Marks Distribution (Total: 19 Marks)

| Component | Marks | Description |
|-----------|-------|-------------|
| **Encapsulation** | 3 | Private variables + getter methods + data hiding |
| **Default Constructor** | 1 | Proper initialization to zero/null |
| **Parameterized Constructor** | 4 | 1D to 2D conversion + automatic naming |
| **Copy Constructor** | 2 | Deep copy with new memory allocation |
| **Destructor** | 3 | Message + zeroing + memory deallocation |
| **getSum() no parameters** | 2 | Demonstrates code reuse |
| **getSum(m,n) with parameters** | 2 | Input validation + error handling |
| **Code Reuse** | 2 | Calling one function from another |

---

## 💡 Important Concepts

### 1. Encapsulation
- All data members must be **private**
- Access to data only through **public getter methods**
- This protects data from unauthorized access

### 2. Deep Copy vs Shallow Copy

**Shallow Copy (❌ Wrong):**
```cpp
matrix = other.matrix;  // Just copies pointer
```

**Deep Copy (✅ Correct):**
```cpp
// Allocate new memory
matrix = new T*[row];
// Copy all values
for (int i = 0; i < row; i++) {
    matrix[i] = new T[col];
    for (int j = 0; j < col; j++) {
        matrix[i][j] = other.matrix[i][j];
    }
}
```

### 3. Memory Management Rules
- Every `new` must have a corresponding `delete`
- Delete arrays with `delete[]`, not just `delete`
- Set pointers to `nullptr` after deletion
- Check for `nullptr` before deletion

### 4. Code Reuse
Instead of writing the same logic twice:
```cpp
T getSum() {
    return getSum(row, col);  // Reuses existing function
}
```

### 5. Template Usage
The class works with any data type:
```cpp
Figure<int> intFigure(3, 2, intArray);
Figure<float> floatFigure(3, 2, floatArray);
Figure<double> doubleFigure(3, 2, doubleArray);
```

---

## 📝 Expected Sample Output

```
===== Test 1: Default Constructor =====
Row: 0
Col: 0

===== Test 2: Triangle 2D =====
Figure: Triangle2D
Rows: 3, Cols: 2
Matrix:
0 0 
3 0 
1 4 
Sum: 8
Partial Sum (2x2): 3

===== Test 3: Line 3D =====
Figure: Line3D
Rows: 2, Cols: 3
Matrix:
1 2 3 
4 5 6 
Sum: 21

===== Test 6: Error Handling =====
Error: Invalid range! m must be <= 3 and n must be <= 2
Error: Invalid range! m must be <= 3 and n must be <= 2

===== Program Ending - Destructors will be called =====
Triangle2D has been destroyed
Line3D has been destroyed
Rectangle2D has been destroyed
```

---

## ⚠️ Common Mistakes to Avoid

1. **Shallow Copy in Copy Constructor** - Must allocate new memory
2. **Memory Leaks** - Forgetting to delete allocated memory
3. **Not Setting nullptr** - After deletion, always set pointer to nullptr
4. **Wrong delete Syntax** - Use `delete[]` for arrays, not `delete`
5. **Missing Validation** - Always validate inputs in getSum(m, n)
6. **Not Using Code Reuse** - getSum() should call getSum(row, col)

---

## 🎯 Learning Outcomes

After completing this assignment, you will be able to:

✅ Implement encapsulation using access specifiers  
✅ Work with dynamic memory allocation and deallocation  
✅ Create template classes for generic programming  
✅ Implement proper copy constructors with deep copy  
✅ Write destructors that properly clean up resources  
✅ Demonstrate code reuse through function calls  
✅ Handle errors and validate inputs  
✅ Understand object lifecycle (construction → usage → destruction)

---


## 📘 Reference

- View explanation: [explanation02.md](explanation02.md)
- View solution: [Solve.cpp](Solve.cpp)

---
**Good Luck with Your Assignment! 🚀**