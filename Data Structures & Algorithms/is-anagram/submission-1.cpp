class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> letters; 

        for( char c : s ) letters[c]++;
        for( char c : t ){
            if( !letters[c] ) return false; 
            letters[c]--;
            
        }

        for(auto c : letters){
            if( c.second ) return false;
        }
         
        return true;
        
    }
};
