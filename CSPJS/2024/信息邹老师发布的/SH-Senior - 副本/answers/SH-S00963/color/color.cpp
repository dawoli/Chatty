#include <bits/stdc++.h>
using namespace std;

int T,n,ans;
int a[200005]; 
int p[200005];
int b[200005];

int check(int c){
	int st=0;
	for(int i=1;i<=n;i++){
		if(a[i]==c && p[i]==0){
			st=i;
		}
	}
	for(int i=st;i<=n;i++){
		if(a[i]==c && p[i]==0) break;
		if(p[i]==1) return false;
	}
	return true;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int aa=1;aa<=T;aa++){
		ans=0;
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		for(int i=n;i>=1;i--){
			if(b[i]==b[i-1]){
				if(check(b[i])){
					ans+=b[i];
				}
				i--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
