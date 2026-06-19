#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
string s[N],s2[N],s3,s4;
int n,m,cnt;
bool flag,flag1,flag2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
	}
	for(int i=1;i<=n;i++){
		flag=flag1=flag2=0;
		cin>>s3>>s4;
		int x=s3.size();
		for(int i=0;i<x;i++){
			for(int j=i;j<x;j++){
				for(int k=1;k<=n;k++){
					for(int l=i;l<=j;l++){
						int t=0;
						if(s3[l]!=s1[t]){
							flag=1;
							break; 
						} 
						else t++;
					}
					if(flag==0){
						for(int l=0;l<i;l++){
							if(s3[l]!=s4[l]){
								flag1=1;
								break;
							}
						}
						for(int l=j+1;l<x;l++){
							if(s3[l]!=s4[l]){
								flag2=1;
								break;
							}
						}
						if(flag1==0&&flag2==0) cnt++; 
					}
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
