class Solution {

  void dfsrecur(int node, vector<int> vis, vector<int> &adj[], vector<int> dfs){
    dfs.push_back(node);
    vis[node] = 1;
    for(auto it : adj[node]){
      if(!vis[it]){
        dfsrecur(it, vis, adj, dfs);
      }
    }
  }
  
  public :
    vector<int> dfsOfGraph(int V, vector<int> adj[]){
      vector<int> dfs;
      vector<int> vis(V+1, 0);

      for(int i = 0; i <= V; i++){
        if(!vis[i]){
          dfsrecur(i, vis, adj, dfs);
        }
      }

      return dfs;
    }
}