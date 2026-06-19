#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
pair<int,int>ans[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int f=0;
	for(int i=1;i<=n;i++){
		int m=a[i];
		if(m==k) ans[f]=make_pair(i,i),f++;
		for(int j=i+1;j<=n;j++){
			m^=a[j];
			if(m==k) ans[f]=make_pair(i,j),f++;
		} 
	}
	int l=ans[0].second;
	int k=1;
	for(int i=0;i<f;i++){
		if(ans[i].first>l) k++,l=ans[i].second;
	}
	cout << k;
	return 0;
}
