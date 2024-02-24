int True(int n)
{
    return 2 * (n - 1);
}

int False(int n)
{
    return 2 * (n - 1) + 1;
}

struct two_sat
{
    vector<vector<int>> adj, adj_rev;
    vector<int> vis, comp;
    stack<int> s;
    int n, cnt;
    two_sat(int n) : n(n)
    {
        cnt = 0;
        adj.resize(2 * (n + 1));
        adj_rev.resize(2 * (n + 1));
        vis.resize(2 * (n + 1));
        comp.resize(2 * (n + 1));
    }

    void add_edge(int a, int b)
    {
        adj[a ^ 1].push_back(b);
        adj[b ^ 1].push_back(a);
        adj_rev[b].push_back(a ^ 1);
        adj_rev[a].push_back(b ^ 1);
    }

    void dfs1(int v)
    {
        vis[v] = 1;
        for (auto to : adj[v])
            if (vis[to] == 0)
                dfs1(to);

        s.push(v);
    }
    void dfs2(int v)
    {
        vis[v] = 2;
        comp[v] = cnt;
        for (auto to : adj_rev[v])
            if (vis[to] == 1)
                dfs2(to);
    }

    void build()
    {
        for (int i = 0; i < 2 * n; i++)
        {
            if (vis[i] == 0)
                dfs1(i);
        }

        while (!s.empty())
        {
            int v = s.top();
            s.pop();

            if (vis[v] != 2)
            {
                dfs2(v);
                cnt++;
            }
        }
    }

    bool check()
    {
        for (int i = 1; i <= n; i++)
        {
            if (comp[True(i)] == comp[False(i)])
                return 0;
        }

        return 1;
    }
};