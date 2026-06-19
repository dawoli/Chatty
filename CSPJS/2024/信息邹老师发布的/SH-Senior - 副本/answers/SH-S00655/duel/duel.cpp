#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
const int N=100005;
struct node{
	int num,cishu;
};
int n,m,l[N],ll[N],ans,l2[N];//l读入 ll判断 shu记录数的种类和出现次数  l2方便 
node shu[N];
bool cmp(const node x,const node y){
	return x.num < y.num;
}
signed main(){
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> l[i];
		if (!ll[l[i]]){
			m++;
			shu[m].num=l[i];
			shu[m].cishu++;
			ll[l[i]]=m;
		}
		else shu[ll[l[i]]].cishu++;
	} 
	sort (shu,shu+m,cmp);
	for (int i=1;i<=m;i++) l2[i]=shu[i].cishu;
	
	for (int i=2;i<=m;i++){
		l2[i] = max(l2[i] , l2[i - 1]);
	}
	cout << l2[m] << endl;
	return 0;
}
