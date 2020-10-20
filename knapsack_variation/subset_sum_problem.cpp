Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Example:

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.




bool isSubsetSum(int set[], int n, int sum) 
{ 
    // Base Cases 
    if (sum == 0) 
        return true; 
    if (n == 0) 
        return false; 
  
    // If last element is greater than sum, 
    // then ignore it 
    if (set[n - 1] > sum) 
        return isSubsetSum(set, n - 1, sum); 
  
    /* else, check if sum can be obtained by any  
of the following: 
      (a) including the last element 
      (b) excluding the last element   */
    return isSubsetSum(set, n - 1, sum) 
           || isSubsetSum(set, n - 1, sum - set[n - 1]); 
} 


set[]={3, 4, 5, 2}
target=6
 
    0    1    2    3    4    5    6

0   T    F    F    F    F    F    F

3   T    F    F    T    F    F    F
     
4   T    F    F    T    T    F    F   
      
5   T    F    F    T    T    T    F

2   T    F    T    T    T    T    T






#include <stdio.h> 
  
// Returns true if there is a subset of set[] 
// with sun equal to given sum 
bool isSubsetSum(int set[], int n, int sum) 
{ 
    // The value of subset[i][j] will be true if 
    // there is a subset of set[0..j-1] with sum 
    // equal to i 
    bool subset[n + 1][sum + 1]; 
  
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
  
    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
  
    // Fill the subset table in botton up manner 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < set[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= set[i - 1]) 
                subset[i][j] = subset[i - 1][j] 
                               || subset[i - 1][j - set[i - 1]]; 
        } 
    } 
  
    /*   // uncomment this code to print table 
     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", subset[i][j]); 
       printf("\n"); 
     }*/
  
    return subset[n][sum]; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int set[] = { 3, 34, 4, 12, 5, 2 }; 
    int sum = 9; 
    int n = sizeof(set) / sizeof(set[0]); 
    if (isSubsetSum(set, n, sum) == true) 
        printf("Found a subset with given sum"); 
    else
        printf("No subset with given sum"); 
    return 0; 
} 
// This code is contributed by Arjun Tyagi. 