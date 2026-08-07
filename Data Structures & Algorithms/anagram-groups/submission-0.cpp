/*


*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> listAnagrams;
        int index = 0;
        map<string, int> look; 

        for( string word : strs ){
            string oriWord = word; 
            sort( word.begin(), word.end());
            if( look.count(word) ){
                listAnagrams[look[word]].push_back(oriWord);
            }else{
                listAnagrams.push_back({oriWord});
                look[word] = index;
                index++;
            }
        }

        return listAnagrams;
    }
};
