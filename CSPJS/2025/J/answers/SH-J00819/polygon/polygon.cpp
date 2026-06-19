#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD=998244353;
int n__,sticks[5005],temp[5001];
bool check(int nn){
	if(nn<3)return 0;
	int t=temp[nn-1],s=0;
	for(int i=0;i<nn;i++)s+=temp[i];
	return (s>(2*t));
}
int bweu(vector<bool>t,int yhyu){
	if(yhyu<n__){
		t.push_back(1);
		int n_=bweu(t,yhyu+1)%MOD;
		t[yhyu]=0;
		return (n_+bweu(t,yhyu+1)%MOD);
	}
	int cnt=0;
	for(int i=0;i<n__;i++)
		if(t[i]){
			temp[cnt]=sticks[i];
			cnt++;
		}
	return check(cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n__);
	if(n__<=3){
		if(n__!=3){cout<<0<<endl;return 0;}
		if(n__==3){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			int t=max(a,max(b,c)),s=a+b+c;
			if(s>(2*t))putchar('1');
			else putchar('0');
			return 0;
		}
	}
	for(int i=0;i<n__;i++)scanf("%d",&sticks[i]);
	sort(sticks,sticks+n__);
	vector<bool>a;
	printf("%d",bweu(a,0)%MOD);
	return 0;
}
