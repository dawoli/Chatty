#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,w;
int chu(int q,int p){
	if(q%p!=0){
		return q/p;
	}
	return q/p-1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	a[1]=s;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=(n*m)/2;i++){
		swap(a[i],a[n*m-i+1]);
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			w=i;
			break;
		}
	}
	if((chu(w,n)%2)==0){
		if(w%n==0){
			cout<<w/n<<" ";
			cout<<n;
		}else cout<<(w/n)+1<<" "<<w%n;
	}
	else if((chu(w,n)%2)==1){
		if(w%n==0){
			cout<<w/n<<" "<<1;
		}else cout<<(w/n+1)<<" "<<n-(w%n)+1;
	}
	return 0;
}
