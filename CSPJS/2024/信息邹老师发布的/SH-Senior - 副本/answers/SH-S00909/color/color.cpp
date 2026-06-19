#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],sum;
int st(int id,int red,int blue){
	int re=0;
	if(id==n){
		if(a[id]==a[red]||a[id]==a[blue]) return a[id];
		return 0;
	}
	if(a[id]==a[red]){
		re=max(st(id+1,red,id),a[id]+st(id+1,id,blue));
	}else{
		if(a[id]==a[blue]){
			re=max(st(id+1,id,blue),a[id]+st(id+1,red,id));
		}else{
			re=max(st(id+1,red,id),st(id+1,id,blue));
		}
	}
	return re;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(;t>0;t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<st(2,1,0)<<endl;
	}
	return 0;
}
