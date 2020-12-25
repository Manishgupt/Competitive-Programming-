//Method-1) ***Naive Approach***
//Time Complexity-Theta(n^2)
//space Complexity-O(n)

/*steps-itertate loop from 1 to n-1
        find left max
        find right max
        apply formula=min(leftMAx,Rightmax)-arr[i];
*/

#include<iostream>
using namespace std;
#include<algorithm>
int totalWater(int *arr,int n)
{
    int total=0;
    for(int i=1;i<n-1;i++)
    {   
        int lmax=arr[i],Rmax=arr[i];
        //lmax
        for(int l=0;l<i;l++)
            lmax=max(arr[l],lmax);
        
        //Rmax
        for(int R=i+1;R<n;R++)
            Rmax=max(arr[R],Rmax);

        total+=min(lmax,Rmax)-arr[i];
    }
    return total;
}
int main(int argc, char const *argv[])
{
    int arr[]={1,2,3,4};
    int n=5;
    cout<<totalWater(arr,n);
    return 0;
}

/************************************************************************************/
//Method-2) Optimize Approach
Time Complexity=Theta(n)
Space Complexity=O(n)

#include<iostream>
using namespace std;
#include<algorithm>
int totalWater(int *arr,int n)
{
    int total=0;
    int lmax[n],Rmax[n];
    lmax[0]=arr[0];
    for(int i=1;i<n;i++){
        lmax[i]=max(arr[i],lmax[i-1]);
    }
    Rmax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        Rmax[i]=max(arr[i],Rmax[i+1]);
    }

    for(int i=1;i<n-1;i++)
    {   
       total+=min(lmax[i],Rmax[i])-arr[i];
    }
    return total;
}
int main(int argc, char const *argv[])
{
    int arr[]={6,6,6,3,3};
    int n=5;
    cout<<totalWater(arr,n);
    return 0;
}
/*******************************************************************/

//Method-3)Efficient and Best method

T(c)=O(n)
S(c)=O(1);
/*steps-----> 1)initialize two variable which keep on pointing to the first and last index
             2)iterate loop from start to end
             3)initialize two varirable maxleft and rightmax which keep track max of left and right
	     4)Two pointer Approach is used here
	     5)youtube link for understand-https://www.youtube.com/watch?v=lthRF-FN7R0 

#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
	while(t--)
	{
	    int size;
	    cin>>size;
	    int arr[size];
	    for(int i=0;i<size;i++)
	        cin>>arr[i];
	   int low=0,high=size-1,maxleft=0,maxright=0,res=0;
	   while(low<high)
	   {
	       if(arr[low]<=arr[high])
	       {
	           maxleft=max(maxleft,arr[low]);
	           res+=maxleft-arr[low];
	           low++;
	       }
	       else
	       {
	           maxright=max(maxright,arr[high]);
	           res+=maxright-arr[high];
	           high--;
	       }
	   }
	   cout<<res;
	}
	return 0;
}