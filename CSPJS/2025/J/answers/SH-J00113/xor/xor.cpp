#include<bits/stdc++.h>
using namespace std;
unsigned long long a[500002];
unsigned long long p[500002];
//freopen
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]^a[i];
	}
	unsigned long long ans=0;
	for(int i=1;i<=n;i){
		unordered_map<unsigned long long,int>mp;
		unsigned long long value=0;
		bool f=0;
		for(int j=i;j<=n;j++){
			value^=a[j];
			if(value==k){
				ans++;
				i=j+1;
				//cout<<i<<"!";
				f=1;
				break;
			}else{
				if(mp.count(value^k)){
					ans++;
					//cout<<i<<"!";
					i=j+1;
					f=1;
					break;
				}
			}
			mp[value]=1;
		}
		if(!f)break; 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

