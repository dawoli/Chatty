#include<bits/stdc++.h>
using namesapace std;
const int N=1e5+10;
int a[100010];
int main(){
	freopen("duel.in","r"stdin);
	freopen("duel.in","w",stdout);
	cin>>n;
	cout<<n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>a[j]]){
				sum+=1;
				sort(a+1,a+n+1);
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdont);
	return 0;
}

