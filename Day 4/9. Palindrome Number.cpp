class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long reversed = 0;
        long long temp = x;
        while(temp > 0 ) {
            int onesPlaceDigit = temp % 10;
            reversed = reversed * 10 + onesPlaceDigit;
            temp /= 10;
        }

        return (x == reversed);
    }
};