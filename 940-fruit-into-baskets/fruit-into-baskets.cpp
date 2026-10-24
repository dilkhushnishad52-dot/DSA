class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0; 
        int r = 0;
        int maxlen = 0;
        unordered_map<int, int> mapp;
        while(r < fruits.size()){
            mapp[fruits[r]]++;
            if(mapp.size() > 2){
                mapp[fruits[l]]--;
                if(mapp[fruits[l]] == 0) mapp.erase(fruits[l]);
                l++;
            }
            if(mapp.size() <= 2) maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};