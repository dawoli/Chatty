#include <bits/stdc++.h>
using namespace std;
int r[110000];
int c[110000];
int z[110000];
int z2[110000];
long long n, cmax=0;

bool cmp(int a, int b) {
    return a>b;
}

int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> r[i];
    sort(r+1, r+n+1, cmp);
    for (int i=1;i<=n;i++) {
        if (cmax<r[i]) cmax=r[i];
        c[r[i]]++;
    }
    long long res=0;
    long long cnt=0;
    for (int i=1;i<=cmax;i++) {
        if (c[i]!=0) z[++cnt]=c[i];
    }
    memcpy(z2, z, sizeof(z));
    for (int i=2;i<=cnt;i++) {
    	if (z[i]<z2[i-1]) {
    		res += z[i];
    		z2[i-1]-=z[i];
		} else {
			long long remaining = z[i];
			for (int j=i-1;j>=1;j--) {
				remaining -= z2[j];
				z2[j]=0;
				if (remaining<0) {
					z2[j]+=abs(remaining);
					remaining=0;
				}
			}
			res += z[i]-remaining;
		}
	}
    cout << n-res;
    return 0;
}
