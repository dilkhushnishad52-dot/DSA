class Solution {
public:
    string largestOddNumber(string num) {
       int ind = -1;
       int j = num.length()-1;
       while(j >= 0){
          int n = num[j] - '0';
          if(n % 2 == 1){
            ind = j;
            break;
          }
          j--;
        }
        int i=0;
        while(i <= ind && num[i] == '0') i++;
        return num.substr(i, ind-i+1); 
    }
};