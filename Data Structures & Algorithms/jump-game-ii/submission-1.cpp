class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, maxcurrentEnd = 0, nextEnd = 0, maxnextEnd = 0;

        if ( nums.size() == 1) return 0;

        while( currentEnd < nums.size()){
            currentEnd = nextEnd;
            maxcurrentEnd = nums[currentEnd] + currentEnd;

            while( currentEnd  < nums.size() && currentEnd <= maxcurrentEnd){
                if( nums[currentEnd] + currentEnd > maxnextEnd){
                    maxnextEnd = nums[currentEnd] + currentEnd;
                    nextEnd = currentEnd;
                }
                currentEnd++;
            }

            jumps++;
        }

        return jumps;

    
    }
};
