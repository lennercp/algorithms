struct bridge_tree
{
    vector<int> pre, low, comp, bridges, prof, tam_comp;
    vector<vector<int>> g, tree;
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
        // cout << "V " << v << " p " << p << '\n';

        for (auto ind : g[v])
        {
            int to = edges[ind][0] ^ edges[ind][1] ^ v;
            if (to == p || prof[to] > prof[v])
                continue;

            if (!pre[to])
            {
                prof[to] = prof[v] + 1;
                dfs(to, v);
                low[v] = min(low[v], low[to]);

                if (low[to] > pre[v])
                {
                    bridges.push_back(ind);

                    int u;
                    cnt++;
                    do
                    {
                        u = s.top();
                        s.pop();
                        comp[u] = cnt;
                        tam_comp[cnt]++;
                        // cout << "V " << u << " CMP " << cnt << " TAM " << tam_comp[cnt] << '\n';
                    } while (u != to);
                }
                else
                    res[ind] = {v, to};
            }
            else
            {
                low[v] = min(low[v], pre[to]);
                res[ind] = {v, to};
            }
        }
    }

    void build()
    {
        cnt = 0, timer = 0;
        bridges.clear();
        for (int v = 1; v < (int)g.size(); v++)
            if (pre[v] == 0)
                dfs(v, -1);

        int u;
        cnt++;
        do
        {
            u = s.top();
            s.pop();
            comp[u] = cnt;
            tam_comp[cnt]++;
            // cout << "V " << u << " CMP " << cnt << " TAM " << tam_comp[cnt] << '\n';
        } while (!s.empty());

        tree.resize(cnt + 1);
        for (auto ind : bridges)
        {
            int a = edges[ind][0];
            int b = edges[ind][1];

            a = comp[a];
            b = comp[b];

            edges2[ind][0] = a;
            edges2[ind][1] = b;
            tree[a].push_back(ind);
            tree[b].push_back(ind);
        }
    }
};