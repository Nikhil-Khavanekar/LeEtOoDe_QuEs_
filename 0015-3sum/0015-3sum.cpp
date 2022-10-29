class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i==0 || (i>0 and (nums[i]!=nums[i-1]))){
                int lo=i+1;
                int hi=n-1;
                int sum=0-nums[i];
                while(lo<hi){
                    if(nums[lo]+nums[hi]==sum){
                        res.push_back(vector<int>{nums[i],nums[lo],nums[hi]});
                        
                        while(lo<hi and nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi and nums[hi]==nums[hi-1]) hi--;
                        
                        lo++;
                        hi--;
                    }
                    else if(nums[lo]+nums[hi]<sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return res;
    }
};