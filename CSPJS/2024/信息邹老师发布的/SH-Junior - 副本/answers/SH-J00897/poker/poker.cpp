#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
struct pock{
	int a,b;
}inf[54];
bool comp(pock x,pock y){
	if(x.b==y.b)return x.a<y.a;
	else return x.b<y.b;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char typ,num;
		cin>>typ>>num;
		if(typ=='D')inf[i].a=1;
		else if(typ=='C')inf[i].a=2;
		else if(typ=='H')inf[i].a=3;
		else inf[i].a=4;
		if(num=='A')inf[i].b=1;
		else if(num=='T')inf[i].b=10;
		else if(num=='J')inf[i].b=11;
		else if(num=='Q')inf[i].b=12;
		else if(num=='K')inf[i].b=13;
		else inf[i].b=num-'0';
	}
	sort(inf+1,inf+n+1,comp);
	//for(int i=1;i<=n;i++)cout<<inf[i].a<<" "<<inf[i].b<<endl; 
	int p=1,q=1;
	for(int i=1;i<=n;i++){
		if(inf[i].b<q)continue;
		ans+=(inf[i].b-q)*4+inf[i].a-p;
		p=inf[i].a+1;
		if(p>4){
			p=(p-1)%4+1;
	    	q=inf[i].b+1;
		}
	//	cout<<ans<<" ";
	}
	ans+=(13-inf[n].b)*4+4-inf[n].a;
	cout<<ans;
	return 0;
} 
