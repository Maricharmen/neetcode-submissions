class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> prevNums;

        for( int i=0; i<numbers.size(); i++){
            int sub = target - numbers[i];
            if( prevNums.count(sub)){
                int index = prevNums[sub];
                return {index, i+1};
            }
            prevNums[numbers[i]] = i+1;
        } 
    }
};
