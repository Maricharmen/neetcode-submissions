class Solution {
public:

    pair<int, int> binary_search(int sub, const vector<int>& numbers, int index){

            int left = index + 1, right = numbers.size()-1;

            while( left <= right ){
                int mid = left + (right - left) / 2 ;

                if( numbers[mid] == sub ){
                    return {mid, 1};
                }else if( numbers[mid] > sub){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }

            return {0,0};
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for( int i=0; i<numbers.size(); i++){
            int sub = target-numbers[i];
            pair<int, int> index = binary_search(sub, numbers, i);
            if( index.second ) return {i+1, index.first+1};
        }

        return {};

    }
};
