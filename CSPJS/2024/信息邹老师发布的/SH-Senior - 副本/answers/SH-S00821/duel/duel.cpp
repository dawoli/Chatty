#include<bits/stdc++.h>
using namespace std;
int n,sum;
map<int,int> cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++){
		int Num=it->second;
		if(Num>=sum) sum=0;
		else sum-=Num;
		sum+=Num;
	}
	cout<<sum<<endl;
	return 0;
}
