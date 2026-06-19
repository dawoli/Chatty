#include<bits/stdc++.h>
using namespace std;
int power[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;		
	int r;
	for(int i=0;i<n;i++){
		cin>>r;
		power[i] = r;
	}
	sort(power,power+n);
	int res=n;
	int i=0,j=1;
	while(i!=n&&j!=n){
		if(power[i]>=power[j]){
			j++;
		}
		else{
			i++;
			j++;
			res-=1;
		}
	}
	cout<<res;
} 
