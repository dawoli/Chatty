#include <bits/stdc++.h>
using namespace std;
int s[100005];
bool v[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int sum=n;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[i]>s[j]&&!v[j]){
				sum--;
				v[j]=1;
				break;
			}
		}
	}
	cout<<sum;
	return 0; 
} 
