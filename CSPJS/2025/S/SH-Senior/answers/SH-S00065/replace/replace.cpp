#include<iostream>
#include<vector>
using namespace std;
const int N=2e5;
int n,q,ans,b1[N],b2[N];
string s1[N],s2[N],t1,t2;
vector<int>nex[N],diff[N<<1];
bool spe=true;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		if(spe)
			for(int j=0;j<s1[i].size();j++)
				if(s1[i][j]!='a'&&s1[i][j]!='b'){
					spe=false;
					break;
				}else if(s1[i][j]=='b')b1[i]=j;
		if(spe){
			for(int j=0;j<s2[i].size();j++)
				if(s2[i][j]=='b')b2[i]=j;
			diff[b2[i]-b1[i]+N].push_back(i);
		}
		nex[i].push_back(0),nex[i].push_back(0);
		for(int j=2,k=0;j<=s1[i].size();j++){
			while(k&&s1[i][k]!=s1[i][j-1])k=nex[i][k];
			if(s1[i][k]==s1[i][j-1])k++;
			nex[i].push_back(k);
		}
	}
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
		ans=0;
		if(spe){
			int b3=0,b4=0;
			for(int j=0;j<t1.size();j++)
				if(t1[j]=='b')b3=j;
			for(int j=0;j<t2.size();j++)
				if(t2[j]=='b')b4=j;
			for(int j=0;j<diff[b4-b3+N].size();j++){
				int k=diff[b4-b3+N][j];
				if(b1[k]<=b3&&s2[k].size()-b2[k]<=t2.size()-b4)ans++;
			}
		}else{
			for(int j=0;j<n;j++){
				for(int k=1,l=0;k<=t1.size();k++){
					while(l&&l<=s1[j].size()&&s1[j][l]!=t1[k-1])l=nex[j][l];
					if(s1[j][l]==t1[k-1])l++;
					if(l==s1[j].size()){
						string t3=t1;
						for(int m=1;m<=s2[j].size();m++)t3[k-s2[j].size()+m-1]=s2[j][m-1];
						if(t3==t2){
							ans++;
							break;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
