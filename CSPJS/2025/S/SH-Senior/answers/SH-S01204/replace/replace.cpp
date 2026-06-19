#include<bits/stdc++.h>
using namespace std;
int n,q,d[10000005];
string x,y;

struct node{
	string s1,s2;
}a[5000005];

bool df(string xx,int begin,int end,string yy,int begin1,int end1){
	if(end-begin!=end1-begin1) return 1;
	for(int i=0;i<end1-begin1;i++){
		if(xx[i+begin]!=yy[i+begin1]){
			return 1;
		}
	}
	return 0;
}


int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	bool flagB=1;
	cin>>n>>q;
	int L=0;
	
	if(n<=100){
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2;
		}
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			int ans=0,l=x.size();
			int bg=l,ed=0;
			for(int j=0;j<l;j++){
				if(x[j]!=y[j]){
					bg=j;
					break;
				}
			}
			for(int j=l-1;j>=0;j--){
				if(x[j]!=y[j]){
					ed=j;
					break;
				}
			}
			for(int j=1;j<=n;j++){
				int l1=a[j].s1.size();
				int bg1=l1,ed1=0;
				for(int p=0;p<l1;p++){
					if(a[j].s1[p]!=a[j].s2[p]){
						bg1=p;
						break;
					}
				}
				for(int p=l1-1;p>=0;p--){
					if(a[j].s1[p]!=a[j].s2[p]){
						ed1=p;
						break;
					}
				}
//				printf("%d %d %d\n",i,bg,ed);
//				printf("%d %d %d\n",j,bg1,ed1);
				if(!df(x,bg,ed+1,a[j].s1,bg1,ed1+1) && !df(y,bg,ed+1,a[j].s2,bg1,ed1+1)){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	return 0;
}
