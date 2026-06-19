#include<bits/stdc++.h>
using namespace std;
long long a[500100],n,k,l,r,cnt=0;
long long mark[500100];
bool isdel[500100];
long long q=1;
long long calc(int s,int e){
	long long  ans=0;
	for(int i=s;i<=e;i++){
		ans^=a[i];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(l=1;l<=n;l++){
		for(r=l;r<=n;r++){
			//cout<<l<<' '<<r<<endl;////
			if(calc(l,r)==k){
				cnt++;
				//cout<<'r'<<endl;////
				if(mark[l]>0 && isdel[mark[l]]==0){
					cnt--;
					isdel[mark[l]]=1;
				}
				if(mark[r]>0 && r!=l && isdel[mark[r]]==0) cnt--;
				for(int i=l;i<=r;i++) mark[i]=q;
				q++;
				//cout<<l<<' '<<r<<endl;////
				break;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
