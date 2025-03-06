class Solution {
public:

    int func(vector<int>& count,int s)
    {
        while(s<10)
        {
            if(count[s]>0)
            {
                count[s]--;
                return 1;
            }
            s+=3;
        }
        return 0;
    }

    string largestMultipleOfThree(vector<int>& digits) 
    {
        if(digits.size()==1)
        {
            if(digits[0]%3)
            return "";
            else
            return to_string(digits[0]);
        }
        sort(digits.begin(), digits.end(), greater<int>());
        
        vector<int> count(10, 0);
        int sum = 0;

        for (int digit : digits) {
            count[digit]++;
            sum += digit;
        }

        if (sum % 3 == 1) {
            if (!func(count, 1)) {
                // If unable to remove one remainder-1 number, remove two remainder-2 numbers
                if (!func(count, 2) || !func(count, 2)) return "";
            }
        } 
        else if (sum % 3 == 2) {
            if (!func(count, 2)) {
                // If unable to remove one remainder-2 number, remove two remainder-1 numbers
                if (!func(count, 1) || !func(count, 1)) return "";
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
