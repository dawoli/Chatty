#include<bits/stdc++.h>
using namespace std;
string b[55];
int n,sum=52,k=1;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	bool m=0;
	for (int i=1;i<=n;i+=1){
		cin>>b[i];
		m=0;
		for (int j=1;j<i;j++){//如果牌和之前有重复则不减，否则需要借的牌-1 
			if (b[i]==b[j]) m=1;
		}
		if (m==0) sum--;
	}
	if (sum<0) sum=0;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
