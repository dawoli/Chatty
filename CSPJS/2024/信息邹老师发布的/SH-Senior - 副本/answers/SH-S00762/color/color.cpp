#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int a[200005]={0},n;
ull ans,maxx;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t,fn,lst0,lst1;
	bool tmp;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		maxx=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		fn=1<<n;
		for(ull i=0;i<=fn;i++){
			ans=0;lst0=0,lst1=0;
			for(int j=1;j<=n;j++){
				tmp=((ull)1<<(j-1)&i);
				if(tmp){
						if(a[lst1]==a[j]) ans+=a[j];
						lst1=j;
					} 
				else{
					if(a[lst0]==a[j]) ans+=a[j];
						lst0=j;
				}
			}
			maxx=max(maxx,ans);
		}
		cout<<maxx<<endl;
	}
	return 0;
} 
