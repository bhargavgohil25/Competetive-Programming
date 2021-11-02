// Directed Acyclic Graphs have 
// only can have topological sorting

// Using DFS ALgorithm 
// kahn's Algorithm

class Topological-sort{

  void getSorted(int node, vector<int> adj[], vector<int> vis, stack<int> st){
    vis[node] = 1;

    for(auto it : adj[node]){
      if(!vis[it]){
        getSorted(it, adj, vis, st);
      }
    }
    st.push(node);
  }

public:
  vector<int> topologicalSortDFS(int N, vector<int> adj[]){

    vector<int> vis(N+1, 0);
    stack<int> st;
    for(int i = 0; i < N; i++){
      if(!vis[i]){
        getSorted(i, adj, vis, st);
      }
    }
    vector<int> ans;
    while(!st.empty()){
      ans.push_back(st.top());
      st.pop();
    }

    return ans;
  }
};