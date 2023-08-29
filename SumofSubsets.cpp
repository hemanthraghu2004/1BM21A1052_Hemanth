#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool f(int ind,int target,int arr[],  vector<vector<int>>&dp)
{   if (target==0) return true;
    if(ind==0)
     return arr[0]==target;
     
    if(dp[ind][target]!=-1)  return dp[ind][target];
    bool nt=0+f(ind-1,target,arr,dp);
    bool t=false;
    if(arr[ind]<=target) t=f(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target]=t|nt;
}
int main()
{
  int arr[]= {3, 34, 4, 12, 5, 2};
  int k=599;
  int n=6;
  vector<vector<int>>dp(n,vector<int>(k+1,-1)) ;
  bool ans=f(n-1,k,arr,dp);
  if(ans) cout<<"TRUE";
  else cout<<"FALSE";
}
