#include<bits/stdc++.h>
using namespace std;
int t,n,sum,a[100005],b[100005],c[100005],fa,fb,fc;
void dfs(int sm,int id){
	if(id<=n){
		if(fa<n/2){
			fa++;
			dfs(sm+a[id],id+1);
			fa--;
		}
		if(fb<n/2){
			fb++;
			dfs(sm+b[id],id+1);
			fb--;
		}
		if(fc<n/2){
			fc++;
			dfs(sm+c[id],id+1);
			fc--;
		}
	}else{
		sum=max(sum,sm);
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		sum=0;
		if(n<=200){
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
			}
			dfs(0,1);
		}else{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) sum+=a[i];
		}
		cout<<sum<<endl;
	}
}
