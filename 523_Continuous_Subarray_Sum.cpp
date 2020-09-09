    bool checkSubarraySum(vector<int>& nums, int k) {
        
        // O(n^2) time | O(n) space
        vector<int> cum(nums.size());
        cum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            cum[i] = nums[i] + cum[i - 1];
        }
        for(int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++){
                
                int sum = cum[j] - cum[i] + nums[i];
                if(k == 0 && sum == 0)
                    return true;
                else if(k == 0 && sum != 0) continue;
                if(sum%k == 0)
                    return true;
            }
        return false;
    }
