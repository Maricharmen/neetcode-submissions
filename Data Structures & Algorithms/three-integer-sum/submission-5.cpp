class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for( int index=0; index<nums.size()-2; index++){

            if( index > 0 && nums[index] == nums[index-1]) continue;

            int left = index + 1, right = nums.size()-1;

            while( left < right ){ // -2 0 1 1 2

                long long sum = nums[left] + nums[right] + nums[index];

                if( sum == 0){
                    result.push_back({nums[index], nums[left], nums[right]}); 
                    left++;right--; 
                    while( left < right && nums[left] == nums[left-1])left++;
                    while( left < right && nums[right] == nums[right+1])right--;    
                }else if( sum > 0 ) right--;
                else if (sum < 0) left++;

            }
        }

        return result;
    }
};
