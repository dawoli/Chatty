#include <bits/stdc++.h>
using namespace std;
struct node
{
	int like,l;
}a[114514];
bool cmp(node x,node y)
{
	return x.l<y.l;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int ans=0;
	int x=0,y=0,z=0;
	for(int i=1;i<=n;i++)
	{
		int A,b,c;
		cin>>A>>b>>c;
		ans+=max(A,max(b,c));
		if(A>max(b,c)){
			a[i].like = 1;
			a[i].l=min(A-b,A-c);
			x++;
		}
		if(b>max(A,c)){
			a[i].like = 2;
			a[i].l = min(b-A,b-c);
			y++;
		}
		if(c>max(A,b)){
			a[i].like=3;
			a[i].l=min(c-A,c-b);
			z++;
		}
	}
	int flag1,flag2;
	if(x>n/2)flag1=1,flag2=x-n/2;
	else if(y>n/2)flag1=2,flag2=y-n/2;
	else if(z>n/2)flag1=3,flag2=z-n/2;
	sort(a+1,a+n+1,cmp);
	for(int i = 1;flag2;i++)
	{
		if(a[i].like==flag1)
		{
			flag2--;
			ans-=a[i].l;
		}
	}
	cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
