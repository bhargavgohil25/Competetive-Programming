// Kahn's Algorithm

class Topological - sort - BFS {
public:
    vector<int> topologicalSortBFS(int N, vector<int> adj[]) {
        vector<int> indegree(N, 0);
        queue<int> q;
        for (int i = 0; i < N; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int>ans;

        while (!q.empty()) {
            int node = q.front();

            q.pop();

            ans.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return ans;
    }
};

