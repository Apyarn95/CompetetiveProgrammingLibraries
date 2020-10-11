 #include<bits/stdc++.h>
 // #include <ext/pb_ds/tree_policy.hpp>
 // #include <ext/pb_ds/assoc_container.hpp>
 // #include<chrono>
  using namespace std;
  using namespace std::chrono;      
 // using namespace __gnu_pbds; 
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
 #define Md          1000000007
 #define forf(i,a,b) for(int i=a;i<b;i++)
 #define it(x)      x::iterator
 #define ll         long long 
 #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 #define time__(d)  for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
 #define vii        vector<int>
 #define big        1e18
 #define sm         -1e9
 #define mkr        make_pair
 #define vpi        vector<pair<int,int> >
 #define pii        pair<int,int>
 #define rng        500005
 #define sz(x)      (int)x.size()
 #define rv(x)      reverse(x.begin(),x.end())
 #define out(x)     cout<<x.fi<<" "<<x.se<<endl;

 // typedef tree<pii, null_type, less<pii>, rb_tree_tag,  
 //            tree_order_statistics_node_update>  odst; 


void pr_init()
{
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   
    #endif
}

int a[10];

// cation : template to calculate min segement trees on int data-type

struct SegTree
{
  int N;
  vector<int> st;
  vector<bool> cLazy;
  vector<int> lazy;

  void init(int n)
  {
    N = n;
    st.resize(4 * N + 5);
    cLazy.assign(4 * N + 5, false);
    lazy.assign(4 * N + 5, 0);
  }

  //Write reqd merge functions
  void merge(int &cur, int &l, int &r) 
  {
    cur = min(l, r);
  }

  void propagate(int node, int L, int R)
  {
    if(L != R)
    {
      cLazy[node*2] = 1;
      cLazy[node*2 + 1] = 1;
      lazy[node*2] = lazy[node];
      lazy[node*2 + 1] = lazy[node]; 
    }
    st[node] = lazy[node];
    cLazy[node] = 0;
  }

  void build(int node, int L, int R)
  {
    if(L==R)
    {
      //build some stuff here
      st[node] = a[L];
      return;
    }
    int M=(L + R)/2;
    build(node*2, L, M);
    build(node*2 + 1, M + 1, R);
    merge(st[node], st[node*2], st[node*2+1]);
  }

  int Query(int node, int L, int R, int i, int j)
  {
    if(cLazy[node])
      propagate(node, L, R);
    if(j<L || i>R)
      return big;
    if(i<=L && R<=j)
      return st[node];
    int M = (L + R)/2;
    int left=Query(node*2, L, M, i, j);
    int right=Query(node*2 + 1, M + 1, R, i, j);
    int  cur;
    merge(cur, left, right);
    return cur;
  }


  void Update(int node, int L, int R, int i, int j, int val)
  {
    if(cLazy[node])
      propagate(node, L, R);
    if(j<L || i>R)
      return;
    if(i<=L && R<=j)
    {
      cLazy[node] = 1;
      lazy[node] = val;
      propagate(node, L, R);
      return;
    }
    int M = (L + R)/2;
    Update(node*2, L, M, i, j, val);
    Update(node*2 + 1, M + 1, R, i, j, val);
    merge(st[node], st[node*2], st[node*2 + 1]);
  }



  int query(int l, int r)
  {
    return Query(1, 1, N, l, r);
  }


  void update(int l, int r, int val)
  {
    Update(1, 1, N, l, r, val);
  }
};


void solve()
{
 
  int n,q;
  cin >> n >> q;

  forf(i,0,n) cin >> a[i];

  SegTree My_tree;
  My_tree.init(n);
  My_tree.build(1,0,n-1);
  
  forf(i,0,q)
  {
    int l,r;
    cin >> l >> r;
    cout<<My_tree.query(l,r)<<endl;

  }

}

int32_t main()
{
  //pr_init();
  //fastio;
  
  auto start = high_resolution_clock::now(); 
 
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl; 

  return 0;
}