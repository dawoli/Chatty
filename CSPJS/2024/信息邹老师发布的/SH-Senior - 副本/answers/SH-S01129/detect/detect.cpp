#include<bits/stdc++.h>
using namespace std;
int T,m,n,l,V,ans1,ans2;
float d[100005],v[100005],a[100005];
float p[100005];
long long L[100005];
bool cmp1(int x,int y){
	return x<y;
}
void init(){
	for(int i=1;i<=n;i++){
		if(a[i]!=0) L[i]=(V*V-v[i]*v[i])/(2*a[i]);
		if(v[i]>V) {
			L[i]=l-d[i];
			if(a[i]>=0){
				a[i]=-1;
			}
		}
		else L[i]=-d[i]-1;
		if(L[i]<0) L[i]=-d[i]-1;
	}
	for(int i=1;i<=n;i++){
		L[i]+=d[i];
		if(L[i]>l&&a[i]>0&&v[i]<V) L[i]=-1;
	}
	return; 
}
void que1(){
	for(int i=1;i<=n;i++){
		
		if(L[i]>=0){
			if(a[i]<=0){
				int x=p[lower_bound(p+1,p+1+n,d[i])-p];
				if(x<=L[i]) ans1++;
			}
			else{
				int x=lower_bound(p+1,p+1+m,L[i])-p;
				if(x<m+1){
					ans1++;
				}
			}
		}
	}
	return;
}
int que2(int y){
	
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.ans","w",stdout);
	cin>>T;
	while(T>0){
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+1+n,cmp1);
		init();
		que1();
		cout<<ans1<<endl;
		
		T--;
		ans1=0;
	}
	return 0;
}
