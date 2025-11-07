#ifdef _DEBUG
    #include "debug.hpp"
#else
    #define dbg(head, ...)  ((void)0)
#endif

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;

#define rep(i, begin, end) for(int i = begin; i < end; i++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define sq(x) (x)*(x)
#define endl '\n'

const int N = 112345;
const int inf = 1e9+7;

void solvetask()
{
    int n;
    cin >> n;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--)
        solvetask();
        // cout << (solvetask() ? "Yes" : "No") << '\n';
}
