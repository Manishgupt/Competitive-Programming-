/*
{{10, 20, 30, 40},
  {15, 25, 35, 45},
  {27, 29, 35, 45},
  {32, 33, 39, 50}};

  spiral matrix of above 2-D array is {10,20,30,40,45,45,50,39,33,32,27,15,23,35,35,29}


  keep start from (0,0) to (0,3)
                  (1,2) to (3,3)
                  (3,2) to (3,0)
                  (2,0) to (1,0)
                  then keep doing this
*/
#include <bits/stdc++.h> 
using namespace std;

class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
    vector<int> res;
    int top = 0, left = 0, bottom = r - 1, right = c - 1;

	while(top <= bottom && left <= right)
	{   //traverse from left to right
		for(int i = left; i <= right; i++)
			res.push_back(mat[top][i]);

		top++;
        //traverse from top to bottom
		for(int i = top; i <= bottom; i++)
			res.push_back(mat[i][right]);
		
		right--;
        //traverse from right left
		if(top <= bottom){
		for(int i = right; i >= left; i--)
			res.push_back(mat[bottom][i]);

		bottom--;
		}
        //traverse from bottom to top
		if(left <= right){
		for(int i = bottom; i >= top; i--)
			res.push_back(mat[i][left]);

		left++;
		}			
    }
    //return the result
    return res;
    }
};