#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N = 200005;
string a[N],b[N],c,d,e,f;
int n,q;
int work()
{
//	cout<<4<<endl;
	int sz = c.size(),sz1,top = 0,ans = 0;
	for(int i = 1;i <= n;i++) {
		top = 0;
//		cout<<i<<endl;
//		cout<<a[i].size()<<' '<<c.size()<<endl;
		if(c.size() < a[i].size())
			continue;
		while(c.find(a[i],top) != string::npos) {
//			cout<<c.find(a[i],top)<<' '<<top<<endl;
			top = c.find(a[i],top);
			top++;
			sz1 = top - 1;
			e = c.substr(0,sz1);
			f = c.substr(top + a[i].size() - 1,sz - sz1 - a[i].size());
			e = e + b[i] + f;
			if(e == d)
				ans++;
		}
	}
	return ans;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
//	cout<<1<<endl;
	for(int i = 1;i <= n;i++)
		cin>>a[i]>>b[i];
//	for(int i = 1;i <= n;i++)
//		cout<<a[i]<<b[i];
//	cout<<2<<endl;
	for(int i = 1;i <= q;i++) {
		cin>>c>>d;
//		cout<<3<<endl;
		printf("%d\n",work());
	}
	fclose(stdin),fclose(stdout);
	return 0;
}
