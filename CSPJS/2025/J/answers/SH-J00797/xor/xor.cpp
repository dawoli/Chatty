#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],cnt=0;
int xs(int l,int r){
	int ans=a[r];
	for(int j=l;j<r;j++){
		ans^=a[j];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	int l=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=l;j<=i;j++){
			if(xs(j,i)==m){
				cnt++;
				l=i+1;
				break;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
