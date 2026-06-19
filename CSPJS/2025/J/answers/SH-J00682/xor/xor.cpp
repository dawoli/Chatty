#include<bits/stdc++.h>
using namespace std;
const int N=500009;
int a[N];
map<int,bool> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)a[i]^=a[i-1];
	int cnt=0;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		if(mp[a[i]^k]){
			cnt++;
			mp.clear();
		}
		mp[a[i]]=1;
	}
	cout<<cnt;
	return 0;
}
/*
Óë¾ý¸èÒ»Çú£¬Çë¾ýÎªÎÒÇã¶úÌý
Öé±¦¬ƒÓñ²»×ã¹ó£¬µ«Ô¸³¤×í²»Ô¸ÐÑ
¹ÅÀ´Ê¥ÏÍ½Ô¼ÅÄ¯£¬Î©ÓÐÒûÕßÁôÆäÃû 
*/
