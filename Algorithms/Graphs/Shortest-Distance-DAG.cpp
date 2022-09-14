// Edges are weighted

// Algorithm for this is that first get the topological sorting order and put in the stack
// and check for minimum path according to the stack...

class Shortest_Distance_DAG {
public:

  stack<int> topo;

  void getSorted(int node, vector<pair<int, int>> adj[],  vector<int> vis) {
    vis[node] = 1;
    for (auto it : adj[node]) {
      if (!vis[it.first]) {
        getSorted(it.first, adj, vis);
      }
    }
    st.push(node);
  }

  void topological_sort(int N, vector<pair<int, int>> adj[]) {
    vector<int> vis(N + 1, 0);
    for (int i = 0; i < N; i++) {
      if (!vis[i]) {
        getSorted(i, adj, vis);
      }
    }
  }


  vector<int> shortestDistance(int src, int N, vector<pair<int, int>> adj[]) {
    // generate the topo sort
    topological_sort(N, adj);

    // create a distance array
    vector<int> dist(N + 1, INT_MAX);

    // mark the distance of src equals to 0
    dist[src] = 0;

    // for every element in the stack find distance
    while (!st.empty()) {
      int node = st.top();
      st.pop();

      if (dist[node] != INT_MAX) {
        // check if distance to node i.e dist(parent) + child weight < dist(child)
        for (auto child : adj[node]) {
          if (dist[node] + child.second < dist[child.first]) {
            dist[child.first] = dist[node] + child.second;
          }
        }
      }
    }
    return dist;
  };
