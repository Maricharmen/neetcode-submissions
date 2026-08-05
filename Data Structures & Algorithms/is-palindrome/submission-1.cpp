class Solution {
public:

    bool isAlpha(char a){
        char c = tolower(a);
        if( (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))return true;
        return false;
    }

    bool isPalindrome(string s) {
        const char* left = s.data(); 
        const char* right = s.data() + s.size() - 1; 

        while( left < right ){

            while( left < right  && !isAlpha(*left) ) left++;
            
            while( left < right && !isAlpha(*right) ) right--;

            char start = tolower(*left);
            char end = tolower(*right);


            if( start != end ) return false;
            left++;
            right--;

        }

        return true;
    }
};
