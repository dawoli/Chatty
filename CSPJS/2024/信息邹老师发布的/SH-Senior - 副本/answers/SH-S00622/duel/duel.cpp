#include<bits/stdc++.h>
using namespace std;
int n,x,a[100010],b[100010],cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x,a[x]++;
	x=0;
	for(int i=1;i<=100000;i++){
		if(a[i]){
			int t=0,t1=a[i];
			while(x!=0 and t1--){
				while(a[b[x-t]]==0){
					t++;
					if(t>=x)break;
				}
				a[b[x-t]]--;
			//	cout<<b[x-t]<<' '<<a[b[x-t]]<<'\n';
			}
			b[++x]=i;
		}
	}
	for(int i=1;i<=100000;i++)cnt+=a[i];
	cout<<cnt;
	return 0;
}

