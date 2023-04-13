#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;

int parent[MAXN], size[MAXN];

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    int n = g_nodes;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < g_from.size(); i++)
        edges.push_back({g_weight[i], {g_from[i], g_to[i]}});
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++)
        make_set(i);
    int ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first;
        if (find_set(u) != find_set(v)) {
            union_sets(u, v);
            ans += w;
        }
    }
    return ans;
}

int main() {
    int g_nodes, g_edges;
    cin >> g_nodes >> g_edges;
    vector<int> g_from(g_edges), g_to(g_edges), g_weight(g_edges);
    for (int i = 0; i < g_edges; i++)
        cin >> g_from[i] >> g_to[i] >> g_weight[i];
    int ans = kruskals(g_nodes, g_from, g_to, g_weight);
    cout << ans << endl;
    return 0;
}
