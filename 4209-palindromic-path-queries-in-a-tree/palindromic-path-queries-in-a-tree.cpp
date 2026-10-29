#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class SegmentTree {
    int n;
    vector<int> tree;
public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) ^ query(2 * node + 1, mid + 1, end, l, r);
    }
};

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    int cur_pos;
    
    int dfs(int v, int p) {
        int size = 1;
        int max_c_size = 0;
        parent[v] = p;
        for (int c : adj[v]) {
            if (c != p) {
                depth[c] = depth[v] + 1;
                int c_size = dfs(c, v);
                size += c_size;
                if (c_size > max_c_size) {
                    max_c_size = c_size;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }
    
    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1) {
            decompose(heavy[v], h);
        }
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v]) {
                decompose(c, c);
            }
        }
    }
    
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        cur_pos = 0;
        
        dfs(0, -1);
        decompose(0, 0);
        
        SegmentTree segTree(n);
        for (int i = 0; i < n; ++i) {
            segTree.update(1, 0, n - 1, pos[i], 1 << (s[i] - 'a'));
        }
        
        vector<bool> answer;
        
        auto query_path = [&](int u, int v) {
            int res = 0;
            for (; head[u] != head[v]; v = parent[head[v]]) {
                if (depth[head[u]] > depth[head[v]]) swap(u, v);
                res ^= segTree.query(1, 0, n - 1, pos[head[v]], pos[v]);
            }
            if (depth[u] > depth[v]) swap(u, v);
            res ^= segTree.query(1, 0, n - 1, pos[u], pos[v]);
            return res;
        };
        
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                segTree.update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                int u, v;
                ss >> u >> v;
                int mask = query_path(u, v);
                bool can_palindrome = (mask == 0) || ((mask & (mask - 1)) == 0);
                answer.push_back(can_palindrome);
            }
        }
        
        return answer;
    }
};
