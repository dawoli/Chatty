#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
bool flag[500005];
int ans=0;
void x(int l){
	bool Break=true;
	for(int i=1;i<=n-l+1;i++){
		bool f=false;
		for(int j=i;j<=i+l-1;j++){
			if (flag[j]==true){
				f=true;
				break;
			}
		}
		if(f)continue;
		Break=false;
		if((a[i+l-1] xor a[i-1])==k){
			for(int j=i;j<=i+l-1;j++){
				flag[j]=true;
			}
			ans++;
		}
	}
	if(Break)return ;
	x(l+1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=(a[i-1] xor a[i]);
	}
	x(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
