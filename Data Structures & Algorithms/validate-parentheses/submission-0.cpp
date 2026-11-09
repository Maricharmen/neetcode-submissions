class Solution {
public:
    bool isValid(string s) {
        stack<char> S;

        for( char c : s ){
            if( c == '[' || c == '{' || c == '('){
                S.push(c);
            }else{
                if( S.empty()) return false;
                else if( S.top() == '[' && c == ']'){
                    S.pop();
                }else if( S.top() == '{' && c == '}'){
                    S.pop();
                }else if( S.top() == '(' && c == ')'){
                    S.pop();
                }else return false;
            }
        }

        if( !S.empty() ) return false;

        return true;
        
    }
};
