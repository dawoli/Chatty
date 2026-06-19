#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=5e5+10;
int a[N],n,k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){//A
		int fl=1,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=1) fl=0;
			if(a[i]==0) cnt++;
		}
		if(fl){
			cout<<n/2;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}else{
			cout<<cnt;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}else if(k<=1){//B
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}cout<<cnt;
		fclose(stdin);
		fclose(stdout);
	}else{//1-13
		int cnt=0;
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				int chu=a[i];
				for(int kk=i+1;kk<=j;kk++){
					int lin=(chu xor a[kk]);
					chu=lin;
				}
				if(chu==k){
					cnt++;
					cout<<chu<<' '<<i<<' '<<j<<'\n';
				}
			}
		}
		cout<<cnt; 
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}
