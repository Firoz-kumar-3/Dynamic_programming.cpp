if n%3==0 then n=n/3;
if n%2==0 then n=n/2;
else n=n-1;


//using recursion and memorization top down dp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fin_min_step(int n,int dp[])
{  
	
	int option1=INT_MAX;
	int option2=INT_MAX;
	int option3=INT_MAX;
	
	if(n==1)
	  return 0;
	  
	if(dp[n]!=0)
	 return dp[n];
	 
	if(n%3==0)
	  option1=fin_min_step(n/3,dp);
	  
	if(n%2==0)
	  option2=fin_min_step(n/2,dp);
	option3=fin_min_step(n-1,dp);
	dp[n]=min(min(option1,option2),option3)+1;
	return dp[n];
}

int main() {
	// your code goes here
	int n;
//	cin>>n;
    n=10;
    int dp[100]={0};
	cout<<fin_min_step(n,dp);
	return 0;
}




//botom up dp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fin_min_step(int n)
{  
		int dp[100]={0};
		dp[1]={0};
	
	for(int i=2;i<=n;i++)
	{  
		int option1=INT_MAX;
		int option2=INT_MAX;
		int option3=INT_MAX;
		if(i%3==0){
		 option1=dp[i/3];
		}
		if(i%2==0){
          option2=dp[i/2];
		}
	   option3=dp[i-1];
	   
       dp[i]=(min(min(option1,option2),option3)+1);	         
	}
	return dp[n];
}

int main() {
	// your code goes here
	int n;
//	cin>>n;
     n=10;
	cout<<fin_min_step(n);
	return 0;
}
