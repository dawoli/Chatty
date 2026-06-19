#include<bits/stdc++.h>
using namespace std;
int s[15][1000005]={0},size[15],a[15][200005];
int ans[15]={0},tmp[15]={0},num[15]={0};
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;cin>>T;
	for(int i=0;i<T;i++){
		cin>>size[i];
		for(int j=0;j<size[i];j++){
			cin>>a[i][j];s[i][a[i][j]]++;
		}
	}
	for(int i=0;i<T;i++){
		for(int j=1;j<1000005;j++){
			int x=0;
			if(s[i][j]>1)x=s[i][j]-1;
			ans[i]+=x*j;
			num[i]+=s[i][j];
//			cout<<i<<" "<<j<<" "<<x<<" "<<ans[i]<<endl;
			if(num[i]==size[i]) break;
			
		}
	}
	for(int i=0;i<T;i++)cout<<ans[i]<<endl;
	return 0;
} 
