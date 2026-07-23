class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(auto s : stones)
            q.push(s);

        while(q.size() > 1) {
            auto s1 = q.top(); q.pop();
            auto s2 = q.top(); q.pop();

            if(s1 > s2) q.push(s1-s2);
        }


        if(q.empty())
            return 0;
            
        return q.top();
    }
};
