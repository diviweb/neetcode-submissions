class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left <= right) {
            while(left < right && !isAlphaNumeric(s[left]))
                left++;
            while(right > left && !isAlphaNumeric(s[right]))
                right--;
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            else {
                left++;
                right--;
            }    
        }
        return true;
    }

    bool isAlphaNumeric(char s) {
        return ((s >= '0' && s <= '9') || (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'));
    }
};
