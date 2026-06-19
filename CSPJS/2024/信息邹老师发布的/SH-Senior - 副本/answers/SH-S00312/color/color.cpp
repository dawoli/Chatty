#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
struct col{
	int a[N],n,c[N],ans;
	bool vis[N];
};
col oo[15];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>oo[i].n;
		for(int j=1;j<=oo[i].n;j++){
			cin>>oo[i].a[j];
		}
		oo[i].c[1]=0;
	}
	for(int i=1;i<=t;i++){
		int tmp=1;
		for(int j=2;j<=oo[i].n;j++){
			for(int k=j;k<=oo[i].n;i++){
				if(oo[i].a[j]==oo[i].a[k]&&oo[i].vis[k-1]==0){
					oo[i].vis[j]=1;oo[i].vis[k]=1;
					oo[i].c[tmp]=oo[i].a[k];
					oo[i].ans+=oo[i].c[tmp];
					tmp++;
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<oo[i].ans<<endl;
	}
	return 0;
}
