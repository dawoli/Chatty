#include<bits/stdc++.h>
using namespace std;
int a[200000],t[200000];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	sort(a+1,a+1+n);
	int minn=a[1],maxx;
	for(int i=1;i<=n;i++){
		if(minn!=a[i]){
			maxx=a[i];
			if(t[minn]<=t[maxx]){
				cnt-=t[minn];
				t[minn]=0;
				minn=maxx;
				while(minn==a[i+1]){
					i++;
				}
			}
			else{
				//t[minn]-=t[maxx];
				cnt-=t[maxx];
				while(maxx==a[i+1]){
					i++;
				}
			}
		}
	}
	/*
	int flag=a[1];
	cnt=t[a[1]];
	for(int i=1;i<=n;i++){
		if(flag!=a[i]){
			cnt+=t[a[i]];
			flag=a[i];
		}
	}
	*/
	cout<<cnt;
	return 0;
}
/*
10
136 136 136 2417 136 136 2417 136 136 136

*/
