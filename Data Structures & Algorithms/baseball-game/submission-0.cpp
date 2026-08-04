class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;

        for(auto& o : operations){
            if(o == "+") {
                int t1 = s.top(); s.pop();
                int t2 = s.top(); s.push(t1);

                s.push(t1+t2);
            }
            else if(o == "C")
                s.pop();
            else if(o == "D")
                s.push(2*s.top());
            else
                s.push(stoi(o));
        }

        int ans = 0;
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }

        return ans;
    }
};