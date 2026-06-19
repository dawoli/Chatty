#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,m,l,v,t;
ll dk[5005],vk[5005],ak[5005];
struct op{
	ll st;		 //st为区间开头 
	ll en;		 //en为区间结尾 
	bool ifop;	 //记录是否被探测器启动 
	bool chek;	 //记录能否被探测到 
	ll tcq;		 //记录每个区间内的 能探测到最多区间的 探测器编号 
}q[5005];
struct con{
	ll ad;		 //记录该探测器位置 
	ll num;		 //记录该探测器一共能探测的区间数量 
	ll add[5005];//记录该探测机能探测的区间编号，探测器编号/区间编号以 开头大小 从小到大排 
}tc[5005];
int cmp(op x,op y){
	return x.st<y.st;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(ll poi=1;poi<=t;poi++){
		ll cnt=0,ans=0,tot=0,jk=1;
		for(int i=1;i<=n;i++){
			dk[i]=0;
			vk[i]=0;
			ak[i]=0;
			q[i].chek=0;
			q[i].en=0;
			q[i].ifop=0;
			q[i].st=0;
			q[i].tcq=0;
			tc[i].ad=0;
			for(int j=1;j<=n;j++){
				tc[i].add[j]=0;
			}
			tc[i].num=0;
		}
		cin>>n>>m>>l>>v;
		for(ll i=1;i<=n;i++){
			cin>>dk[i]>>vk[i]>>ak[i];
		}
		for(ll i=1;i<=m;i++){
			cin>>tc[i].ad;
		}
		for(ll i=1;i<=n;i++){//记录区块 
			ll d=dk[i];
			ll va=vk[i];
			ll a=ak[i];
			if(a>0){
				if(va>v){
					q[jk].st=d;
					q[jk].en=l;
					jk++;
					tot++;
				}
				else{
					ll vc=v*v-va*va;
					ll al=a*2;
					ll jlk=vc/al;
					if(vc%al==0) jlk++;
					if(d+jlk<=l){
						q[jk].st=d+jlk;
						q[jk].en=l;
						jk++;
						tot++;
					}
				}
			}
			if(a<0){
				if(va>v){
					ll vc=v*v-va*va;
					ll al=a*2;
					ll jlk=vc/al;
					if(vc%al==0) jlk--;
					if(d+jlk<=l){
						q[jk].st=d;
						q[jk].en=d+jlk;
						jk++;
						tot++;
					}
				}
			}
			if(a==0){
				if(va>v){
					q[jk].st=d;
					q[jk].en=l;
					jk++;
					tot++;
				}
			}
			
		}
		sort(q,q+n,cmp);
		ll pl=1;
		for(ll i=1;i<=n;i++){
			ll flag=0;
			for(ll j=1;j<=m;j++){
				if(q[i].st<=tc[j].ad and q[i].en>=tc[j].ad){
					flag=1;
					q[i].chek=1; 
					tc[j].num++;
					tc[j].add[pl]=i;
				}
			}
			if(flag==1) cnt++;
			pl++;
		}
		for(ll i=1;i<=tot;i++){
			ll jln=0,jl=0;
			for(ll j=1;j<=m;j++){
				if(tc[j].ad>=q[i].st and tc[j].ad<=q[i].en){
					if(tc[j].num>jln){
						jln=tc[j].num;
						jl=j;
					}
				}
			}
			q[i].tcq=jl;
		} 
		for(ll i=1;i<=tot;i++){//查找应该被开启的探测器 
			if(q[i].ifop==0 and q[i].chek==1){
				for(ll j=1;j<=tot;j++){
					q[tc[q[i].tcq].add[j]].ifop=1;
					
				}
				ans++;
			}
		}
		cout<<cnt<<" "<<m-ans<<endl;
	}
	return 0;
}
