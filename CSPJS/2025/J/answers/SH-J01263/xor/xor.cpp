#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=false;
	}
	if(k==0&&f){
		cout<<"0";
		return 0;
	}
	int ans=0,t;
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			flag=true;
		}
		else{
			if(flag){
				t=a[i];
				flag=false;
			}		
			else{
				t=t^a[i];
				if(t==k){
					ans++;
					flag=true;
				}
			}
		}
	}
	cout<<ans;
	//#Shang4Shan3Ruo6Shui4
	return 0;
}
