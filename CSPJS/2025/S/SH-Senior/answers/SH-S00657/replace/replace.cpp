#include <bits/stdc++.h>
using namespace std;
const int maxl = 5002424, maxn = 200083, maxlog = 22;
struct node
{ int nxt [27], pt; }
trie [maxl*2+maxn*4]; int ctc;
#define jnode(var,ch) if(trie[var].nxt[ch]) var=trie[var].nxt[ch];\
    else var=trie[var].nxt[ch]=++ctc;
char s [maxl], t [maxl];
typedef unsigned long long ll;
struct pnode
{
    int rt;
    unordered_map <ll, int> cnt;
} pns [maxl]; int ptc;
const ll b1 = 457, b2 = 997, p1 = 998244853, p2 = 1e9+9;
int hmap [26];
void init_hash (void)
{
    mt19937 rnd (random_device {} ());
    int i; char u [26];
    for (i=0; i<26; i++) u [i] = i;
    shuffle (u, u+26, rnd);
    for (i=0; i<26; i++)
    hmap [u [i]] = 3 + i*(i+1)/2;
    for (i=0; i<26; i++) hmap [i] = i+1;
}
#define nh(x,b,p,c) ((x*b+hmap[c])%p)
ll nxt_hash (ll cur, int ch)
{
    ll ha = cur >> 32, hb = cur & 0xffffffffull;
    return (nh (ha, b1, p1, ch) << 32) |
        nh (hb, b2, p2, ch);
}
void dfs_pns (ll ch, int cur, int rt)
{
    pns [rt] .cnt [ch] = trie [cur] .pt;
    int i;
    for (i=0; i<26; i++)
    if (trie [cur] .nxt [i])
    dfs_pns (nxt_hash (ch, i), trie [cur] .nxt [i], rt);
}
void add_s (void)
{
    scanf ("%s%s", s, t);
    if (strcmp (s, t) == 0) return;
    int np = 1e9+7, xp = -1;
    int i, l = strlen (s);
    for (i=0; i<l; i++)
    if (s [i] != t [i])
    np = min (np, i), xp = max (xp, i);
    int cur = 0;
    for (i=np; i<=xp; i++)
    {
        jnode (cur, s [i] - 'a');
        jnode (cur, t [i] - 'a');
    }
    jnode (cur, 26);
    for (i=xp+1; i<l; i++) jnode (cur, s [i] - 'a');
    // cerr << "s bn " << cur << endl;
    int pr;
    if (trie [cur] .pt) pr = trie [cur] .pt;
    else
    {
        pr = trie [cur] .pt = ++ptc;
        pns [pr] .rt = ++ctc;
    }
    cur = pns [pr] .rt;
    if (trie [cur] .pt == 0) trie [cur] .pt = 1;
    for (i=np-1; i>=0; i--)
    {
        int x = trie [cur] .pt;
        jnode (cur, s [i] - 'a');
        if (trie [cur] .pt == 0) trie [cur] .pt = x;
    }
    trie [cur] .pt ++;
}
void init_s (int sc)
{
    int i;
    for (i=0; i<sc; i++) add_s ();
    for (i=1; i<=ptc; i++) dfs_pns (0, pns [i] .rt, i);
}
ll hs [maxl];
int query (void)
{
    scanf ("%s%s", s, t);
    int np = 1e9+7, xp = -1;
    int i, l = strlen (s);
    if (strlen (t) != l) return 0;
    for (i=0; i<l; i++)
    if (s [i] != t [i])
    np = min (np, i), xp = max (xp, i);
    cerr << "np=" << np << " xp=" << xp << endl;
    int cur = 0;
    for (i=np; i<=xp; i++)
    {
        jnode (cur, s [i] - 'a');
        jnode (cur, t [i] - 'a');
    }
    jnode (cur, 26);
    for (i=np-1; i>=0; i--)
    hs [np-i] = nxt_hash (hs [np-i-1], s [i] - 'a');
    // cerr << "sp: " << cur << endl;
    int res = 0;
    for (i=xp; i<l; i++)
    {
        int pr;
        if (pr = trie [cur] .pt)
        {
            int l = 0, r = np;
            pnode& cn = pns [pr];
            while (l<r)
            {
                int m = (l+r+1) / 2;
                if (cn.cnt.count (hs [m])) l = m;
                else r = m-1;
            }
            // if (l == 0) goto O;
            // if (cn.cnt [hs [l]] - 1)
            // cerr<< " i=" << i
            //     << " prefix len " << l << " cnt " << cn.cnt[hs[l]]-1
            //     << " cnode " << cur << endl;
            res += cn.cnt [hs [l]] - 1;
            O:;
        }
        if (i<l-1)
        {
            cur = trie [cur] .nxt [s [i+1] - 'a'];
            if (cur == 0) break;
        }
    }
    return res;
}
void dfs_dbg_trie (int cur)
{
    cerr << "node " << cur << ":";
    int i; vector <int> x;
    for (i=0; i<27; i++)
    if (trie [cur] .nxt [i])
    {
        cerr << " " << (char)(i<26?i+'a':'#') << "->" <<
            trie [cur] .nxt [i];
        x.push_back (trie [cur] .nxt [i]);
    }
    cerr << endl;
    for (int y : x) dfs_dbg_trie (y);
}
int main (void)
{
    freopen ("replace.in", "r", stdin);
    freopen ("replace.out", "w", stdout);
    int n, q; scanf ("%d%d", &n, &q);
    init_hash ();
    init_s (n);
    int Q = q;
    while (q--)
    {
        printf ("%d\n", query ());
        // cerr << "eoq"<<endl;
        // if (Q-q==101) break;
    }
    // dfs_dbg_trie (0); int i;
    // for (i=1; i<=ptc; i++)
    // {
    //     cerr << "--" << endl;
    //     dfs_dbg_trie (pns [i] .rt);
    // }
}
