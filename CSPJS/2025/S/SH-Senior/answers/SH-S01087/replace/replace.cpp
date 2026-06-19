#include<bits/stdc++.h>
using namespace std;
long long n,q,cnt,jishu,cntt=0;
int sta,en;
bool pd[100010];
string a[100010],b[100010],c[100010],d[100010],e,f;
void go(string x,string y){
cout<<sta<<" "<<en<<endl;
	if(sta<0&&en>c[jishu].length())return;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==x&&b[i]==y&&pd[i])
		{
			pd[i]=0;
			cnt++;
		}
	}
	if(sta>0)
	{
		go(c[jishu][--sta]+x,d[jishu][sta-1]+y);
		sta++;
	}
	if(en<c[jishu].length())
	{
		go(x+c[jishu][++en],y+d[jishu][en+1]);
		en--;
	}
}
int main (){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++){
		cin>>c[i]>>d[i];
		sta=0,en=0;
		for(int j=0;j<c[i].length();j++){
			if(c[i][j]!=d[i][j]){
				e+=c[i][j];
				f+=d[i][j];
				if(cntt==0)sta=j;
				else en=j;
				cntt++;
			}
		}
		jishu=i;
		for(long long i=1;i<=n;i++)pd[i]=1;
		go(e,f);
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
