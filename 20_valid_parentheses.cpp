class Solution {
public:
    bool isValid(string s) {
        stack p = stack<char>();
        int len = s.size();
        
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{'){
                p.push(c);
            } else {
                if (p.empty())
                    return false;
                char t = p.top();
                cout << "comparing " << t << ' ' << c << endl; 
                if (!isMatching(t, c))
                    return false;
                p.pop();
            }
        }

        if (p.empty())
            return true;

        return false;
    }

    bool isMatching(char open, char close) {
        switch (close) {
            case ')': return open == '(';
            case ']': return open == '[';
            case '}': return open == '{';
            default: return false;
        }
    }
};
