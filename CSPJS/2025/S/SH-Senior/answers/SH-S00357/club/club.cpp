#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c;
}cl[100005];
int t;
int n;
bool cmp1(Node a,Node b){
	if(a.a==b.a){
		return a.b<b.b;
	}
	else return a.a>b.a;
}
bool cmp2(Node a,Node b){
	if(a.b==b.b){
		return a.a<b.a;
	}
	else return a.b>b.b;
}
bool cmp3(Node a,Node b){
	if(a.c==b.c){
		return a.a<b.a;
	}
	else return a.c>b.c;
}
bool cmp(Node a,Node b){
	if(a.a==b.a){
		if(a.b==b.b)return a.c<b.c;
		return a.b<b.b;
	}
	return a.a<b.a;
}
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cl[i].a>>cl[i].b>>cl[i].c;
		}
		
		sort(cl+1,cl+n+1,cmp1);
		int maxn=-1,sum=0;
		for(int i=1;i<=n;i++){
			if(i<=n/2)sum+=cl[i].a;
			else sum+=max(cl[i].b,cl[i].c);
		}
		maxn=max(maxn,sum);
		
		sort(cl+1,cl+n+1,cmp2);
		sum=0;
		for(int i=1;i<=n;i++){
			if(i<=n/2)sum+=cl[i].b;
			else sum+=max(cl[i].a,cl[i].c);
		}
		maxn=max(maxn,sum);
		
		sort(cl+1,cl+n+1,cmp1);
		sum=0;
		for(int i=1;i<=n;i++){
			if(i<=n/2)sum+=cl[i].c;
			else sum+=max(cl[i].b,cl[i].a);
		}
		maxn=max(maxn,sum);
		sum=0;
		int want[10]={0};
		for(int i=1;i<=n;i++){
			int now;
			if(cl[i].a>max(cl[i].b,cl[i].c))now=1;
			else if(cl[i].b>max(cl[i].a,cl[i].c))now=2;
			else now=3;
			if(want[now]+1<=n/2){
				want[now]++;
//				cout<<want[now]<<"\n";
				if(now==1)sum+=cl[i].a;
				else if(now==2)sum+=cl[i].b;
				else sum+=cl[i].c;
			}
			else{
				int now1;
				if(now==1){
					now1=max(cl[i].b,cl[i].c);
				}
				else if(now==2){
					now1=max(cl[i].a,cl[i].c);
				}
				else{
					now1=max(cl[i].a,cl[i].b);
				}
				sum+=now1;
			}
		}
		maxn=max(maxn,sum);
		cout<<maxn<<"\n";
	}
}
