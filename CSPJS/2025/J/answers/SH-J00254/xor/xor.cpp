#include<iostream>
int n,k,s[500001];
int f(int x){
	for(int i=x;i<n;i++){
		if((s[i]^s[x-1])==k){
			for(int j=1;j<=n-i;j++)
				return f(i+j)+1;
		}
	}
	if(s[n]^s[x-1]==k)return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;
		std::cin>>a;
		s[i]=a^s[i-1];
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=std::max(ans,f(i));
	std::cout<<ans;
	return 0;
}
