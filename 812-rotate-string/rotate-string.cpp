class Solution {
public:
    bool rotateString(string s, string goal) {
        string str = s + s;
        if(s.size() != goal.size()) return false;
        if(str.find(goal) != string :: npos) return true;
        return false;
    }
};