#include<bits/stdc++.h>
using namespace std;
int a[505050];
bool f[2][50550];
int n,k;
bool chk255(){
	for(int i = 1;i<=n;i++)
		if(a[i]>255)return 0;
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++)cin>>a[i];
	
	if(n<=1000){int l=1,cnt=0;
		for(int i = 1;i<=n;i++){
			int mq=0;
			for(int j = i;j>=l;j--){
				mq^=a[j];
				if(mq==k)cnt++,l=i+1;
			}
		}
		cout<<cnt;		
	}
	else if(chk255()){
		int ans=0; 
		f[0][0]=1;
		for(int i = 1;i<=n;i++){
			if(f[i-1&1][k^a[i]]==1 or (a[i]==k)){
				memset(f,0,sizeof(f));
				f[i&1][0]=1;
				ans++;continue;
			}
			else{
				memset(f[i&1],0,sizeof(f[i&1]));
				for(int j = 0;j<=255;j++)
					f[i&1][j^a[i]]|=f[i-1&1][j];
				f[i&1][a[i]]=1;
			}
		}
		cout<<ans;
	} 
	else cout<<0;
} 
