#include<bits/stdc++.h>
using namespace std;
bool vis[100005];
int s[100005];
int n; 
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	int left=1,right=2,sum=n;
	while(right<=n){
		if(s[left]<s[right]){
			sum--;
			left++;
			right++;
		}
		else
			right++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
