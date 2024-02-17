struct bridge_tree
{
    vector<int> pre, low, comp, prof, tam_comp;
    vector<vector<int>> g, tree, vert_comp;
    vector<array<int, 2>> bridges;
    int cnt, timer;
    stack<int> s;

    bridge_tree(vector<vector<int>> g) : g(g)
    {
        int n = (int)g.size();
        pre.resize(n), low.resize(n), comp.resize(n);
        prof.resize(n), tam_comp.resize(n);
        build();
    }

    void dfs(int v, int p)
    {
        pre[v] = low[v] = ++timer;
        s.push(v);

        for (auto to : g[v])
        {
            if (to == p || prof[to] > prof[v])
                continue;

            if (!pre[to])
            {
                prof[to] = prof[v] + 1;
                dfs(to, v);
                low[v] = min(low[v], low[to]);

                if (low[to] > pre[v])
                    bridges.push_back({v, to});
            }
            else
                low[v] = min(low[v], pre[to]);
        }

        if (pre[v] == low[v])
        {
            int u;
            vector<int> aux;
            do
            {
                u = s.top();
                s.pop();
                comp[u] = cnt;
                aux.push_back(u);
            } while (u != v && !s.empty());
            vert_comp.push_back(aux);
            cnt++;
        }
    }

    void build()
    {
        cnt = 0, timer = 0;
        bridges.clear();
        for (int v = 1; v < (int)g.size(); v++)
            if (pre[v] == 0)
            {
                dfs(v, -1);
            }

        tree.resize(cnt + 1);
        for (auto [a, b] : bridges)
        {
            tree[comp[a]].push_back(comp[b]);
            tree[comp[b]].push_back(comp[a]);
        }
    }
};