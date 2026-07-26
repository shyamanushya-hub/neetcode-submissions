class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        map<string, int> operators{{"+",1}, {"-",2},{"*",3},{"/",4}};
        int ans{0};
        for(auto token: tokens){
            int op2;
            int op1;
            if(operators.find(token) != operators.end()){
                if(s.size() < 2) break;
                op2 = s.top(); s.pop();
                op1 = s.top(); s.pop();

                switch(operators[token]){
                    case 1:
                    {
                        ans = op1 + op2;
                        break;
                    }
                    case 2:
                    {
                        ans = op1 - op2;
                        break;
                    }
                    case 3:
                    {
                        ans = op1 * op2;
                        break;
                    }
                    case 4:
                    {
                        ans = op1 / op2;
                        break;
                    }
                }

                s.push(ans);
            }
            else {
                s.push(stoi(token));
            }
        } 

        if(!s.empty())
            return s.top();

        return ans;
    }
};
