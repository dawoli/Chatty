#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x^=x;
	int f=1;
	char a=getchar();
	while('0'>a||a>'9'){
		if(a=='-')f=-1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=f;
	return ;
}
const int SIZE=2e5+9;
int n,q,ans;
string s1[SIZE],s2[SIZE],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);
	read(q);
	int i,t,j,k,t0;
	bool right;
	for(i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		ans^=ans;
		cin>>t1>>t2;
		if(t1.size()==t2.size())for(i=0;i<n;i++){
			right^=right;
			if(s1[i].size()>t1.size())continue;
			if(t1.find(s1[i])==-1)continue;
			for(j=s1[i].size();j<=t1.size();j++){
				string temp=t1.substr(j-s1[i].size(),s1[i].size());
				string temp2=t2.substr(j-s1[i].size(),s1[i].size());
				if(temp==s1[i]&&temp2==s2[i]){
					for(k=0;k<s1[i].size();k++)t1[j-s1[i].size()+k]=s2[i][k];
					if(t1==t2)right=1,ans++;
					for(k=0;k<s1[i].size();k++)t1[j-s1[i].size()+k]=s1[i][k];
					if(!right)break;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
