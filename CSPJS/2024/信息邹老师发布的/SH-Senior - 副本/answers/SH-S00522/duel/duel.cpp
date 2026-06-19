#include<bits/stdc++.h>
using namespace std;
int r[100001],cnt[100001],u[100001];
bool f[100001],k[100001];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n&&j!=i;j++){
			if(i>j){
				f[j]=0;
				k[i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(k[i]==1){
			cnt[i]++;
		}
	}
	cout<<*min_element(cnt+1,cnt+1+n);
	return 0;
}
