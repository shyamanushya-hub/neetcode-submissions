class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        map<string, int> operators{{"+",1}, {"-",2},{"*",3},{"/",4}};
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
                        s.push(op1 + op2);
                        break;
                    }
                    case 2:
                    {
                        s.push(op1 - op2);
                        break;
                    }
                    case 3:
                    {
                        s.push(op1 * op2);
                        break;
                    }
                    case 4:
                    {
                        s.push(op1 / op2);
                        break;
                    }
                }
            }
            else {
                s.push(stoi(token));
            }
        } 

        return s.top();

    }
};
