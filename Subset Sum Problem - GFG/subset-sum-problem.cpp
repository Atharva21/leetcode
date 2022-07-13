// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    bool isSubsetSum(vector<int>arr, int sum){
        const int n = arr.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<=sum;++i) dp[0][i] = false; // 👈 if we have no elements, we cant achieve any amount of sum
        for(int i=0;i<=n;++i) dp[i][0] = true; // 👈 if sum == 0, we have already achieved is subset sum with a empty subset
        // dp[0][0] = true;
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=sum;++j) {
                if(arr[i-1] <= j) { // choose
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // for(int i=0;i<=n;++i) {
        //     for(int j=0;j<=sum;++j) {
        //         cout << dp[i][j] ? "1 " : "0 ";
        //     }
        //     cout << endl;
        // }
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends