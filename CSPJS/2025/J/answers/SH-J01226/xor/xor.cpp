#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		if(k && a[i])ans++;
		if(!k){
			if(!a[i])ans++;
			else if(a[i]&&a[i-1] && i>0){
				i++;ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
