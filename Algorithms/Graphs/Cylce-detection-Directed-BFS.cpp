// Kahn's Algorithm

// If we find a cycle in the Graph using Kahn's Algorithm
// we can say that its a cyclic Graph...


class Cylce - detection - Directed - BFS {
public:
  bool isCyclic(int N, vector<int> adj[]) {
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

    int cnt = 0;
    while (!q.empty()) {
      int node = q.front();

      q.pop();

      cnt++;

      for (auto it : adj[node]) {
        indegree[it]--;
        if (indegree[it] == 0) {
          q.push(it);
        }
      }
    }

    if (cnt == N) return false;
    return true;
  }
};