#include <bits/stdc++.h>
using namespace std;


class figure{
  private:
    double row;
    double col;
    string name;
    double **matrix;
    
    
    void setName(){
      name = row == 2 && (col == 2)? "line2D" : "line3D";
      name = row == 3 && (col == 2)? "Triangle2D" : "Triangle3D";
      name = row == 4 && (col == 2)? "Rectangle2D" : "Rectangle3D";
    }
    
    
    void allocateMatrix(){
      matrix = new double *[row];
      
      for(int i=0; i<row; i++){
        matrix[i] = new double [col];
      }
    }
    
    
    void deAllocateMatrix(){
      matrix != nullptr && {
        for(int i=0; i<row; i++){
          delete[] matrix[i];
        }
        
        delete[] matrix[];
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
      
      for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
          matrix[i][j] = arr[idx++];
        }
      }
      
      
      setName();
      
      
    }
    
    
    figure(const figure& other){
      row = other.row;
      col = other.col;
      name = other.name;
      
      
     if (other.matrix != nullptr)
      {
        for(int i=0; i<row; i++){
          for(int j=0; j<col; j++){
            matrix[i][j] = other.matrix[i][j];
          }
        }
      } 
      
      else 
       {
         matrix = nullptr;
       }
      
    }
    
    
    
    
    ~figure(){
        if(name) cout<<name<<" has been destroyed"<<endl;
          
        if(matrix != nullptr ){
          for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
              matrix[i][j] = 0;
            }
          }
        }
        
        
        deAllocateMatrix();
        row = 0;
        col = 0;
        
     }
     
     
   int getSum(int r, int c){
     
     int sum = 0;
     int valid = (r>row || c>col || r<0 || c<0) 0 : 1;
     
    
     if(!valid) {
       cout<<"input invalid"<<endl;
       
       return 0;
       
     }
     
     for(int i=0; i<r; i++){
       for(int j=0; j<c; j++){
         sum = sum + matrix[i][j];
       }
     }
     
     return sum;
   }
   
   
   int getSum(){
     return getSum(row, col);
   }
   
   
   
   int getRow() const {return row;}
   int getCol() const {return col;}
   string getName() const {return name;}
    
   
   
   
   void display(){
     cout<<"rows : "<<row<<endl;
     cout<<" columns: "<<col<<endl;
     
     for(int i=0; i<row; i++){
       for(int j=0; j<col; j++){
         cout<<matrix[i][j]<<" ";
       }
       
       cout<<endl;
     }
   }   
    
};

int main()
{
    cout<<" Default Object created"<<endl;
    
    figure f1;
    cout<<"rows :"<<f1.row<<endl;
    cout<<"columns: "<<f1.col<<endl;
    
    
    
}