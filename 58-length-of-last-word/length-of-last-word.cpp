class Solution {
public:
    int lengthOfLastWord(string s) {
        long ans = 0;
        int i = s.size()-1;
        while(i >= 0){
            if(s[i] == ' '){
                ans += 0;
            }
            else{
                ans += 1;
            }
            if(ans != 0 && s[i] == ' ') break;
            i--;
        }
        return ans;
    }
};