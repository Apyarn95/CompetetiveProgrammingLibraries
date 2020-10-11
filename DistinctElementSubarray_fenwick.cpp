#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <complex>
#include <ctime>
#include <numeric>
#include <set>
 
using namespace std;

// **** always start from index 1 ***

typedef long long ll;
 
typedef struct node{
    int s, e, val, pos;
    bool operator<(const node& n) const{
        if(e != n.e) return e < n.e;
        return val > n.val;
    }
    node(){};
    node(int ss, int ee, int v, int p){
        s = ss, e = ee, val = v, pos = p;
    }
}node;
 
int occs[(int)1e6 + 5], tree[2000000], n, ans[2000000];
 
void update(int x, int val){
    while(x <= n){
        tree[x] += val;
        x += x & -x;
    }
}

// update range(a,b) -> v
void update(int a, int b,int v)     
{ 
  update(a, v)     
  update(b + 1, -v)
}      
 
 
int query(int x){
    int ret = 0;
    while(x > 0){
        ret += tree[x];
        x -= x & -x;
    }
    return ret;
}
 
int main()
{
 
    int q, s, e;
    vector<node> v;
    scanf("%d", &n);
    scanf("%d", &q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &s);
        v.push_back(node(i, i, s, -1));
    }
    
    for(int i = 0; i < q; i++){
        scanf("%d %d", &s, &e);
        v.push_back(node(s, e, 0, i));
    }
 
    sort(v.begin(), v.end());
 
    for(int i = 0;i < v.size(); i++){
        if(v[i].val == 0){
            ans[v[i].pos] = query(v[i].e) - query(v[i].s - 1);
        }else{
            if(occs[v[i].val] != 0) update(occs[v[i].val], -1);
            update(v[i].s, 1);
            occs[v[i].val] = v[i].s;
        }
    }
 
    for(int i = 0; i < q; i++){
        printf("%d\n", ans[i]);
    }
 
    return 0;
}