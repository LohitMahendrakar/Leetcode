#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> stack;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue; // ignore empty and current directory
            } 
            else if (token == "..") {
                if (!stack.empty()) stack.pop_back();
            } 
            else {
                stack.push_back(token);
            }
        }

        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i != stack.size() - 1) result += "/";
        }

        return result;
    }
};
