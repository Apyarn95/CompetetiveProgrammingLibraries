#include<bits/stdc++.h>
using namespace std;
#define fastio     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int Mxn = 200005;
int p[Mxn];

int par(int u)
{
	if(p[u]==u) return u;

	return (p[u] = par(p[u]));
}

void  uni(int a,int b)
{
   int p1 = par(a);
   int p2 = par(b);
   p[p2] = p1;
}

int main()
{
	fastio;
    int n,q;
    cin >> n >> q;
    
    for(int i=1;i<=n;i++) p[i] = i;
    while(q--)
    {
    	int t,u,v;
    	cin >> t >> u >> v;
    	if(t==0)
    	{
    		uni(u,v);
    	}else
    	{
    		cout<<(par(u)==par(v)?1:0)<<"\n";
    	}
    }
	return 0;
}