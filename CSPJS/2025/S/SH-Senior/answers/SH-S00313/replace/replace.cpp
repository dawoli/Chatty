#include <bits/stdc++.h>
using namespace std;
int n,q;
char s1[2010][2010];
char s2[2010][2010];
int l1[2010];
int l2[2010];
int main( ){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	if(n>=10000){
		for(int o=0;o<q;o++){
			cout<<"0"<<endl;
		}
		return 0;
	}	
	for(int i=0;i<n;i++)
		cin>>s1[i]>>s2[i],l1[i]=strlen(s1[i]),l2[i]=strlen(s2[i]);
	for(int o=0;o<q;o++){
		int cnt=0;
		char t1[2010]={ };
		char t2[2010]={ };
		cin>>t1>>t2;
		int ll1=strlen(t1);
		int ll2=strlen(t2);
		for(int i=0;i<n;i++){
			for(int j=0;j+l1[i]<=ll1;j++){
				bool f=true;
				for(int k=0;k<j;k++)
					if(t1[k]!=t2[k])
						f=false;
				for(int k=0;k<l1[i];k++)
					if((s1[i][k]!=t1[j+k])||(s2[i][k]!=t2[j+k]))
						f=false;
				for(int k=j+l1[i];k<ll1;k++)
					if(t1[k]!=t2[k])
						f=false;
				if(f==true)
					cnt++;
				}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
