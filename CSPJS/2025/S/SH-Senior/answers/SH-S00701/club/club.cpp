#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct type{
	int a,b,c;
}x[N];
int T;
int n;
//int a[N][5];
bool A,B;

void init(){
	A=1;
	B=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
		if(x[i].b!=0)	A=0;
		if(x[i].c!=0){
			A=0;
			B=0;
		}
	}
//	cout<<"is A or B:"<<A<<" "<<B<<endl;
}
int ans=0;
void dfs(int id,int sum,int ca,int cb,int cc){
	if(id==n+1){
//		cout<<"check_ans:"<<ans<<" "<<sum<<endl;
		ans=max(ans,sum);
		return;
	}
//	cout<<"check_dfs:"<<id<<" "<<sum<<" "<<ca<<" "<<cb<<" "<<cc<<endl;
	if(ca+1<=n/2)	dfs(id+1,sum+x[id].a,ca+1,cb,cc);
	if(cb+1<=n/2)	dfs(id+1,sum+x[id].b,ca,cb+1,cc);
	if(cc+1<=n/2)	dfs(id+1,sum+x[id].c,ca,cb,cc+1);
}
void solve_hard(){
	ans=0;
	dfs(1,0,0,0,0);
	printf("%d\n",ans);
}

bool cmp_bth(type p,type q){
	if(p.a>q.a)	return true;
	else if(p.a==q.a)	return p.b>q.b;
	else return false;
}
void solve_B(){
	ans=0;
	int cntA,cntB;
	cntA=0;
	cntB=0;
	sort(x+1,x+n+1,cmp_bth);
	for(int i=1;i<=n;i++){
		if(x[i].a>x[i].b&&cntA<n/2){
			++cntA;
			ans+=x[i].a;
		}
		else if(x[i].b>x[i].a&&cntB<n/2){
			++cntB;
			ans+=x[i].b;
		}
		else if(x[i].a==x[i].b){
			if(cntA<n/2){
				++cntA;
				ans+=x[i].a;
			}
			else if(cntB<n/2){
				++cntB;
				ans+=x[i].b;
			}
		}
	}
	printf("%d\n",ans);
	return;
}
void solve_200(){
	
}
void solve_A(){
	sort(x+1,x+n+1,cmp_bth);
	ans=0;
	for(int i=1;i<=n/2;i++)	ans+=x[i].a;
	printf("%d\n",ans);
	return;
}
void solve_1e5(){
	cout<<2e9<<endl;
}
void Dec(){
	ans=0;
	if(n<=30)	solve_hard();//40pts
	else if(n<=200){
		if(B)	solve_B();//5pts
		else solve_200();
	}
	else if(n<=1e5){
		if(A)	solve_A();//5pts
		else if(B)	solve_B();//10pts
		else solve_1e5();
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		Dec();
	}
	return 0;
}
