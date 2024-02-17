struct kosaraju
{
    int n, cnt = 0;
    vector<vector<int>> adj, adj_rev;
    vector<int> comp, tam_comp, vis;
    stack<int> order;
    kosaraju(int n) : n(n)
    {
        adj.resize(n + 1);
        adj_rev.resize(n + 1);
        comp.resize(n + 1);
        vis.resize(n + 1);
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
        for (auto to : adj_rev[v])
            if (vis[to] == 1)
                dfs2(to);
        order.push(v);
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
                dfs2(v);
                cnt++;
            }
        }
    }
};