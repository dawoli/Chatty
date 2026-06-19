//yihou ^
#include<iostream>
using namespace std;
int n,k,ans=0;
int a[500010],s[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int la=0;
	for(int i=1;i<=n;i++){
		if(i<=la) continue;
		for(int j=i;j<=n;j++){
			if((s[i-1]^s[j])==k){
				la=j;
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
