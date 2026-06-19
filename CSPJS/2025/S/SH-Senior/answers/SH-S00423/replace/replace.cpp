#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int ans;
string xy[200005][3];
int lenms[200005][3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool flg=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		xy[i][1]=s1,xy[i][2]=s2;
		int lt1=s1.length(),lt2=s2.length();
		lenms[i][0]=lt1-lt2;
		int sb1,sb2;
		for(int j=0;j<lt1;j++) if(s1[j]=='b'){sb1=j;break;}
		for(int j=0;j<lt2;j++) if(s2[j]=='b'){sb2=j;break;}
		lenms[i][1]=sb1;lenms[i][2]=sb2;
		if(s1==s2) cnt++;
		for(int j=0;j<lt1;j++) if(s1[j]!='a' and s1[j]!='b'){flg=1;break;}
		for(int j=0;j<lt2;j++) if(s2[j]!='a' and s2[j]!='b'){flg=1;break;}
	}
	if(flg){
		while(m--){
			ans=0;
			string t1,t2;
			cin>>t1>>t2;
			int l=0,r=0;
			int lt1=t1.length(),lt2=t2.length();
			int len=min(lt1,lt2);
			string k1="",k2="";
			for(int i=0;i<len;i++)
				if(t1[i]==t2[i])
					l++;
				else break;
			for(int i=1;i<=len;i++)
				if(t1[lt1-i]==t2[lt2-i])
					r++;
				else break;
			if(l==len-1){cout<<cnt<<endl;continue;}
			for(int i=l;i<lt1-r;i++) k1+=t1[i];
			for(int i=l;i<lt2-r;i++) k2+=t2[i];
			string prv="";
			for(int j=0;l-j>=0;j++){
				if(j!=0) if(t1[l-j]!=t2[l-j]) break;
				if(j!=0) prv=t1[l-j]+prv;
				string lst="";
				for(int k=0;k<=r;k++){
					if(k!=0) if(t1[lt1-r-1+k]!=t2[lt2-r-1+k]) break;
					if(k!=0) lst+=t1[lt1-r-1+k];
					for(int i=1;i<=n;i++)
						if(prv+k1+lst==xy[i][1] and prv+k2+lst==xy[i][2])
							ans++;
				}
			}
			cout<<ans<<endl;
		}
	}else{
		while(m--){
			ans=0;
			string t1,t2;
			cin>>t1>>t2;
			int fb1=-1,fb2=-1;
			int lt1=t1.length(),lt2=t2.length();
			for(int j=0;j<lt1;j++) if(t1[j]=='b'){fb1=j;break;}
			for(int j=0;j<lt2;j++) if(t2[j]=='b'){fb2=j;break;}
			int lenm=lt1-lt2;
			for(int i=1;i<=n;i++){
				string s1=xy[i][1],s2=xy[i][2];
				int ls1=s1.length(),ls2=s2.length();
				int sb1=lenms[i][1],sb2=lenms[i][2];
				int lst1=ls1-sb1,lst2=ls2-sb2;
				if(lenm==lenms[i][0]){
					if((sb2-sb1)==(fb2-fb1) and fb2>=sb2 and fb1>=sb1 and lt1-fb1>=ls1-sb1 and lt2-fb2>=ls2-sb2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
