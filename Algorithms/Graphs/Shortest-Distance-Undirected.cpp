class Shortest - Distance - Undirected {
public:
  vector<int> shortestDistance(int src, int N, vector<int> adj[]) {
    // int dist[N];
    // memset(dist, INT_MAX, sizeof dist);
    vector<int> dist(N, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
      int node = q.front();

      q.pop();

      for (auto it : adj[node]) {
        if (dist[node] + 1 < dist[it]) {
          dist[it] = dist[node] + 1;
          q.push(it);
        }
      }
    }

    return dist;
  }
};
