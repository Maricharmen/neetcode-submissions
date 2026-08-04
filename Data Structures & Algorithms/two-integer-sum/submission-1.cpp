class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> looking;

        for( int i=0 ; i < nums.size() ;  i++ ){
            int find = target-nums[i];
             
            if( looking.count(find) ){
                return {looking[find], i};
            }

            looking[nums[i]] = i;

        }

        return {};

    }
};
