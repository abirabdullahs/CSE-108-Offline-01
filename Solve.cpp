#include <bits/stdc++.h>
using namespace std;

class figure{
  private:
    int row;
    int col;
    string name;
    double **matrix;
    
    void setName(){
      if(row == 2 && col == 2) name = "line2D";
      else if(row == 2 && col == 3) name = "line3D";
      else if(row == 3 && col == 2) name = "Triangle2D";
      else if(row == 3 && col == 3) name = "Triangle3D";
      else if(row == 4 && col == 2) name = "Rectangle2D";
      else if(row == 4 && col == 3) name = "Rectangle3D";
      else name = "Unknown";
    }
    
    void allocateMatrix(){
      matrix = new double*[row];
      for(int i = 0; i < row; i++){
        matrix[i] = new double[col];
      }
    }
    
    void deAllocateMatrix(){
      if(matrix != nullptr){
        for(int i = 0; i < row; i++){
          delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;
      }
    }

    
  public:
    
    figure(){
      row = 0;
      col = 0;
      name = "";
      matrix = nullptr;
    }
    
    
    figure(int r, int c, double *arr){
      row = r;
      col = c;
      
      allocateMatrix();
      
      int idx = 0;
      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
          matrix[i][j] = arr[idx++];
        }
      }
      
      setName();
    }
    
    
    figure(const figure& other){
      row = other.row;
      col = other.col;
      name = other.name;

      if(other.matrix != nullptr){
        allocateMatrix();
        for(int i = 0; i < row; i++){
          for(int j = 0; j < col; j++){
            matrix[i][j] = other.matrix[i][j];
          }
        }
      }
      else matrix = nullptr;
    }
    
    
    ~figure(){
      if(!name.empty())
        cout << name << " has been destroyed" << endl;

      deAllocateMatrix();
      row = 0;
      col = 0;
    }
     
     
   int getSum(int r, int c){
     if(r > row || c > col || r < 0 || c < 0){
       cout<<"input invalid"<<endl;
       return 0;
     }
     
     int sum = 0;
     for(int i = 0; i < r; i++){
       for(int j = 0; j < c; j++){
         sum += matrix[i][j];
       }
     }
     
     return sum;
   }
   
   int getSum(){
     return getSum(row, col);
   }
   
   int getRow() const { return row; }
   int getCol() const { return col; }
   string getName() const { return name; }
    
   void display(){
     cout<<"rows: "<<row<<endl;
     cout<<"columns: "<<col<<endl;
     
     for(int i = 0; i < row; i++){
       for(int j = 0; j < col; j++){
         cout<<matrix[i][j]<<" ";
       }
       cout<<endl;
     }
   }   
    
};

int main() {
    cout << " Testing Figure Class " << endl;
    
    // Test 1: Default Constructor
    cout << "\nTest 1: Default Constructor" << endl;
    figure f1;
    cout << "Default object created with row=" << f1.getRow() 
         << ", col=" << f1.getCol() << endl;
    
    // Test 2: Triangle 2D
    cout << "\n Test 2: Triangle 2D" << endl;
    double arr1[] = {0, 0, 3, 0, 1, 4};
    figure triangle2D(3, 2, arr1);
    triangle2D.display();
    cout << "Sum of all elements: " << triangle2D.getSum() << endl;
    cout << "Sum of first 2 rows and 2 cols: " << triangle2D.getSum(2, 2) << endl;
    
    // Test 3: Line 3D
    cout << "\n Test 3: Line 3D" << endl;
    double arr2[] = {1, 2, 3, 4, 5, 6};
    figure line3D(2, 3, arr2);
    line3D.display();
    cout << "Sum of all elements: " << line3D.getSum() << endl;
    
    // Test 4: Rectangle 2D
    cout << "\n Test 4: Rectangle 2D " << endl;
    double arr3[] = {0, 0, 5, 0, 5, 3, 0, 3};
    figure rect2D(4, 2, arr3);
    rect2D.display();
    cout << "Sum of all elements: " << rect2D.getSum() << endl;
    cout << "Sum of first 3 rows and 2 cols: " << rect2D.getSum(3, 2) << endl;
    
    // Test 5: Clone Constructor
    cout << "\nTest 5: Clone Constructor" << endl;
    figure clonedTriangle(triangle2D);
    clonedTriangle.display();
    cout << "Cloned sum: " << clonedTriangle.getSum() << endl;
    
    // Test 6: Error handling in getSum
    cout << "\n Test 6: Error Handling " << endl;
    triangle2D.getSum(5, 5);  // invalid input
    
    // Test 7: Float type replaced by double for compatibility
    cout << "\n Test 7: Triangle with double float values" << endl;
    double arr4[] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5};
    figure triangleFloat(3, 2, arr4);
    triangleFloat.display();
    cout << "Sum of all elements: " << triangleFloat.getSum() << endl;
    
    cout << "\n Destructors will be called " << endl;
    
    return 0;
}