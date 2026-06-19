#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[200010][5];
int fd[200010];
int maxn=0;
void find(int p,int q,int r,int id){
	if(id>n){
		int tot=0;
		for(int i=1;i<=n;i++){
			tot+=a[i][fd[i]];
		}
		maxn=max(maxn,tot);
	}
	if(p<n/2){
		fd[id]=1;
		find(p+1,q,r,id+1);
	}
	if(q<n/2){
		fd[id]=2;
		find(p,q+1,r,id+1);
	}
	if(r<n/2){
		fd[id]=3;
		find(p,q,r+1,id+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(;t>0;t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		maxn=0;
		find(0,0,0,1);
		cout<<maxn<<endl;
	}
	return 0;
}
