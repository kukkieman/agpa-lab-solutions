#include<iostream>
#include<stdlib.h>
#include<time.h>

#define n 9

#define m 5

using namespace std;

char valid_keys[5]={'r', 'g', 'b', 'w'};

bool is_blank_above(char grid[n][m], int a, int b){
 for(; a>=0; --a){
   if(grid[a][b]!='0'){
     return false;
   }
 }
 return true;
}

void input_grid(char grid[n][m]){
 for(int i=0; i<n; i++){
   for(int j=0; j<m; j++){
     cin>>grid[i][j];
   }
 }
}

void output_grid(char grid[n][m]){
 for(int i=0; i<n; i++){
   for(int j=0; j<m; j++){
     cout<<grid[i][j]<<" ";
   }
   cout<<endl;
 }
}

void collapse_blank(char grid[n][m]){
 for(int j=0; j<m; j++){
   for(int i=n-1; i>=0; i--){
     if(!is_blank_above(grid, i, j)){
       while(grid[i][j]=='0'){
         for(int k=i; k>0; k--){
           grid[k][j]=grid[k-1][j];
           grid[k-1][j]='0';
         }
       }
     }
   }
 }
}

void rand_fill(char grid[n][m]){
 for(int i=0; i<n; i++){
   for(int j=0; j<m; j++){
     if(grid[i][j]=='0'){
       grid[i][j]=valid_keys[rand()%4];
     }
   }
 }
}

void clear_cell(char grid[n][m], int count, int i, int j, char mode){
 switch(mode){
   case 'h': while(count--){
               grid[i][j++]='0';
             }
             break;

   case 'v': while(count--){
               grid[i++][j]='0';
             }
             break;
 }
}

void h_check(char grid[n][m]){
 for(int i=0; i<n; i++){
   for(int j=0; j<m; j++){
     int count=0, k=j;
     do{
       count++;
       k++;
     }while(grid[i][j]==grid[i][k]);
     if(count>=3){
       clear_cell(grid, count, i, j, 'h');
     }
   }
 }
}

void v_check(char grid[n][m]){
 for(int j=0; j<m; j++){
   for(int i=0; i<n; i++){
     int count=0, k=i;
     do{
       count++;
       k++;
     }while(grid[i][j]==grid[k][j]);
     if(count>=3){
       clear_cell(grid, count, i, j, 'v');
     }
   }
 }
}

int main(){
 srand(time(NULL));
 char grid[n][m];
 input_grid(grid);
 h_check(grid);
 v_check(grid);
 getchar();
 system("cls");
 cout<<"\nAfter clear_cell():"<<endl;
 output_grid(grid);
 cout<<"\nAfter collapse_blank():"<<endl;
 collapse_blank(grid);
 output_grid(grid);
 cout<<"\nAfter rand_fill():"<<endl;
 rand_fill(grid);
 output_grid(grid);
 return 0;
} 
