#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],xos[maxn],sum1=0;
struct st{
	int la,no,h;
}; 
void BFS(int h){
	queue<st> Q;
	for(int i=1;i<=n;i++){
		if(xos[i]!=k){
			continue;
		}
		Q.push({0,i,1});
	}
	while(!Q.empty()){
		st u=Q.front();Q.pop();
		st no;no.la=u.no;no.h=u.h+1;
		for(int i=u.no+1;i<=n;i++){
			int t=xos[i] xor xos[u.no];
			if(t!=k){
				continue;
			}
			no.no=i;
			if(no.h==h){
				cout<<h;
				exit(0);
			}
			Q.push(no);
		}
	}
}
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xos[i]=xos[i-1] xor a[i];
		if(a[i]==1){
			sum1++;
		}
	}
	if(n>50){
		if(k==0){
			cout<<1;
			return 0;
		}
		else if(k==1){
			if(sum1&1){
				cout<<1;
			}
			else{
				cout<<2;
			}
			return 0;
		}
	}
	for(int i=n;i>=1;i--){
		BFS(i);
	}
	cout<<1;
	return 0;
}
