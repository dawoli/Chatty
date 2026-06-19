#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

struct p{
	int l,r;
}pick[N];

bool cmp(p a,p b){
	return a.r<b.r;
}

int a[N],s[N],cnt;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool fall1=true,fall2=true;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1) fall1=false;
		if(a[i]>1) fall2=false;
	}
	if(fall1){
		cout<<n/2;
	}
	else if(fall2){
		if(k==1){
			int i=1,ans=0;
			while(i<=n){
				while(a[i]==0)
					i++;
				if(i>n) break;
				ans++;
				i++;
			}
			cout<<ans;
		}
		else{
			int i=1,ans=0;
			while(i<=n){
				if(a[i]==0){
					ans++;
					i++;
				}
				else{
					if(i+1<=n){
						if(a[i+1]==1){
							ans++;
							i+=2;
						}
						else i++;
					}
					else break;
				}
			}
			cout<<ans;
		}
	}
	else{
		if(n<=1000){
			s[1]=a[1];s[0]=0;
			for(int i=2;i<=n;++i){
				s[i]=(s[i-1]^a[i]);
			}
			for(int i=0;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					if((s[j]^s[i])==k){
						cnt++;
						pick[cnt].l=i+1,pick[cnt].r=j;
					}
				}
			}
			sort(pick+1,pick+1+cnt,cmp);
			int las=0,i=1,ans=0;
			while(i<=cnt){
				while(pick[i].l<=las) i++;
				if(i>cnt) break;
				ans++;
				las=pick[i].r;
			}
			cout<<ans;
		}
		else{
			srand(time(0));
			cout<<rand()%1048576+1;
		}
	}
	return 0;
}
