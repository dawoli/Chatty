#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int a,n[200001],T;
int search(int lr,int lb,int nr,int nb,int pt,long long tot){
	if(pt==a){
		ans=max(ans,tot);
		return 0;
	}
	pt++;
	if(n[pt]==nr)tot+=nr;
	search(nr,lb,n[pt],nb,pt,tot);
	if(n[pt]==nr)tot-=nr;
	if(n[pt]==nb)tot+=nb;
	search(lr,nb,nr,n[pt],pt,tot);
	if(n[pt]==nb)tot-=nb;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T){
		T--;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>n[i];
	}
	ans=0;
	search(0,0,n[1],0,1,0);
	search(0,0,n[1],0,1,0);
	cout<<ans<<endl;
}
}
