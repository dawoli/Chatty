#include<bits/stdc++.h>
using namespace std;
int T,n;
long long ans=-1;
int r[200009],a[200009];
void print(){
	int h=0,l=0;
	long long tmp=0;
	for(int i=1;i<=n;i++){
		if(r[i]==0 and a[i]==h){
			tmp+=h;
		}
		if(r[i]==1 and a[i]==l){
			tmp+=l;
		}
		if(r[i]==0) h=a[i];
		if(r[i]==1) l=a[i];
	}
	ans=max(tmp,ans);
	return;
}
void s1(int x){
	if(x==n+1){
		print();
		return;
	}
	r[x]=1;
	s1(x+1);
	r[x]=0;
	s1(x+1);
	return;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	r[1]=0;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		s1(2);
		cout<<ans<<endl;
		ans=-1;
	}
	return 0;
}
