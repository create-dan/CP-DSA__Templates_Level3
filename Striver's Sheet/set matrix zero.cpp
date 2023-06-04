#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//#SD
//https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8&ab_channel=takeUforward
//if all elements are positive , jab bhi 0 ayega to uske row and col ke
//sare non zero elements ko -1 kar do 
//aur jaha bhi -1 and 0 hai make them 0 O(n*m)*(n+m)


//appraoch two
//dummy array of size col and row
//ab jab bhi 0 ayega to col and row index mai 0 set kar do

//Most Optimal
//2 dummy array alag lene se achha inside the 2 d matrix le lenge
//1st row = as col dummy array
//1col= as row dymmy array
//variable col =true
//ab travere karo and 0 ayega to update 
//agar 0 pahle col mai aa raha hai to col = false kar do
// 2*(M * N)--> traverse the matrix twice
// space - constant
//



    void setZeroes(vector<vector<int>>& mat) {

        //flag var initially true
        int flag=1;
        int row = mat.size();
        int col = mat[0].size();

        for(int i=0;i<row;i++)
        {
               //agar col 0 mai koi bhi 0 aata hai to flag=0
               if(mat[i][0]==0) flag=0;


               //now traverse for rest of the columns
               for(int j=1;j<col;j++)
               {
                   //agar ye 0 hai to leftmost guy and uppar most guy ko bhi 0 karna
                   if(mat[i][j]==0){
                   mat[i][0]=0; //left most
                   mat[0][j]=0; //top mos
                   }
               }
        }


     //piche se traverse karo
     for(int i=row-1;i>=0;i--)
     {
         for(int j=col-1;j>=1;j--)
         {
             //agar dummy value 0 hai 
             //left most --> mat[i][0]
             //top most --> mat[0][j]

             int leftMost = mat[i][0];
             int topMost = mat[0][j];
             if(leftMost==0 || topMost==0)
             {
                 mat[i][j]=0;
                 
             }
              
             
         }
         if(flag==0) mat[i][0]=0;
        
     }

     


    }
};
