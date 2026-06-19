#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int preb1[200005],aftb1[200005];
int preb2[200005],aftb2[200005],minlen[200005];
int cha[200005];
vector <int> c[200005];
//struct d{
//	int anscha,anslen;
//	bool operator < (const d & x)const {
//		anscha<
//	}
//};
int tcha[200005];
//d a[200005];
int pre(string u){
	int ans=0;
	for(int i=0;i<u.size();i++){
		if(u[i]!='b')ans++;
		else break;
	}
	return ans;
}
int aft(string u){
	int ans=0;
	for(int i=u.size()-1;i>=0;i--){
		if(u[i]!='b')ans++;
		else break;
	}
	return ans;
}
int main(int argc, char** argv) {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	string s1,s2;
//	cin >> s1 >> s2;
//	cout << pre(s1) << " " << aft(s1)<< endl;
	for(int i=1;i<=n;i++){
		string x,y;
//		cin >> x >> y;
		preb1[i]=pre(x);aftb1[i]=aft(x);
		preb2[i]=pre(y);aftb2[i]=aft(y);
		int t=preb1[i]-preb2[i];
		if(t<0)t*=-1;
		cha[i]=t;
		tcha[cha[i]]++;
		c[cha[i]].push_back(min(preb1[i],preb2[i]));
		minlen[i]=min(preb1[i],preb2[i]);
	}
//	for(int i=1;i<=200000;i++){
//		sort(c[i],c[i]+c[i].size());
//	}
	
	for(int i=1;i<=q;i++){
		int ans=0;
		string x,y;
//		cin >> x >> y;
		cout << 0 << endl;
//		int qcha=pre(x)-pre(y);
//		for(int i=1;i<=n;i++){
//			if(preb1[i]-preb2[i]==qcha){
//				if(preb1[i]<=pre[x] and preb1[i]<=pre[y] and preb2[i]<=pre[x] and preb2[i]<=pre[y] and aftb1[i]<=aft)
//			}
//		} 
		cout << ans << endl;
//		int minq=min(pre(x),pre(y));
//		if(qcha<0)qcha*=-1;
//		int anst=tcha[qcha];
////		int ss=upperc[qcha]
//		for(int i=0;i<c[qcha].size();i++){
//			if(minq>=c[qcha][i]){
//				ans++;
//			}
//		}
//		cout  << ans << endl;
		
		// if(cha==qcha and minlen<minq
	}
	return 0;
}
/*
*/
