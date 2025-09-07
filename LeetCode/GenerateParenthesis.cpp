// // Generate Parenthesis
// Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.

// Example 1 :

//     Input : n = 3 Output : [ "((()))", "(()())", "(())()", "()(())", "()()()" ]

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp;
        generateParenthesishelper(n, ans, 0, 0, temp);
        return ans;
    }

    void generateParenthesishelper(int n, vector<string> &ans, int left, int right, string temp)
    {

        if (left + right == 2 * n)
        { // Base conditon where all possible parenthesis are added
            ans.push_back(temp);
            return;
        }

        // At each step we can add either '(' or ')'

        // add '('  when left is still less than the number of pairs
        if (left < n)
        {
            temp.push_back('(');
            generateParenthesishelper(n, ans, left + 1, right, temp);
            temp.pop_back();
        }
        // We only add ')' if it won’t break validity
        if (right < left)
        {
            temp.push_back(')');
            generateParenthesishelper(n, ans, left, right + 1, temp);
            temp.pop_back();
        }
    }
};