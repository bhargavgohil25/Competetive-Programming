class Dijkstra_Algorithm {
public:

	/*
			TC - O((N + E) * log N)
			SC - O(N) + O(N)

	*/

	vector<int> dijkstra(int src, int n, vector<pair<int, int>> adj[]) {
		vector<int> dist(n + 1, INT_MAX);
		// { distance, node } --> structure of PQ
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dist[src] = 0;
		pq.push({ 0, src });

		while (!pq.empty()) {
			auto node = pq.top();
			pq.pop();

			if (dist[node.second] != INT_MAX) {
				for (auto it : adj[node.second]) {
					if (dist[node.second] + it.second < dist[it.first]) {
						dist[it.first] = dist[node] + it.second;
						pq.push({ dist[it.first], it.first });
					}
				}
			}
		}
		return dist;
	}
};