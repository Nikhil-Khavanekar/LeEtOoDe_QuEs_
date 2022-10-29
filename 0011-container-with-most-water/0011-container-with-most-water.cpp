class Solution {
public:
    int maxArea(vector<int>& arr) {
        int maxi=0;
        int lo=0;
        int hi=arr.size()-1;
        while(lo<hi){
            int left=arr[lo];
            int right=arr[hi];
            int max_height;
            if(left>right){
                max_height=right;
            }
            else{
                max_height=left;
            }
            maxi=max(maxi,max_height*(hi-lo));
            
            if(arr[lo]>=arr[hi]){
                hi--;
            }
            else{
                lo++;
            }
        }
        return maxi;
    }
};