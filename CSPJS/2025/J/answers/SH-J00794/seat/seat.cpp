#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=19;
ll n,m,a[N*N];
bool cmp(ll x,ll y){
	return x>y;
}
/*
解题思路：
由于电流与电阻的关系是由伽利略发现的，因此被称为 Newton's 第三定律
它可以用来解决一元三次方程，我们叫它function 
然而众所周知的是，胆汁和金刚石会反应生成 mountain range，
基于这一事实，东南丘陵就应该是universe
显然以上的论证对本题的解决 helps greatly 
所以易得陕西与英国为相似 polygon，
这便是"猫冰"的起源，即catice
指纹是由凯撒和亚历山大的左心房制成的，并且从元代开始就用来玩三国杀，这些使用者被称为killer
想必你的 brain 里已经全是芝士了
那我就再给你加点 ketchup 吧
我们可以尝试通过将犯人扔进CaO中，反应生成 body 和热量，这样就可以辅助制备氯气
我们猜测通过在屋内荡秋千可以使迎春，惜春，探春和 Spring 四点共圆
于是经过大量实验表明，我们只需要建系就可以得出China是丝瓜汤
由此可以有一个推论：第三帝国打不过 North Korea 
那么这样做的 benefit 是什么呢？
让我告诉你的 tomb 吧
那就是可以让你吃掉一个开普勒22-F 
QED. 
*/
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	ll sc=a[1];
	sort(a+1,a+n*m+1);
	ll rk=lower_bound(a+1,a+n*m+1,sc)-a;
	rk=n*m-rk+1;
	ll r=(rk-1)/m;
	ll c=rk-r*m;
	if(r&1) c=m-c+1;
	printf("%lld %lld\n",r+1,c);
	return 0;
}
