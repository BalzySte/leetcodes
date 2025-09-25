#include <sstream>

// NOTE: it's possible to optimize the algorithm by avoiding the stringstream
//       construction and using the result string as a stack.

class Solution {
public:
    string simplifyPath(string path) {
        stack pathStack = stack<string>();
        stringstream ss(path);
        string node;
        string result;

        while(getline(ss, node, '/')) {
            if (node == "" || node == ".")
                continue;
            if (node == ".."){
                if (!pathStack.empty())
                    pathStack.pop();
                continue;
            }
            pathStack.push(node);
        }

        while (!pathStack.empty()) {
            result = "/" + pathStack.top() + result;
            pathStack.pop();
        }

        if (result.size() == 0) {
            return "/";
        }
        return result;   
    }
};
