#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	int n,k,sum=0;
	scanf("%d %d",&n,&k);
	const int con=n;
	int a[con];
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if (sum==n){
		printf("%d",n/2);
	}else{
	if (sum<n){
		int cnt=0;
		vector<int> v;
		v.push_back(-1);
		for (int i=0;i<n;i++){
			if (i<n-1&&a[i]!=a[i+1]) v.push_back(i);
		}
		v.push_back(n-1);
		if (k==0){
			for (int i=0;i<n;i++){
				if (a[i]==0) ++cnt;
			}
			for (int i=0;i<v.size()-1;++i){
				if (v[i+1]-v[i]>1&&a[i+1]==1) ++cnt;
			}
			printf("%d",cnt);
		}else{
			for (int i=1;i<v.size()-2;++i){
				if (v[i+1]-v[i]>1){
					cnt+=2;
				}else{
					++cnt; 
				}
			}
			printf("%d",cnt);
		}
		
		
	}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
