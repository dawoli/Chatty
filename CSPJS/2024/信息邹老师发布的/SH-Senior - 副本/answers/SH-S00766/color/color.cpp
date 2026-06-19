#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+5;
int t,n,a[N];
ll ans,res;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x*f;
}

void solveBF(){
	for(int i=0;i<(1<<n);++i){
		int r=-1,b=-1; ans=0;
		for(int j=0;j<n;++j){
			int k=i&(1<<j);
			if(k==0){
				if(r!=-1)
					if(a[j]==a[r])
						ans+=a[j];
				r=j;
			}
			else{
				if(b!=-1)
					if(a[j]==a[b])
						ans+=a[j];
				b=j;
			}
		}
		res=max(ans,res);
	}
	cout<<res<<endl;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=0;i<n;++i) a[i]=read();
		res=0;
		solveBF();
	}
	return 0;
}
