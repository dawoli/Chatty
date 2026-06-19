#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;

int n;
int f[MAXN]={};
bool v[MAXN]={};
bool g[MAXN]={}; 

int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>f[i];
		g[i]=true; v[i]=true;
	}
	sort(f+1,f+n+1);
	int pt=2;
	for(int i=1;i<=n;i++) {
		if(g[i]) {
			for(int j=pt;j<=n;j++) {
				if(v[j] && f[j]>f[i]) {
					v[j]=false;
					g[i]=false;
					pt=j;
					break;
				}
			}
		}
	} 
	int ljy=0;
	for(int i=1;i<=n;i++) {
		if(g[i]) {
			ljy++;
		}
	}
	cout<<ljy<<endl;
	return 0;
}
