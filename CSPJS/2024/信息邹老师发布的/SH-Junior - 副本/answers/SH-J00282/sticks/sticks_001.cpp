#include<bits/stdc++.h>
using namespace std;
const int cnta[10]={6,2,5,5,4,5,6,3,7,6};
int t,n;
unsigned long long ans=2222222222222222222;
int as[100009],lth;
bool flag=false;
struct numb{
	int ct;
	int id;
}a[10];
void init(){
	a[0].ct=7,a[0].id=8;
	a[1].ct=6,a[1].id=0;
	a[2].ct=6,a[2].id=6;
	a[3].ct=6,a[3].id=9;
	a[4].ct=5,a[4].id=2;
	a[5].ct=5,a[5].id=3;
	a[6].ct=5,a[6].id=5;
	a[7].ct=4,a[7].id=4;
	a[8].ct=3,a[8].id=7;
	a[9].ct=2,a[9].id=1;
}
void solven7(int g){
	for(int i=1;i<=g/7;i++)
		cout<<8;
	cout<<endl;
}
void solven17(int g){
	if(g!=1)
		cout<<"10";
	else{
		cout<<-1<<endl;
		return;
	}
	for(int i=1;i<(g-1)/7;i++)
		cout<<"8";
	cout<<endl;
}
void dfs(int x,int cnt,unsigned long long k){
	if(cnt>n)return;
	if(cnt==n){
		ans=min(ans,k);
		return;
	}
	if(k>ans)return;
	for(int i=0+(x==1);i<=9;i++){
		unsigned long long g=k*10+i;
		dfs(x+1,cnt+cnta[i],g);
	}
}
void solve(int x,int cnt){
	if(flag)return;
	if(cnt==n){
		flag=true;
		lth=x-1;
		return;
	}
	if(cnt>n)
		return;
	for(int i=0;i<=9;i++){
		if(x==1&&a[i].id==0)continue;
		as[x]=a[i].id;
		solve(x+1,cnt+a[i].ct);
		if(flag)
			break;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	init();
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==0)
			solven7(n);
		else if((n-1)%7==0)
			solven17(n);
		else if(n<=20){
			ans=2222222222222222222;
			dfs(1,0,0);
			if(ans!=2222222222222222222)
				cout<<ans<<endl;
			else
				cout<<-1<<endl;
		}
		else{
			flag=false;
			solve(1,0);
			if(!flag)cout<<-1<<endl;
			else{
				for(int i=1;i<=lth;i++)cout<<as[i];
				cout<<endl;
			}
		}
	}
	return 0;
}
