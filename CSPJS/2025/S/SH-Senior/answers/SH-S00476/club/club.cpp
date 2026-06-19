#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;
struct node{
	long long a,b,c,mx;
	long long va,vb,vc;
};
node mem[100100];
bool cmp(node x,node y){
	if(x.mx==y.mx){
		if(x.va==x.mx){
			if(max(x.vc,x.vb)==max(y.vc,y.vb)){
				if(x.vb==max(x.vc,x.vb)&&y.vb==x.vb){
					return x.vc<y.vc;
				}
				else if(x.vc==max(x.vc,x.vb)&&y.vc==x.vc){
					return x.vb<y.vb;
				}
			}
			return max(x.vb,x.vc)<max(y.vb,y.vc);
		}
		else if(x.vb==x.mx){
			if(max(x.vc,x.va)==max(y.vc,y.va)){
				if(x.va==max(x.vc,x.va)&&y.va==x.va){
					return x.vc<y.vc;
				}
				else if(x.vc==max(x.vc,x.vb)&&y.vc==x.vc){
					return x.va<y.va;
				}
			}
			return max(x.va,x.vc)<max(y.va,y.vc);
		}
		else if(x.vc==x.mx){
			if(max(x.va,x.vb)==max(y.va,y.vb)){
				if(x.vb==max(x.va,x.vb)&&y.b==x.vb){
					return x.va<y.va;
				}
				else if(x.va==max(x.va,x.vb)&&y.va==x.va){
					return x.vb<y.vb;
				}
			}
			return max(x.vb,x.va)<max(y.vb,y.va);
		}
	}
	return x.mx>y.mx;
}
bool c2(node x,node y){
	return x.a>y.a;
}
int mxn=0;
void dfs(int aa,int i,int a,int b,int c){
	mxn=max(mxn,aa);
	if(i>n)return ;
	aa+=mem[i].a;
	if(a<n/2)
	dfs(aa,i+1,a+1,b,c);
	aa-=mem[i].a;
	aa+=mem[i].b;
	if(b<n/2)
	dfs(aa,i+1,a,b+1,c);
	aa-=mem[i].b;
	aa+=mem[i].c;
	if(c<n/2)
	dfs(aa,i+1,a,b,c+1);
	aa-=mem[i].c;
	return ;
}
void solve(){
	map<int,int>mpa;
	map<int,int>mpb;
	map<int,int>mpc;
	long long ans=0;
	bool spj2=1,spj3=1;
	node cnt={0,0,0,0};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>mem[i].a>>mem[i].b>>mem[i].c;
		int a=mem[i].a,b=mem[i].b,c=mem[i].c;
		if(mem[i].b!=0)spj2=0;
		if(mem[i].c!=0)spj3=0;
		mem[i].va=2*a-b-c;
		mem[i].vb=2*b-a-c;
		mem[i].vc=2*c-a-b;
		mem[i].mx=max(max(mem[i].va,mem[i].vb),mem[i].vc);
	}
	if(n<=10){//%20
		mxn=0;
		dfs(0,1,0,0,0);
		cout<<mxn<<'\n';
		return ;
	}
	if(spj2==1){//%5
		sort(mem+1,mem+1+n,c2);
		for(int i=1;i<=n;i++){
			cnt.a++;
			ans+=mem[i].a;
			if(cnt.a==n/2)break;
		}
		cout<<ans<<'\n';
		return ;
	}
	else{
		priority_queue<int,vector<int>,greater<int> >q1;
		priority_queue<int,vector<int>,greater<int> >q2;
		priority_queue<int,vector<int>,greater<int> >q3;
		bool j1=1,j2=1,j3=1;
		int ma,mb,mc;
		sort(mem+1,mem+1+n,cmp);
		sort(mem+1,mem+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(mem[i].va==mem[i].mx){
				if(cnt.a<n/2){
					q1.push(mem[i].a);
					mpa[mem[i].a]=i;
					cnt.a++;
				}
				else{
					int j=q1.top();
					if(mem[mpa[j]].a<mem[i].a){
						if(mem[j].b>mem[j].c){
							q2.push(mem[mpa[j]].b);
							mpb[mem[mpa[j]].b]=j;
						}
						else{
							q3.push(mem[mpa[j]].c);
							mpc[mem[mpa[j]].c]=j;
						}
						q1.pop();
						q1.push(-mem[i].a);
					}
				}
			}
			else if(mem[i].vb==mem[i].mx){
				if(cnt.b<n/2){
					q2.push(mem[i].b);
					mpb[mem[i].b]=i;
					cnt.b++;
				}
				else{
					int j=q2.top();
					if(mem[mpb[j]].b<mem[i].b){
						if(mem[j].a>mem[j].c){
							q1.push(mem[mpb[j]].a);
							mpa[mem[mpb[j]].a]=j;
						}
						else{
							q3.push(mem[mpb[j]].c);
							mpc[mem[mpb[j]].c]=j;
						}
						q2.pop();
						q2.push(mem[i].b);
					}
				}
			}
			else if(mem[i].vc==mem[i].mx){
				if(cnt.c<n/2){
					q3.push(mem[i].c);
					mpc[mem[i].c]=i;
					cnt.c++;
				}
				else{
					int j=q3.top();
					if(mem[mpa[j]].c<mem[i].c){
						if(mem[j].b>mem[j].a){
							q2.push(mem[mpc[j]].b);
							mpb[mem[mpc[j]].b]=j;
						}
						else{
							q1.push(mem[mpc[j]].a);
							mpa[mem[mpc[j]].c]=j;
						}
						q3.pop();
						q3.push(mem[i].c);
					}
				}
			}
		}
		while(q1.size()){
			ans+=q1.top();
			q1.pop();
		}
		while(q2.size()){
			ans+=q2.top();
			q2.pop();
		}
		while(q3.size()){
			ans+=q3.top();
			q3.pop();
		}
		cout<<ans<<'\n';
	}
	for(int i=1;i<=n;i++){
		mem[i].a=0,mem[i].b=0,mem[i].c=0,mem[i].mx=0;
		mem[i].va=0,mem[i].vb=0,mem[i].vc=0;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
 
