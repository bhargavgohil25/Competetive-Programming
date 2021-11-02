class Solution {

  bool checkBipartiteDFS(int node, vector<int> &color, vector<int> adj[]){
    
    if(color[node] == -1) {
      color[node] = 1;
    }

    for(auto it : adj[src]){
      if(color[it] == -1){
        color[it] = 1 - color[node];
        if(!checkBipartiteDFS(it, color, adj)){
          return false;
        }
      }else if(color[it] == color[node]) return false;
    }
    return true;
  }

  public:
  bool bipartiteDFS(int n, vector<int> adj[]){
    vector<int> color(n, -1);

    for(int i = 0; i < n; i++){
      if(color[i] == -1){
        if(!checkBipartiteDFS(i, n, color, adj)){
          return false;
        }
      }
    }

    return false;
  }
}