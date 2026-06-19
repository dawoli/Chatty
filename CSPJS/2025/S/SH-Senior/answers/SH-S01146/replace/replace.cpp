#include<bits/stdc++.h>
using namespace std;
const int maxl=2005,maxn=2e5+5;
long long n,q,ca[maxn],cc[maxn],f=1,ch[maxn][5];
string a[maxn],b[maxn],c[maxn],d[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int s=0;s<a[i].size();s++){
			if(a[i][s]!='a'||a[i][s]!='b'||b[i][s]!='a'||b[i][s]!='b') f=0;
			if(a[i][s]!=b[i][s]){
				ca[i]=s;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>c[i]>>d[i];
		for(int s=0;s<c[i].size();s++){
			if(c[i][s]!='a'||c[i][s]!='b') f=0;
		}
		for(int s=0;s<d[i].size();s++){
			if(d[i][s]!='a'||d[i][s]!='b') f=0;
		}
	}
	if(f){
		for(int i=1;i<=n;i++){
			for(int s=0;s<a[i].size();s++){
				if(a[i][s]=='b') ch[i][1]=s;
				if(b[i][s]=='b') ch[i][2]=s;
			}
		}
		for(int i=1;i<=q;i++){
			long long cnt=1;
			if(c[i].size()!=d[i].size()){
				cout<<0<<endl;
				continue;
			}
			for(int s=0;s<c[i].size();s++){
				if(c[i][s]=='b') ch[i][3]=s;
				if(d[i][s]=='b') ch[i][4]=s;
			}
			for(int j=1;j<=n;j++){
				if(ch[i][4]-ch[i][3]==ch[j][2]-ch[j][1]&&ch[i][3]>=ch[j][1]&&c[i].size()-ch[i][3]>=a[j].size()-ch[j][1]) cnt++;
			}
			cout<<cnt<<endl;
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		long long cnt=0;
		if(c[i].size()!=d[i].size()){
			cout<<0<<endl;
			continue;
		}
		for(int s=0;s<c[i].size();s++){
			if(c[i][s]!=d[i][s]){
				cc[i]=s;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			bool flag=true;
			string t=c[i];
			if(ca[j]>cc[i]||cc[i]-ca[j]+a[j].size()>c[i].size()) continue;
			for(int s=cc[i]-ca[j];s<=cc[i]-ca[j]+a[j].size()-1;s++){
				if(c[i][s]==a[j][s-(cc[i]-ca[j])]){
					c[i][s]=char(b[j][s-(cc[i]-ca[j])]);
				}else{
					flag=false;
//					cout<<c[i]<<' '<<i<<' '<<j<<' '<<c[i][s]<<' '<<a[j][s-(cc[i]-ca[j])]<<endl<<"j:"<<j<<" s:"<<s<<endl;
					break;
				}
			}
			if(flag){
				for(int s=0;s<=c[i].size()-1;s++){
					if(c[i][s]!=d[i][s]){
						flag=false;
//						cout<<"S:"<<s<<endl;
					}
				}
			}
			if(flag) cnt++;
			c[i]=t;
		}
		cout<<cnt<<endl;
	}
//	for(int i=1;i<=n;i++) cout<<ca[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=q;i++) cout<<cc[i]<<' ';
}
