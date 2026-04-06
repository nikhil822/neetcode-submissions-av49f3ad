class Solution {
    string ans;
public:
    void helper(string num) {
        if(ans == "") {
            ans = num;
            return;
        }

        int i = num.size() - 1, j = ans.size() - 1, carry = 0;
        string temp = "";

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += num[i--] - '0';
            if(j >= 0) sum += ans[j--] - '0';

            temp += (sum % 10) + '0';
            carry = sum / 10;
        }

        reverse(temp.begin(), temp.end());
        ans = temp;
    }

    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        ans = "";
        int n = num1.size(), m = num2.size();
        int pdZero = 0;

        for(int i = n - 1; i >= 0; i--) {
            string temp = "";
            int carry = 0;

            for(int j = m - 1; j >= 0; j--) {
                int prod = (num1[i] - '0') * (num2[j] - '0') + carry;
                temp += (prod % 10) + '0';
                carry = prod / 10;
            }

            if(carry) temp += (carry + '0');

            reverse(temp.begin(), temp.end());

            // add zeros
            temp += string(pdZero, '0');
            pdZero++;

            helper(temp);
        }

        return ans;
    }
};