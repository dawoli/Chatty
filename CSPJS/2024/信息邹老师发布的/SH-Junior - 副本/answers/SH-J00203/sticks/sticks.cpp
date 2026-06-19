#include<bits/stdc++.h>
using namespace std;
int sn[10]={6,2,5,5,4,5,6,3,7,6};
int t,a[214514],k=0;
string s[214514];
int p(int i){
	if(i==0)return 8;
	if(i==1)return 0;
	if(i==2)return 6;
	if(i==3)return 9;
	if(i==4)return 2;
	if(i==5)return 3;
	if(i==6)return 5;
	if(i==7)return 4;
	if(i==8)return 7;
	if(i==9)return 1;
}
int f(int n,int oi)
{
	if(n==t)return n;
	if(n>t)return -1;
	int m=0; 
	for(int o=0;o<10;o++){
		int i=p(o);
		if(n+i==0)continue;
		m=f(sn[i]+n,oi+1);
		a[oi]=i;
//		for(int i=0;i<10;i++)cout<<a[i]<<' ';
//		cout<<endl;
		if(m!=-1){
			if(oi) return m;
			for(int l=0;a[l]!=-1;l++)s[k]+=to_string(a[l]);
			sort(s[k].begin(),s[k].end());
			if(s[k][0]=='0'){
				for(int p=0;p<s[k].size();p++)if(s[k][p]!='0'){
					swap(s[k][0],s[k][p]);
					break;
				}
			}
			k++;
			memset(a,-1,sizeof(a));
		}
		else a[oi]=-1;
	}
}
bool cmp(string a,string b)
{
	bool flag=false;
	for(int i=0;i<a.size();i++)if(a[i]!=0){flag=true;break;}
	if(!flag)return false;
	if(a.size()>b.size())return false;
	if(a.size()<b.size())return true;
	return a<b;
}
void ff()
{
	cin>>t;
	memset(a,-1,sizeof(a));
	f(0,0);
	sort(s,s+k,cmp);
	if(s[0]=="")cout<<-1<<endl;
	else cout<<s[0]<<endl;
	memset(a,-1,sizeof(a));
	for(int i=0;i<1024;i++)s[i]="";
	t=k=0;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(;T>0;T--)ff();
	return 0;
}
