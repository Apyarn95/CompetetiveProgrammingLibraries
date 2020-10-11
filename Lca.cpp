#include<bits/stdc++.h>
 using namespace std;     
 #define fastio     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 #define fi         first
 #define se         second
#define int         long long 
 #define pb         push_back
 #define emp        emplace_back
 #define vv(x)      vector<x>
 #define mp(x,y)    map<x,y>
 #define dq(x)      deque<x>
 #define pql(x)     priority_queue<x>
 #define pqs(x)     priority_queue<x,vv(x),greater<x> >
 #define M         1000000007
 #define forf(i,a,b) for(int i=a;i<b;i++)
 #define it(x)      x::iterator
 #define ll         long long 
 #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 #define time__(d)  for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
 #define vii        vector<int>
 #define big        1e12
 #define mkr        make_pair
 #define vpi        vector<pair<int,int> >
 #define pii        pair<int,int>
 #define rng        500000
void pr_init()
{
   
    #ifndef ONLINE_JUDGE
    freopen("output.txt", "r", stdin);
    freopen("input.txt", "w", stdout);
   
    #endif
}


int n;
vector<vii> gp,P;
vii parent,lv;
void dfs(int u,int p,int cc)
{
    parent[u] = p;
    lv[u]=cc+1;
    for(auto x:gp[u])
        if(x!=p)
        {
            dfs(x,u,cc+1);
        }

}
int LCA(int u , int v){
    if(lv[u] < lv[v]){
        swap(u,v) ;     
    }
    
    int dist = lv[u] - lv[v] ; 
    while(dist > 0){
        int raise_by = log2(dist);
        u = P[u][raise_by];
        dist -= (1<<raise_by) ; 
    }

    if(u == v){
        return u ; 
    }

    for(int j = log2(n) ; j >= 0 ; --j){
        if((P[u][j] != -1) and (P[u][j] != P[v][j])){
            u = P[u][j] ; 
            v = P[v][j] ; 
        }
    }
    return parent[u] ; 
}
int dis(int u,int v)
{
    int lca = LCA(u,v);
    return (lv[u]-2*lv[lca]+lv[v]);
}   
void solve()
{
 cin >> n;
 gp.assign(n+1,vii());
 parent.assign(n+1,-1);
 lv.assign(n+1,-1);
 P.assign(n+1,vii(log2(n)+1,-1));
 forf(i,0,n-1)
 {
    int u,v;
    cin >> u >> v;
    gp[u].pb(v);
    gp[v].pb(u);
 }
 
 dfs(1,-1,0);
 
 for(int i = 1 ; i <= n ; ++i){
        P[i][0] = parent[i] ; 
    }
 
 for(int j = 1; (1<<j) < n ; ++j){
    for(int i = 1 ; i <= n ; ++i){
        if(P[i][j-1] != -1){
            P[i][j] = P[P[i][j-1]][j-1] ; 
         }
       }
  
     }
  
  
  
} 
int32_t main()
{
   
 //pr_init();
  
  //fastio;
  solve();
  return 0;
}