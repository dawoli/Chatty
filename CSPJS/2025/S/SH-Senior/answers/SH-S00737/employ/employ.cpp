#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n;int s;bool pass[510];int stand[510];
int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ3.out","w",stdout);
	cin>>n>>s;
	string H;cin>>H;
	for(int i=0;i<=H.size()-1;i++)
		pass[i+1]=H[i]-'0';
	for(int i=1;i<=n;i++)
		cin>>stand[i];
//	if(s==1){
//		int ans=0;
//		for(int i=1;i<=n;i++){
//			int d=stand[i];
//			for(int j=1;j<=d;j++)
//				if(pass[j]){
//					ans=(ans+)
//				}
//		}
//		cout<<ans<<endl;
//		return 0;
//	}
	int ind=H.find('0');
	if(ind>=0 && ind<=n-1){
		if(s==n) 
			cout<<"0"<<endl;
		return 0;
	}
	else{
		long long ans=1;
		for(long long i=n;i>=1;i--)
			ans=ans*i%M;
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
