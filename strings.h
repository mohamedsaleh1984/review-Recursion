#ifndef STRINGS_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class StringsAlgo {
public:
    bool IsPalendromic(std::string str) {
        if (str.length() == 0 || str.length() == 1)
            return true;
        
        if (str[0] == str[str.length() - 1])
        {
            str = str.substr(1, str.length() - 2);
            return IsPalendromic(str);
        }
        return false;
    }
    //Solution Ref : https://leetcode.com/problems/generate-parentheses/discuss/1847972/C%2B%2B-simple-approach-of-Recursion-and-backtracking.
    //Problem : https://leetcode.com/problems/generate-parentheses
    vector<string> generateParenthesis(int n) {
        string output;
        vector<string> out;
        generateParenthesisHelper(out, output, n, 0, 0, 0);
        return out;
    }
private:
    void generateParenthesisHelper(vector<string>& out, string output, int n, int open, int close, int i) {
        //base case
        if (i == 2 * n) {
            out.push_back(output);
            return;
        }
        //recursive case 
        if (open < n) {
            generateParenthesisHelper(out, output + '(', n, open + 1, close, i + 1);
        }
        if (close < open) {
            generateParenthesisHelper(out, output + ')', n, open, close + 1, i + 1);
        }
    }
};
#endif // !STRINGS_H
