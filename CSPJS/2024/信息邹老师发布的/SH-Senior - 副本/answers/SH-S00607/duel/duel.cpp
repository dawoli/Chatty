#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	long long n,tmp;
	long long a[MAXN];
	cin>>n;
	long long ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int currentnum=a[1];
	int continuous=0;
	int numforextinction=0;
	a[n+1]=-1;
	for(int i=1;i<=n+1;i++){
		if(a[i]==currentnum){
			continuous++;
		}
		else{
			currentnum=a[i];
			if(numforextinction>=continuous){
				ans-=continuous;
			}
			else{
				ans-=numforextinction;
				numforextinction=continuous;
			}
			continuous=1;
		}
	}
	cout<<ans;
	return 0;
} 
