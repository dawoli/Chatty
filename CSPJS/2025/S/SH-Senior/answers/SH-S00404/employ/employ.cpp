#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int x[1001];
int main(){
	int n,m,a=0,b=0,c=0,ans=1;
	string s;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') a++;
	}for(int i=0;i<n;i++){
		cin>>x[i];
		if(x[i]<=a) b++;
	}if(n-b >=m){
		for(int i=n;i>=1;i--){
			ans*=i;
		}cout<<ans%N;
		return 0;
	}else{
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]=='0') break;
			c++;
		}if(b>=a){
			for(int i=n-a;i>=1;i--){
				ans*=i;
			}for(int i=b;i>=1;i--){
				ans*=i;
			}cout<<ans%N;
		}
	}
	return 0;
} 
