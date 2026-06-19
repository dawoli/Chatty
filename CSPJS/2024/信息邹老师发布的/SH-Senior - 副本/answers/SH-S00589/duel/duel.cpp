#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr[100029];
int tong[100029];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		tong[arr[i]]++;
	}
	int cnt=0;
	int temp=0;
	for(int i=0;i<100009;i++){
		if(tong[i]>0){
			cnt+=min(temp,tong[i]);
			temp+=tong[i]-min(temp,tong[i]);
		}
	}
	cout<<n-cnt;
	return 0;
}
