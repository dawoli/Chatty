#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
typedef long long ll;
int r[N],arr[N],num[N];
int n,kinds;
int pray(int p){
	if(p==kinds) return num[p];
	int pn=num[p];
	int ce=p+1;
	while(pn>0&&ce<=kinds){
		if(pn<=arr[ce]){
			arr[ce]-=pn;
			pn=0;
		}
		else{
			pn-=arr[ce];
			arr[ce]=0;
		}
		ce++;
	}
	return pn;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+1+n);
	int counter=0;
	for(int i=1;i<=n;i++){
		if(r[i]!=r[i-1]){
			counter++;
			arr[counter]++; 
		}
		else{
			arr[counter]++;
		}
	}
	kinds=counter;
//	cout<<counter<<endl;
//	for(int i=1;i<=kinds;i++){
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=kinds;i++) num[i]=arr[i];
	
	int ans=0;
	for(int i=1;i<=kinds;i++){
		int py=pray(i);
//		cout<<i<<" "<<py<<endl;
		ans+=py;
	}
	cout<<ans;
	return 0;
} 
