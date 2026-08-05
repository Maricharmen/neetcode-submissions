class Solution {
public:

    bool isAlpha(char a){
        char c = tolower(a);
        if( (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))return true;
        return false;
    }

    bool isPalindrome(string s) {
        int l = 0, h = s.size()-1;

        while( l < h ){

            while( l < h && !isAlpha(s[l]) ) l++;
            
            while( l < h && !isAlpha(s[h]) ) h--;

            char start = tolower(s[l]);
            char end = tolower(s[h]);


            if( start != end ) return false;
            l++;
            h--;

        }

        return true;
    }
};
