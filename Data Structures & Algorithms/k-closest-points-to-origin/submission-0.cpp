class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            int d1 = a[0]*a[0] + a[1]*a[1];
            int d2 = b[0]*b[0] + b[1]*b[1];

            return d1 < d2;
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;
        vector<vector<int>> ans;
        for(auto &point : points) {
            pq.push(point);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;

    }
};
