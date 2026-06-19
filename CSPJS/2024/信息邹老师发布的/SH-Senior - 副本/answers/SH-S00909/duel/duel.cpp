#include<bits/stdc++.h>
using namespace std;
int n,r[100005],k,sum=1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+n+1);
	k=1;
	for(int i=1;i<=n;i++){
		if(r[i]>r[k]){
			r[k]=-1;
			k++;
		}
	}
	cout<<n-k+1<<endl;
	return 0;
}
