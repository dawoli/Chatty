#include<bits/stdc++.h>
using namespace std;
struct member{
	int ma,mb,mc,dab,dbc,dca;
};
bool ka(member a,member b){
	int m,n;
	m=min(a.dab,a.dca);
	n=min(b.dab,b.dca);
	return m<n;
}
bool kb(member a,member b){
	int m,n;
	m=min(a.dab,a.dbc);
	n=min(b.dab,b.dbc);
	return m<n;
}
bool kc(member a,member b){
	int m,n;
	m=min(a.dbc,a.dca);
	n=min(b.dbc,b.dca);
	return m<n;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a,b,c,ans,k;
	member lst[205],ca[205],cb[205],cc[205];
	cin>>t;
	for(int test=0;test<t;test++){
		cin>>n;
		a=0;
		b=0;
		c=0;
		ans=0;
		for(int i=0;i<n;i++){
			cin>>lst[i].ma>>lst[i].mb>>lst[i].mc;
			lst[i].dab=abs(lst[i].ma-lst[i].mb);
			lst[i].dbc=abs(lst[i].mb-lst[i].mc);
			lst[i].dca=abs(lst[i].mc-lst[i].ma);
			ans+=max(max(lst[i].ma,lst[i].mb),lst[i].mc);
			if(lst[i].ma>=max(lst[i].mb,lst[i].mc))ca[a++]=lst[i];
			if(lst[i].mb>=max(lst[i].ma,lst[i].mc))cb[b++]=lst[i];
			if(lst[i].mc>=max(lst[i].ma,lst[i].mb))cc[c++]=lst[i];
		}
		if(a>n/2){
			sort(ca,ca+a,ka);
			k=0;
			while(a>n/2){
				ans-=min(ca[k].dab,ca[k].dca);
				a--;
				k++;
			}
		}
		if(b>n/2){
			sort(cb,cb+b,kb);
			k=0;
			while(b>n/2){
				ans-=min(cb[k].dab,cb[k].dbc);
				b--;
				k++;
			}
		}
		if(c>n/2){
			sort(cc,cc+c,kc);
			k=0;
			while(c>n/2){
				ans-=min(cc[k].dbc,cc[k].dca);
				c--;
				k++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
