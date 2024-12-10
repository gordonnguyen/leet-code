/*
20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/


class Solution {
public:
    bool isValid(string s) {
        //Use stack
        //If encounter opening bracket, push to top
        //If encounter closing bracket, peek the stack if its the same type
        //      If stack empty or not the same type, return false 
        //return true if loop complete
        
        int total_char = 3;
        char opening_brackets[3] = {'(','{','['};
        char closing_brackets[3] = {')','}',']'};
        stack<char> stack;

        for (int i = 0;i < s.size(); i++) {
            for (int j=0; j < total_char; j++) {
                if (s[i] == opening_brackets[j]) {
                    stack.push(s[i]);
                }
                else if (s[i] == closing_brackets[j]) {
                    if (!(stack.empty()) && (stack.top() == opening_brackets[j])) {
                        stack.pop();
                    }
                    else {return false;}
                }
            }
        }
        // Check if theres unsolved opening bracket
        if (!(stack.empty())) {
            return false;
        }
        return true;

    }
};
