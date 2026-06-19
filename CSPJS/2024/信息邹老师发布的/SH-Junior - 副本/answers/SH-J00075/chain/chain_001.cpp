#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct g{
	ll x,y,l,b;
};
ll t,n,k,q,l,r,c,a[10000][20000];
queue<g> d;
g now,nown;
bool flag;
bool bfs(){
	while(!d.empty()){
		now=d.front();
		d.pop();
		now.l++;
		if (now.l>r){
			return 0;
		}
		for (int i=0;i<n;i++){
			if (i==now.b){
				continue;
			}
			for (int j=1;j<=a[i][0];j++){
				if (a[i][j]==a[now.x][now.y]){
					for (int f=j-1;f>=1&&j-f+1<=k;f--){
						if (a[i][f]==1&&now.l==r){
							return 1;
						}
						if (now.l<r){
							nown.x=i;
							nown.y=f;
							nown.l=now.l;
							nown.b=now.x;
							d.push(nown);
						}
					}
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	while(t--){
		cin>>n>>k>>q;
		memset(a,0,sizeof(a));
		for (int i=0;i<n;i++){
			cin >> l;
			a[i][0]=l;
			for (int j=1;j<=l;j++){
				cin >> a[i][j];
			}
		}
		while(q--){
			cin >> r >> c;
			flag=0;
			for (int i=0;i<n;i++){
				for (int j=1;j<=a[i][0];j++){
					if (a[i][j]==c){
						while(!d.empty()){
							d.pop();	
						}
						now.x=i;
						now.y=j;
						now.l=0;
						now.b=0x3f3f;
						d.push(now);
						if (bfs()){
							cout << 1<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag){
					break;
				}
			}
			if (!flag){
				cout << 0 << endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
