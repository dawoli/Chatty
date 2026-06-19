#include<bits/stdc++.h>
using namespace std;
int n,tot,r[100010],zj;
bool b[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	tot=n;
	for (int i=1;i<=n;++i) cin>>r[i],b[i]=1;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=i;++j){
			if (r[i]<r[j]){
				zj=r[j];
				r[j]=r[i];
				r[i]=zj;
			}
		}
	}
	for (int i=2;i<=n;++i){
		for (int j=1;j<i;++j){
			if (b[j]==1&&r[j]<r[i]){
				tot--;
				b[j]=0;
				break;
			}
		}
	} 	
	cout<<tot;
	return 0;
}
