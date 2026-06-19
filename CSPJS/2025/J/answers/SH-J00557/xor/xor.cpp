#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans=0,t[500005],s[500005]={},vgt=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	a[0]=-1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			a[i]=-1;
			t[i]=-1;
		}else{
			if(a[i-1]==-1) s[vgt++]=i; 
		}
	}
	if(n==1){
		cout<<ans;
		return 0;
	}

	for(long long i=1;i<vgt;i++){
		long long begin=s[i];
		t[s[i]]=a[s[i]];
		bool flag=0;
		for(long long j=s[i]+1;a[j]!=-1&&j<=n&&!flag;j++){
			t[j]=(t[j-1]^a[j]);
			if(t[j]==k){
				ans++;
				j++;
				if(a[j]==-1||j>=n){
					flag=1;
					break;
				}
				begin=j;
				t[j]=a[j];
				continue;
			}
			if(flag) break;
			for(long long l=begin;l<=j-2;l++){
				if((t[j]^t[l])==k){
					ans++;
					j++;
					if(a[j]==-1||j>n){
						flag=1;
						break;
					}
					begin=j;
					t[j]=a[j];
					break;
				} 
			}
			if(flag) break;
		}
	}
	/*for(long long i=1;i<=n;i++){
		cout<<t[i]<<" ";
	}
	cout<<endl;*/
	cout<<ans<<endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}

