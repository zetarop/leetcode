    bool checkSubarraySum(vector<int>& nums, int k) {
        
        //O(n) time | O(n) space
        int sum = 0;
        unordered_map<int, int> M{{0, -1}}; // most left index where sum appears
        for(int i = 0; i < nums.size(); i++){
            
            int ele = nums[i];
            sum += ele;
            if(k) sum %= k;
            
            if(M.find(sum) != M.end()){
                if(i - M[sum] > 1) return true;
            }else{  
                M[sum] = i; // most left index where sum appear
            }
            
        }
        return false;
    }
