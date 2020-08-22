knap_sack_problem.
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity 
of each item.In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an
integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot 
break an item, either pick the complete item, or don’t pick it (0-1 property).


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 int dp[1002][1002];
int knapsack(int wt[],int val[],int w,int n)
 {
     if(n==0 ||w==0)
      return 0;
     
     if(dp[n][w]!=-1) 
        return dp[n][w];
     if(wt[n-1]<=w)
      {
          dp[n][w]=max((val[n-1]+knapsack(wt,val,w-wt[n-1],n-1)),  knapsack(wt,val,w,n-1));
      }    
     else
     {
         dp[n][w]=knapsack(wt,val,w,n-1);
      
     }
   
   return dp[n][w];
 }

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   
        memset(dp,-1,sizeof(dp));
	    
	    int n,w;
	    cin>>n;
	    cin>>w;
	    int wt[n]={0};
	    int val[n]={0};
	    for(int i=0;i<n;i++)
	    {
	        cin>>val[i];
	    }
	    for(int i=0;i<n;i++)
	   {
	        cin>>wt[i];
	    }
	
	cout<<knapsack(wt,val,w,n)<<endl;
	}
	
	return 0;
}