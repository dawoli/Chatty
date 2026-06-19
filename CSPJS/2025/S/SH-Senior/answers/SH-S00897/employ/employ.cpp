#include<bits/stdc++.h>
using namespace std;
int N,M,p[505],pl[1005],l,Ans;string str;
int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>N>>M>>str;
	for(int i=1;i<=N;i++)pl[i]=i;
	for(int i=1;i<=N;i++)cin>>p[i];sort(p+1,p+1+N);
	do{
		int now=0,cnt=0;
		for(int i=1;i<=N;i++){
			if(p[pl[i]]-now<=0||str[i-1]-'0'==0)cnt--,now++;cnt++;
		}
		if(cnt>=M)Ans++;
	}while(next_permutation(pl+1,pl+1+N));
	cout<<Ans<<endl;
	return 0;
}
