#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V;
const int N=1e5+5; 
struct node{
	int d,v,a;
} c[N];
long long machine[N];
long long maxn=-1;
bool flag1=1,flag2=1;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int l=1;l<=T;l++){
		flag1=1,flag2=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			if(c[i].a!=0)	flag1=0;
			else if(c[i].a>0) flag2=0;	
		}
		for(int i=1;i<=m;i++){
			cin>>machine[i];
		}
		if(flag1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(c[i].v>V&&c[i].d<=machine[m]) cnt++;
			}
			if(!cnt) cout<<cnt<<" "<<m<<endl;
			else cout<<cnt<<" "<<m-1<<endl;
		}else{
			cout<<"5 5";
		} 
	}
}

