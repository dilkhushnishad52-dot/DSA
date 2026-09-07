class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string ans = "";
       if(strs.empty()) return "";
       sort(strs.begin(), strs.end());
       string first = strs[0];
       string sec = strs[strs.size()-1];
       int minlength = min(first.size(), sec.size());
       for(int i=0; i<minlength; i++){
         if(first[i] != sec[i]) break;
         ans += first[i];
        }
        return ans;
    }
};