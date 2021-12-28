/*
    Programmer : Alexandru_Olteanu
*/
#include<bits/stdc++.h>
using namespace std;
// GCC Optimizations
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt")
#pragma GCC target("abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
// Useful
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define FastEverything  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define HighPrecision cout<<fixed<<setprecision(17);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll const mod=1000000007LL;
ll const mod2 = 100000000LL;
ll const md=998244353LL;
ll mypowr(ll a,ll b) {ll res=1;if(b<0)b=0;a%=mod; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll mypow(ll a,ll b) {ll res=1;if(b<0)b=0;assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
// ifstream in("input.txt");
// ofstream out("output.txt");
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()

// #define cin in
// #define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 3e5 + 2;



int main()
{
    FastEverything
    HighPrecision
    int test = 1;
    //cin>>test;

    for(int tt = 1; tt <= test; ++tt){
        int n = rng() % 10000 + 2;
        int m = rng() % 1000 + 2;
        cout<<n<<" "<<m<<'\n';
        for(int i = 1; i <= n; ++i){
            int x = rng() % inf + 1;
            int negative = rng() % 2;
            if(negative)x = -x;
            cout<<x<<" ";
        }
        cout<<'\n';
        int updates = 0;
        for(int i = 1; i <= m; ++i){
            int x, y;

            if(updates){
                int p = rng() % 2;
                if(p == 1)cout << "U ";
                else{
                    cout<<" Q ";
                }
            }
            x = rng() % n + 1;
            y = rng() % n + 1;
            if(x > y)swap(x, y);
            cout<<x<<" "<<y<<'\n';
        }
    }
    return 0;
}
