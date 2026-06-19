#include<bits/stdc++.h>
#include<algorithm> 
using namespace std;
const int N=1e5+5;
int n;
struct Sat{
	int a,b,c;
	int id;
}mem[N];
struct Cul{
	int val;
	int id;
}a[N],b[N];
int capa;
bool cmp(Cul a,Cul b){
	return a.val>b.val;
}
bool chosen[N];

bool cmp1(Sat x,Sat y){
	return x.a>y.a;
}
bool cmp2(Sat x,Sat y){
	return x.b>y.b;                                                              
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		memset(mem,0,sizeof(mem));
		capa=0;
		memset(chosen,0,sizeof(chosen));
		int flag=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>mem[i].a>>mem[i].b>>mem[i].c;
			if(mem[i].c!=0)	flag=0; 
			mem[i].id=i;
		}
		capa=n/2;
		if(flag==1){
			int acnt=1,bcnt=1;
			for(int i=1;i<=n;i++){
				if(mem[i].a>mem[i].b) a[acnt++].val=mem[i].a,a[acnt].id=i;
				else b[bcnt++].val=mem[i].b,b[bcnt].id=i;
			}
			sort(a+1,a+1+acnt,cmp);
			sort(b+1,b+1+bcnt,cmp);
			int ans=0;
			for(int i=1;i<=capa;i++){
				ans+=a[i].val;
				ans+=b[i].val;
			}
			cout<<ans<<endl;
		}
		
	}
	
	return 0;
}
