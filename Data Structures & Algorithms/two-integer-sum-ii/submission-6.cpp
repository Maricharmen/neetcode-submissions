class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size()-1;
        vector<int> indexes(2);
        while( numbers[low] + numbers[high] != target){
            int sum = numbers[low] + numbers[high];

            if( sum > target ){
                high--;
            }else if(sum < target){
                low++;
            }
        
        }
        
        indexes[0] = low+1; indexes[1] = high+1;

        return indexes;

    }
};
