#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5030];
int maxn=0;
int b[5030];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}if(maxn==1){
		int ans=0;
		for(int i=3;i<=n;i++){
			int p=1;
			int x=1;
			for(int j=1;j<=i;j++){
				p=(p*(n-j+1))%mod;
				x=(x*j)%mod;
			}ans+=p/x;
		}cout<<ans;
		return 0;
	}if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}return 0;
	}if(n==4){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k])){
						ans++;
					}
				}
			}
		}if(a[1]+a[2]+a[3]+a[4]>2*max(max(a[1],a[2]),max(a[3],a[4]))){
			ans++;
		}cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	int ans=0;
	string s[100001];
	int t[5001]={};
	for(int i=1;i<=n;i++){
		string sm="";
		int x=a[i];
		while(x){
			int f=x%10;
			sm+=f+'0';
			x/=10;
		}if(t[a[i]]>0){
			string nmk="";
			for(int i=1;i<=t[a[i]];i++){
				nmk+="#";
			}
			s[i]=sm+nmk;
		}
		else{
			s[i]=sm;
		}t[a[i]]++;
	}
	return 0;
}
