class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
    : kth{k}, pq(nums.begin(), nums.end()) {
        while(pq.size() > kth)
            pq.pop();

    }
    
    int add(int val) {
        if(pq.size() < kth) {
            pq.push(val);
        }
        else {
            if(val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }

        return pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth {0};
};