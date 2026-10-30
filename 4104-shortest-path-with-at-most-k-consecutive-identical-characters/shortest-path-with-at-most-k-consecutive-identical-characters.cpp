#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Adjacency list: u -> list of {v, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // Min-heap priority queue storing: {weight_sum, node, consecutive_count}
        priority_queue<tuple<long long, int, int>, 
                       vector<tuple<long long, int, int>>, 
                       greater<tuple<long long, int, int>>> pq;

        // dist[u][count] = min weight to reach node u with run length count
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        // Start at node 0
        int start_count = 1;
        pq.push({0LL, 0, start_count});
        dist[0][start_count] = 0;

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (d > dist[u][count]) continue;

            // If we reached the destination node n - 1
            if (u == n - 1) {
                return d;
            }

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                int next_count = 1;
                if (labels[u] == labels[v]) {
                    next_count = count + 1;
                }

                // If consecutive identical characters exceed k, invalid transition
                if (next_count > k) continue;

                if (dist[u][count] + weight < dist[v][next_count]) {
                    dist[v][next_count] = dist[u][count] + weight;
                    pq.push({dist[v][next_count], v, next_count});
                }
            }
        }

        // Find the minimum distance to reach node n - 1 across all valid counts
        long long ans = LLONG_MAX;
        for (int c = 1; c <= k; ++c) {
            ans = min(ans, dist[n - 1][c]);
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};
