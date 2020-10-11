// DIV-2 662 P-D
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 2005;
char a[maxn][maxn];
int cnt_up[maxn][maxn], cnt_down[maxn][maxn], L[maxn], R[maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i != 1 && a[i][j] == a[i - 1][j]) cnt_up[i][j] = cnt_up[i - 1][j] + 1;
            else cnt_up[i][j] = 0;
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            if (i != n && a[i][j] == a[i + 1][j]) cnt_down[i][j] = cnt_down[i + 1][j] + 1;
            else cnt_down[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int go = j;
            while (go <= m && a[i][j] == a[i][go]) go++;
            go--;
            for (int pos = j; pos <= go; ++pos) {
                if (pos == j) L[pos] = pos;
                else {
                    L[pos] = max(L[pos - 1], pos - min(cnt_up[i][pos], cnt_down[i][pos]));
                }
            }
            j = go;
        }
        for (int j = m; j >= 1; --j) {
            int go = j;
            while (go >= 1 && a[i][j] == a[i][go]) go--;
            go++;
            for (int pos = j; pos >= go; --pos) {
                if (pos == j) R[pos] = pos;
                else {
                    R[pos] = min(R[pos + 1], pos + min(cnt_up[i][pos], cnt_down[i][pos]));
                }
            }
            j = go;
        }
        for (int j = 1; j <= m; ++j) {
            ans += (ll)min(j - L[j] + 1, R[j] - j + 1);
        }
    }
    cout << ans << '\n';
    return 0;
}