struct kosaraju
{
    int n, cnt = 0;
    vector<vector<int>> adj, adj_rev, vert_comp;
    vector<int> comp, tam_comp, vis, grau;
    stack<int> order;
    kosaraju(int n) : n(n)
    {
        adj.resize(n + 1);
        adj_rev.resize(n + 1);
        comp.resize(n + 1);
        vis.resize(n + 1);
        grau.resize(n + 1);
    }

    void add_edge(int a, int b)
    {
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    void dfs1(int v)
    {
        vis[v] = 1;
        for (auto to : adj[v])
            if (vis[to] == 0)
                dfs1(to);
        order.push(v);
    }
    void dfs2(int v)
    {
        vis[v] = 2;
        comp[v] = cnt;
        tam_comp.back()++;
        if (vert_comp.back()[0] != v)
            vert_comp.back().push_back(v);
        for (auto to : adj_rev[v])
            if (vis[to] == 1)
                dfs2(to);
            else if (comp[to] != comp[v])
            {
                grau[comp[to]]++;
            }
    }

    void build()
    {
        rep(i, 1, n + 1) if (vis[i] == 0)
            dfs1(i);

        while (!order.empty())
        {
            int v = order.top();
            order.pop();

            if (vis[v] == 1)
            {
                tam_comp.push_back(0);
                vert_comp.emplace_back(1, v);
                dfs2(v);
                cnt++;
            }
        }
    }
};