class Solution{
  
  bool checkForCycle(int node, int vis[], int dfsVis[]){
    vis[node] = 1;
    dfsVis[node] = 1;

    for(auto it : adj[node]){
      if(!vis[it]){
        if(checkForCycle(it, adj, vis, dfsVis)){
          return true;
        }
      }else if(dfsVis[it]){
        return true;
      }
    }

    dfsVis[node] = 0;
  }


public:
  bool isCyclic(int N, vector<int> adj[]){
    int vis[N], dfsVis[N];
    memset(vis, 0, sizeof vis);
    memset(dfsVis, 0, sizeof dfsVis);

    for(int i = 0; i < N; i++){
      if(!vis[i]){
        if(checkForCycle(i, adj, vis, dfsVis)){
          return false;
        }
      }
    }

    return true;
  }
};
