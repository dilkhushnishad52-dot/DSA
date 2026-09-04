bool isAlphaNum(char ch){
    if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
        return true;
    }
    else{
        return false;
    }
}

class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.length()-1;
        while(st < end){
            if(!isAlphaNum(s[st])){
                st++;
                continue;
            }
            if(!isAlphaNum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st]) != tolower(s[end])){
                return false;
                break;
            }
            else{
                st++, end--;
            }
        }
        return true;
    }
};