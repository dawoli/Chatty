#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a,s[n+1],top=0;
	long long num=0;
	s[0]=0;
	for(int i=1;i<=n;i++) cin>>a,s[i]=s[i-1]^a;
	//for(int i=1;i<=n;i++) cout<<s[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=top;j<i;j++){
			if((s[i]^s[j])==k){
				num++;
				top=i;
				break;
			}
		}
	}
	cout<<num;
	return 0;
}
