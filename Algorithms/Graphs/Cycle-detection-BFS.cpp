class Solution {

  public :
    bool cycleDetectionBFS(int V, vector<int> adj[]){
      vector<int> vis(V+1, 0);
      // pair<int, int> ==> { currNode, parentNode }
      for(int i = 1; i <= V; i++){  
        if(!vis[i]){
          queue<pair<int,int>> q;

          vis[i] = 1;

          q.push({i, -1});

          while(!q.empty()){
            // current Node
            int node = q.front().first;
            // parent Node
            int par = q.front().second;

            q.pop();

            for(auto it : adj[node]){
              if(!vis[it]) {
                vis[it] = 1;
                q.push({ it, node });
              }else if(it != par){
                return true;
              }
            }
          }
        }
      }
      return false;
      
    }
}