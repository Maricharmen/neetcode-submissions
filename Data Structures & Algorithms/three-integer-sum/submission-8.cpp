class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());

        for(int i=0; i <= size-3; i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;
            int target = -1*nums[i];    
            int low = i+1, high = size-1;
            //  -1, -1, 0, 1, 2, 4 
            while( low < high ){
                int sum = nums[low] + nums[high];
                if( sum == target){
                    triplets.push_back({nums[i], nums[low], nums[high]});
                    while( low < high && nums[high] == nums[high-1]) high--;
                    while( low < high && nums[low] == nums[low+1] ) low++;
                    high--;
                    low++;
                }else if( sum > target){
                    high--;
                }else if( sum < target){ 
                    low++;
                }

            }
        }

        return triplets;
    }
};

// 1 + 2 + k == 0
// 1 + 2 - 3 == 0 -> 1 + 2 = 3
// a+b == -c -> -c = -(a+b)
// [-1,0,1,2,-1,4]
// [-1, -1, 0, 1, 2, 4]
/*
-1 4 -3 -> 2 times

-1 -> 1

[-1, -1, 0, 1, 2, 4]
 |             |
-1 + 4 = 3
-1 + 2 = 1

-1 -1 2 = 0

*/