#include<bits/stdc++.h>
using namespace std;
int n,q;
string x,y,a,b,c,d;
struct cg{
	int x,y,z;
	bool operator<(const cg&aaa)const{
		if (y!=aaa.y) return y<aaa.y;
		if (x!=aaa.x) return x<aaa.x;
		return z<aaa.z;
	}
}h[200009];
string s[1009],t[1009],sam_1[1009],sam_2[1009];
void solveBF(){
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		int pos=0,cnt1=0,cnt2=0;
		while(s[i][pos]==t[i][pos]){
			pos++;
			cnt1++;
		}
		sam_1[i]=s[i].substr(0,pos);
		pos=s[i].size()-1;
		while(s[i][pos]==t[i][pos]){
			pos--;
			cnt2++;
		}
		for(int j=s[i].size()-cnt2;j<=s[i].size()-1;j++)
			sam_2[i]+=s[i][j];
		s[i]=s[i].substr(cnt1,s[i].size()-cnt1-cnt2);
		t[i]=t[i].substr(cnt1,t[i].size()-cnt1-cnt2);
//		cout<<s[i]<<' '<<t[i]<<' '<<sam_1[i]<<' '<<sam_2[i]<<endl;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>a>>b;
		int pos=0,cnt1=0,cnt2=0;
		while(a[pos]==b[pos]){
			pos++;
			cnt1++;
		}
		c=a.substr(0,pos);
		pos=a.size()-1;
		while(a[pos]==b[pos]){
			pos--;
			cnt2++;
		}
		for(int j=a.size()-cnt2;j<=a.size()-1;j++)
			d+=a[j];
		a=a.substr(cnt1,a.size()-cnt1-cnt2);
		b=b.substr(cnt1,b.size()-cnt1-cnt2);
		for(int j=1;j<=n;j++){
			if (a==s[j]&&b==t[j]){
//				cout<<j<<endl;
				if (c.substr(c.size()-sam_1[j].size(),sam_1[j].size())==sam_1[j]&&d.substr(d.size()-sam_2[j].size(),sam_2[j].size())==sam_2[j]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
//		cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	}
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if (n<=1000){
		solveBF();
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		int posa=0,posb=0;
		for(int j=0;j<x.size();j++)
			if (x[j]=='b')
				posa=j;
		for(int j=0;j<y.size();j++)
			if (y[j]=='b')
				posb=j;
		h[i].x=posa;h[i].y=posb-posa;h[i].z=x.size()-posa-1;
//		cout<<h[i].x<<' '<<h[i].y<<' '<<x<<' '<<y<<endl;
	}
	sort(h+1,h+n+1); 
//	for(int i=1;i<=n;i++) cout<<h[i].x<<' '<<h[i].y<<endl;
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		int posa=0,posb=0;
		for(int j=0;j<a.size();j++)
			if (a[j]=='b')
				posa=j;
		for(int j=0;j<b.size();j++)
			if (b[j]=='b')
				posb=j;
		int p=posb-posa,o=posa,op=a.size()-posa-1;
		int l=1,r=n,mid,lp=0,rp=0;
		while(l<=r){
			mid=(l+r)>>1;
			if (h[mid].y<p) l=mid+1;
			else if (h[mid].y>p) r=mid-1;
			else{
				lp=mid;
				r=mid-1;
			}
		}
		l=1,r=n,mid=0;
		while(l<=r){
			mid=(l+r)>>1;
			if (h[mid].y<p) l=mid+1;
			else if (h[mid].y>p) r=mid-1;
			else if (h[mid].x>o) r=mid-1;
			else{
				rp=mid;
				l=mid+1;
			}
		}
//		cout<<o<<' '<<p<<endl;
		if (lp!=0&&rp!=0){
			int cnt=0;
			for(int i=lp;i<=rp;i++)
				if (h[i].z<=op)
					cnt++;
			cout<<cnt<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
//4 4
//aaab aaba
//ab ba
//aab baa
//aba aab
