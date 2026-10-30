class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int l = 0;
        int r = 0;
        int cnt = 0;
        int minlen = INT_MAX;
        int sindex = -1;
        for(int i=0; i<t.size(); i++){
            hash[t[i]]++;
        }
        while(r < s.size()){
            if(hash[s[r]] > 0) cnt = cnt + 1;
            hash[s[r]]--;
            while(cnt == t.size()){
                if(r - l + 1 < minlen){
                    minlen = r - l + 1;
                    sindex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt = cnt - 1;
                l++;
            }
            r = r + 1;
        }
        return sindex == -1 ? "" : s.substr(sindex,minlen);
    }
};