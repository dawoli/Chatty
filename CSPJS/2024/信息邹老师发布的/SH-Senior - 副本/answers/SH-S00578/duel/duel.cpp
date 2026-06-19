#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long n,r[100005],num[100005],pr[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		num[r[i]]++;
	}
	for(int i=0;i<=100000;i++)pr[i]=0;
	for(int i=1;i<=100000;i++){
		if(pr[i-1]<num[i]){
			pr[i-1]=0;
		}
		else{
			pr[i-1]-=num[i];
		}
		pr[i]=num[i]+pr[i-1];
	}
	cout<<pr[100000]<<endl;
	return 0;
}
