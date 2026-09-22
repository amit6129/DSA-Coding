#include <vector>

using namespace std;

struct Node {
    int total_prod;
    int count[5]; // Stores frequency of remainders 0 to 4
    
    Node() {
        total_prod = 1;
        for (int i = 0; i < 5; ++i) count[i] = 0;
    }
};

class Solution {
    vector<Node> tree;
    int n, K;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.total_prod = (left.total_prod * right.total_prod) % K;
        for (int i = 0; i < K; ++i) {
            res.count[i] = left.count[i];
        }
        for (int i = 0; i < K; ++i) {
            res.count[(left.total_prod * i) % K] += right.count[i];
        }
        return res;
    }

    void build(int node, int l, int r, const vector<int>& nums) {
        if (l == r) {
            int val = nums[l] % K;
            tree[node].total_prod = val;
            tree[node].count[val] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, nums);
        build(2 * node + 1, mid + 1, r, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            int v = val % K;
            for (int i = 0; i < K; ++i) tree[node].count[i] = 0;
            tree[node].total_prod = v;
            tree[node].count[v] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node, l, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        if (qr <= mid) return query(2 * node, l, mid, ql, qr);
        if (ql > mid) return query(2 * node + 1, mid + 1, r, ql, qr);
        
        return merge(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }

public:
    // Renamed to match the expected driver method name
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        K = k;
        tree.assign(4 * n, Node());
        
        build(1, 0, n - 1, nums);
        
        vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];
            
            update(1, 0, n - 1, idx, val);
            Node resNode = query(1, 0, n - 1, start, n - 1);
            result.push_back(resNode.count[x]);
        }
        
        return result;
    }
};
