#include<bits/stdc++.h>
#define int long long
const int bs=29,md=1e9+7,N=2e5+7;
using namespace std;
int n,q;
string s1,s2;
struct edge{
	int a,b,c,d;
}e[N];
unordered_map<int,int>ump2,ump3;
signed main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>n>>q;
	if(n*q<=1e8){
		for(int pt=1;pt<=n;pt++){
			int lst=0,fst=0;
			cin>>s1>>s2;
			if(s1==s2)continue;
			for(int j=0;j<=s1.size()-1;j++)
					if(s1[j]!=s2[j])
					lst=j;
			for(int j=s1.size()-1;j>=0;j--)
				if(s1[j]!=s2[j])
					fst=j;
			int md1=0,md2=0,md3=0,md4=0;
			for(int i=fst;i<=lst;i++){
				md3=(md3*bs%md+(s1[i]-'a'+1))%md;
				md4=(md4*bs%md+(s2[i]-'a'+1))%md;
			}
			for(int i=fst-1;i>=1-1;i--)
				md1=(md1*bs%md+(s1[i]-'a'+1))%md;
			for(int i=lst+1;i<=s1.size()-1;i++)
				md2=(md2*bs%md+(s1[i]-'a'+1))%md;
				e[pt]={md1,md2,md3,md4};
		}
		for(int pt=1;pt<=q;pt++){
			int lst=0,fst=0;
			cin>>s1>>s2;
			if(s1.size()!=s2.size()){
				cout<<"0\n";
				continue;
			}
			for(int j=0;j<=s1.size()-1;j++)
				if(s1[j]!=s2[j])
					lst=j;
			for(int j=s1.size()-1;j>=0;j--)
				if(s1[j]!=s2[j])
					fst=j;
			int md1=0,md2=0,md3=0,md4=0;
			for(int i=fst;i<=lst;i++){
				md3=(md3*bs%md+(s1[i]-'a'+1))%md;
				md4=(md4*bs%md+(s2[i]-'a'+1))%md;
			}
			int ret=0;
			ump2.clear(),ump3.clear();
			ump2[0]++;
			for(int i=fst-1;i>=1-1;i--)
				ump2[md1=(md1*bs%md+(s1[i]-'a'+1))%md]++;
			ump3[0]++;
			for(int i=lst+1;i<=s1.size()-1;i++)
				ump3[md2=(md2*bs%md+(s1[i]-'a'+1))%md]++;
			for(int i=1;i<=n;i++)
				if(e[i].c==md3&&e[i].d==md4&&ump3[e[i].b]&&ump2[e[i].a])
					ret++;
			cout<<ret<<"\n";
		}
	}else{
		
	}
}
