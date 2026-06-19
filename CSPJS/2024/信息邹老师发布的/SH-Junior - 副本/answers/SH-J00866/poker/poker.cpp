#include<bits/stdc++.h>
using namespace std;
char s[55],num[55];
int n;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	int ans=n;
	for(int i=0;i<n;i++){
		cin>>s[i]>>num[i];
	}
	if(n==1){
		cout<<52-ans;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(s[i]==s[j] && num[i]==num[j])ans-=1;
		}
	}
	cout<<52-ans;
	return 0;
}
