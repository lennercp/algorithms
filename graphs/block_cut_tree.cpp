// source: brunomaletta/Biblioteca
// Block-Cut Tree
//
// Cria a block-cut tree, uma arvore com os blocos
// e os pontos de articulacao
// Blocos sao componentes 2-vertice-conexos maximais
// Uma 2-coloracao da arvore eh tal que uma cor sao
// os blocos, e a outra cor sao os pontos de art.
// Funciona para grafo nao conexo
//
// art[v] responde o numero de novas componentes conexas
// criadas apos a remocao de v do grafo g
// Se art[v] >= 1, v eh ponto de articulacao
//
// Para todo b <= blocks.size()
// blocks[b] eh uma componente 2-vertce-conexa maximal
// edgblocks[b] sao as arestas do bloco b
// tree[b] eh um vertice da arvore que corresponde ao bloco b
//
// pos[v] responde a qual vertice da arvore ao que o vertice v pertence
// Arvore tem no maximo 2n vertices
//
// O(n+m)

struct block_cut_tree
{
    vector<vector<int>> g, blocks, tree;
    vector<vector<pair<int, int>>> edgblocks;
    stack<int> s;
    stack<pair<int, int>> s2;
    vector<int> pre, art, pos;

    block_cut_tree(vector<vector<int>> g_) : g(g_)
    {
        int n = (int)g.size();
        pre.resize(n, -1), art.resize(n), pos.resize(n);
        build();
    }

    int dfs(int v, int &timer, int p = -1)
    {
        int low = pre[v] = timer++;
        s.push(v);

        if (p != -1)
            s2.emplace(v, p);
        for (int to : g[v])
            if (to != p and pre[to] != -1)
                s2.emplace(v, to);

        for (int to : g[v])
        {
            if (to == p)
                continue;

            if (pre[to] == -1)
            {
                int low_to = dfs(to, timer, v);
                low = min(low, low_to);

                if (low_to >= pre[v])
                {
                    art[v]++;
                    blocks.emplace_back(1, v);
                    while (blocks.back().back() != to)
                        blocks.back().push_back(s.top()), s.pop();

                    edgblocks.emplace_back(1, s2.top()), s2.pop();
                    while (edgblocks.back().back() != pair(to, v))
                        edgblocks.back().push_back(s2.top()), s2.pop();
                }
                // if (low_to > pre[v]) aresta v-to eh ponte
            }
            else
                low = min(low, pre[to]);
        }

        if (p == -1 and art[v])
            art[v]--;
        return low;
    }

    void build()
    {
        int timer = 0;
        for (int v = 1; v < (int)g.size(); v++)
            if (pre[v] == -1)
                dfs(v, timer, -1);

        tree.resize((int)blocks.size());
        for (int v = 1; v < (int)g.size(); v++)
            if (art[v])
                pos[v] = (int)tree.size(), tree.emplace_back();

        for (int b = 0; b < (int)blocks.size(); b++)
            for (int j : blocks[b])
            {
                if (!art[j])
                    pos[j] = b;
                else
                    tree[b].push_back(pos[j]), tree[pos[j]].push_back(b);
            }
    }
};