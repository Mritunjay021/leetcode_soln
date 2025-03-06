class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) 
    {
        if(digits.size()==1)
        {
            if(digits[0]%3)
            return "";
            else
            return to_string(digits[0]);
        }
        sort(digits.begin(), digits.end(), greater<int>());  // Sort in descending order
        
        vector<int> count(10, 0);
        int sum = 0;

        for (int digit : digits) {
            count[digit]++;
            sum += digit;
        }

        auto removeSmallest = [&](int rem) {
            for (int i = 0; i <= 9; i++) {
                if (count[i] > 0 && i % 3 == rem) {
                    count[i]--;
                    return true;
                }
            }
            return false;
        };

        if (sum % 3 == 1) {
            if (!removeSmallest(1)) {
                removeSmallest(2);
                removeSmallest(2);
            }
        } 
        else if (sum % 3 == 2) {
            if (!removeSmallest(2)) {
                removeSmallest(1);
                removeSmallest(1);
            }
        }

        string result = "";
        for (int i = 9; i >= 0; i--) {
            while (count[i]--) {
                result += to_string(i);
            }
        }

        return (result[0] == '0') ? "0" : result;
    }
};
