/*I'm broke, lads.*/    // |=@|< <<|=!
/*I'm broke, lads.*/    #include<bits/stdc++.h>
/*I'm broke, lads.*/    using namespace std;
/*I'm broke, lads.*/    struct Edge {
/*I'm broke, lads.*/        int u, v, w;
/*I'm broke, lads.*/        Edge() {
/*I'm broke, lads.*/            vil = -1;
/*I'm broke, lads.*/        }
/*I'm broke, lads.*/        Edge(int U, int V, int W) : u(U), v(V), w(W) {
/*I'm broke, lads.*/            vil = -1;
/*I'm broke, lads.*/        }
/*I'm broke, lads.*/        bool operator<(const Edge& b) const {
/*I'm broke, lads.*/            return w < b.w;
/*I'm broke, lads.*/        }
/*I'm broke, lads.*/    };
/*I'm broke, lads.*/    int n, m, k;
/*I'm broke, lads.*/    vector<Edge> edges;
/*I'm broke, lads.*/    vector<int> fa;
/*I'm broke, lads.*/    int find(int node) {
/*I'm broke, lads.*/        return (node == fa[node] ? node : (fa[node] = find(fa[node])));
/*I'm broke, lads.*/    }
/*I'm broke, lads.*/    void unite(int x, int y) {
/*I'm broke, lads.*/        fa[find(x)] = find(y);
/*I'm broke, lads.*/    }
/*I'm broke, lads.*/    bool connected(int x, int y) {
/*I'm broke, lads.*/        return find(x) == find(y);
/*I'm broke, lads.*/    }
/*I'm broke, lads.*/    int main() {
/*I'm broke, lads.*/        freopen("road.in", "r", stdin);
/*I'm broke, lads.*/        freopen("road.out", "w", stdout);
/*I'm broke, lads.*/        cin >> n >> m >> k;
/*I'm broke, lads.*/        for(int i = 0; i < m; i++) {
/*I'm broke, lads.*/            int u, v, w;
/*I'm broke, lads.*/            cin >> u >> v >> w;
/*I'm broke, lads.*/            edges.push_back(Edge(u, v, w));
/*I'm broke, lads.*/        }
/*I'm broke, lads.*/    
/*I'm broke, lads.*/        vector<int> city(k);
/*I'm broke, lads.*/        vector<vector<int> > costs(k, vector<int>(n));
/*I'm broke, lads.*/        for(int i = 0; i < k; i++) {
/*I'm broke, lads.*/            cin >> city[i];
/*I'm broke, lads.*/            for(int j = 0; j < n; j++) {
/*I'm broke, lads.*/                cin >> costs[i][j];
/*I'm broke, lads.*/            }
/*I'm broke, lads.*/            for(int j = 0; j < n; j++) {
/*I'm broke, lads.*/                for(int k1 = j + 1; k1 < n; k1++) {
/*I'm broke, lads.*/                    edges.push_back(Edge(j + 1, k1 + 1, costs[i][j] + costs[i][k1] + city[i]));
/*I'm broke, lads.*/                }
/*I'm broke, lads.*/            }
/*I'm broke, lads.*/        }
/*I'm broke, lads.*/    
/*I'm broke, lads.*/        sort(edges.begin(), edges.end());
/*I'm broke, lads.*/        int ans = 0;
/*I'm broke, lads.*/        fa.push_back(0);
/*I'm broke, lads.*/        for(int i = 1; i <= n; i++) {
/*I'm broke, lads.*/            fa.push_back(i);
/*I'm broke, lads.*/        }
/*I'm broke, lads.*/        for(int i = 0; i < edges.size(); i++) {
/*I'm broke, lads.*/            if(connected(edges[i].u, edges[i].v)) {
/*I'm broke, lads.*/                continue;
/*I'm broke, lads.*/            }
/*I'm broke, lads.*/            unite(edges[i].u, edges[i].v);
/*I'm broke, lads.*/            ans += edges[i].w;
/*I'm broke, lads.*/        }
/*I'm broke, lads.*/    
/*I'm broke, lads.*/        cout << ans << '\n';
/*I'm broke, lads.*/        return 0;
/*I'm broke, lads.*/    }
/*I'm broke, lads.*/    // 
/*I'm broke, lads.*/    // AC 1-4
/*I'm broke, lads.*/    // 
/*I'm broke, lads.*/    // Try #1
/*I'm broke, lads.*/    // use cnt to iterate through which villages to turn into cities
/*I'm broke, lads.*/    // and add the edges to use kruskal every time
/*I'm broke, lads.*/    // also, check if the minimum value is smaller than the price to build the city
/*I'm broke, lads.*/    // 
/*I'm broke, lads.*/    // Try #2
/*I'm broke, lads.*/    // check the minimum cost with making no villages to cities using kruskal
/*I'm broke, lads.*/    // then, use cnt to iterate through which villages to turn into cities
/*I'm broke, lads.*/    // each time, check if a route is lesser or equal to the original path
/*I'm broke, lads.*/    // then change the weight
/*I'm broke, lads.*/    // 
/*I'm broke, lads.*/    // Try #3
/*I'm broke, lads.*/    // put all the paths between cities via villages in edges[], with a special param of the village
/*I'm broke, lads.*/    // if kruskal uses the edge then iterate through the edges to minus the weight
/*I'm broke, lads.*/    // 
/*I'm broke, lads.*/    // should be at most O(n^2)
/*I'm broke, lads.*/    // AAAH