#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[1000001][2];
string ll1,ll2;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int w=0;w<q;w++){
		cin>>ll1>>ll2;
		int na=0,nb=0;int wrb=0;
		for(int i=0;i<ll1.length();i++){
			if(ll1[i]=='a') na++;
			if(ll1[i]=='b'){
				nb++;
				wrb=i;
			}
		}
		int na2=0,nb2=0;int wrb2=0;
		for(int i=0;i<ll1.length();i++){
			if(ll1[i]=='a') na2++;
			if(ll1[i]=='b'){
				nb2++;
				wrb2=i;
			}
		}  
		if(ll1.length()!=ll2.length()){
			cout<<"0"<<endl;
			continue;
		}
		if(nb==1&&nb2==1&&na2==(ll1.length()-1)&&na==(ll1.length()-1))
		{
			int ans=0;
			int ds=wrb2-wrb;
			for(int j=0;j<n;j++){
				int sb1=0,sa1=0,wrsb1=0;
				int sb2=0,sa2=0,wrsb2=0;
				for(int k=0;k<s[j][0].length();k++){
					if(s[j][0][k]=='a')sa1++;
					if(s[j][1][k]=='a')sa2++;
					if(s[j][0][k]=='b')
					{
						sb1++;
						wrsb1=k;
					}
					if(s[j][1][k]=='b'){
						sb2++;
						wrsb2=k;
					}
				}
				if(sa1==(s[j][0].length()-1)&&sa2==(s[j][0].length()-1)&&sb1==1&&sb2==1){
					if(ds==wrsb2-wrsb1&&min(wrb,wrb2)>=min(wrsb1,wrsb2)&&(ll1.length()-max(wrb,wrb2))>=(s[j][0].length()-min(wrsb1,wrsb2))) ans++;
				}
			}
			cout<<ans<<endl;
			continue;
		}
//		else
//		{
			int ans=0;
			int len=ll1.length();
			for(int i=0;i<len;i++){
				for(int j=0;j<n;j++){
					if(s[j][0][0]==ll1[i])
					{
						bool flg=1;
						for(int k=0;k<s[j][0].length();k++){
							if(ll1[i+k]!=s[j][0][k])flg=0;
						}
						if(flg==1){
							bool flg1=1;
							for(int k=0;k<s[j][0].length();k++){
								if(ll2[i+k]!=s[j][1][k])flg1=0;
							}
						//	cout<<"2,"<<flg1<<" "<<i+k<<" "<<k<<endl;
							if(flg1==1){
								bool flg2=1;
								for(int k=0;k<len;k++){
									if((k<i||k>=i+s[j][0].length())&&ll1[k]!=ll2[k]){
										flg2=0;
									}
								}
								if(flg2==1){
									ans++;
								//	cout<<ans<<" "<<i<<" "<<j<<endl;///////////////////
								}
							}
						}
					}
				}
			}
			cout<<ans<<endl;
//		}
	}
	return 0;
}
