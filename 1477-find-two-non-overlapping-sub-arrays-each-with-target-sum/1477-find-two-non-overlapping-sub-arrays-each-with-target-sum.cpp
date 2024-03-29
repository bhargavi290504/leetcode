class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {   
    int l=0,r=0,sum=0,ans=INT_MAX;
        vector<int> dp(arr.size(),INT_MAX);
        for(;r<arr.size();r++){
            sum+=arr[r];
            while(sum>target)
                sum-=arr[l++];
            if(sum==target){
                dp[r]=r-l+1;
                if(l-1>=0 && dp[l-1]!=INT_MAX)
                    ans=min(ans,dp[r]+dp[l-1]);
            }
            if(r-1>=0)
                dp[r]=min(dp[r-1],dp[r]);
        }
        
        return ans==INT_MAX?-1:ans;
        
    }
};