#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

vector<int> arr(312345), freq(1123456);
int len = 320, L, R;

struct node
{
    int l, r;
    node(int l_, int r_) : l(l_), r(r_) {}

    bool operator<(const node &o) const
    {
        return make_pair(l / len, r) < make_pair(o.l / len, o.r);
    }
};
vector<node> ord, op;

int expand_l(int l)
{
    if (l < L)
    {
        int res = 0;
        for (int i = l; i < L; i++)
        {
            if (freq[arr[i]] == 0)
                res++;
            freq[arr[i]]++;
        }
        L = l;
        return res;
    }
    return 0;
}
int expand_r(int r)
{
    if (r > R)
    {
        int res = 0;
        for (int i = R + 1; i <= r; i++)
        {
            if (freq[arr[i]] == 0)
                res++;
            freq[arr[i]]++;
        }

        R = r;
        return res;
    }
    return 0;
}

int contract_l(int l)
{
    if (l > L)
    {
        int res = 0;
        for (int i = L; i < l; i++)
        {
            freq[arr[i]]--;
            if (freq[arr[i]] == 0)
                res--;
        }

        L = l;
        return res;
    }
    return 0;
}
int contract_r(int r)
{
    if (r < R)
    {
        int res = 0;
        for (int i = r + 1; i <= R; i++)
        {
            freq[arr[i]]--;
            if (freq[arr[i]] == 0)
                res--;
        }

        R = r;
        return res;
    }
    return 0;
}

void solvetask()
{
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    cin >> q;
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        op.push_back(node(l, r));
        ord.push_back(node(l, r));
    }
    sort(ord.begin(), ord.end());

    map<pair<int, int>, int> m_res;
    int res = 0;
    for (auto o : ord)
    {
        res += expand_l(o.l);
        res += expand_r(o.r);
        res += contract_l(o.l);
        res += contract_r(o.r);
        m_res[{o.l, o.r}] = res;
    }

    for (auto o : op)
        cout << m_res[{o.l, o.r}] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--)
        solvetask();
}