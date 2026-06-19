#include<iostream>
#define int long long
using namespace std;
const int N=5e5+5;
int arr[N],timex[N],timey[N],xtime=0,ytime=0,ans=0;
int xornum(int a,int b){
	int n=arr[a];
	for(int i=a+1;i<=b;i++){
		n^=arr[i];
	}
	return n;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>arr[i];
	while(true){
		bool flag=true;
		for(int i=1;i<=n;i++){
			bool flag3=false;
			for(int j=i;j<=n;j++){
				bool flag2=false;
				for(int l=1;l<=xtime;l++){
					if(i==timex[l]){
						flag2=true;
					}
				}
				if(!flag){
					for(int l=1;l<=ytime;l++){
						if(j==timey[l]){
							flag2=true;
						}
					}
				}
				if(flag2)continue;
				if(xornum(i,j)==k){
					xtime++,ytime++;
					timex[xtime]=i,timey[ytime]=j;
					flag=false;
					flag3=true;
					break;
				}
			}
			if(flag3)break;
		}
		if(flag)break;
		else ans++;
	}
	cout<<ans;
	fclose(stdin); 
	fclose(stdout); 
	return 0;
}
