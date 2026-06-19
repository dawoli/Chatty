#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],l,r;//b[i]==0->iÈÔÓĞ¹¥»÷´ÎÊı
void f(int i,int j){
	if(l==r){
		if(b[j]||a[j]<=a[i]) return;
		a[i]=-1;
		b[j]++;
		return ;
	} 
	if(a[j]<=a[i]||b[j]==1){
		l=j+1;
		j=(r+j+1)/2;
		f(i,j);
	}else{
		r=j;
		j=(j+l)/2;
		f(i,j);
	}
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		l=i;r=n;
		int j=(l+r)/2;
		f(i,j);
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==-1) ans++;
	}
	cout<<n-ans; 
	return 0;
}
