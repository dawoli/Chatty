#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010],tail=0;
struct node{
	int cnt,l,r,num;
}m[1000010];
bool cmp(node t1,node t2){
	return t1.num*(t1.cnt-1)>t2.num*(t2.cnt-1);
}
long long dfs(int step,int rlast,int blast){
	if(step==n) return 0;
	long long ans1 = dfs(step+1,a[step],blast);
	if(rlast==a[step]) ans1+=rlast;
	long long ans2 = dfs(step+1,rlast,a[step]);
	if(blast==a[step]) ans2+=blast;
	return max(ans1,ans2);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(long long T=0;T<t;T++){
		cin>>n;
		if(n<24){
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			long long ans = dfs(0,-1,-1);
			cout<<ans<<"\n";
		}
		else{
			for(int i=0;i<n;i++){
				m[i].cnt = 0;
				m[i].l = 0xff;
				m[i].r = -1;
				m[i].num = 0;
			}
			for(int i=0;i<n;i++){
				cin>>a[i];
				bool flag=true;
				for(int j=0;j<tail;j++){
					if(m[j].num==a[i]){
						m[j].cnt++;
						if(m[j].l>i) m[j].l=i;
						if(m[j].r<i) m[j].r=i;
						flag = false;
						break;
					}
				}
				if(flag){
					m[tail].num = a[i];
					m[tail].cnt++;
					m[tail].l = i;
					m[tail].r = i;
					tail++;
				}
			}
			sort(m,m+tail,cmp);
			
			long long lr=-1,rr=-1,lb=-1,rb=-1,ans=0;
			for(int i=0;i<tail;i++){
				if(lr==-1 && rr==-1){
					lr = m[i].l;
					rr = m[i].r;
					ans += (m[i].cnt-1)*m[i].num;
				}
				else if(m[i].r<lr){
					lr = m[i].l;
					ans += (m[i].cnt-1)*m[i].num;
				}
				else if(m[i].l>rr){
					rr = m[i].r;
					ans += (m[i].cnt-1)*m[i].num;
				}
				
				else if(lb==-1 && rb==-1){
					lb = m[i].l;
					rb = m[i].r;
					ans += (m[i].cnt-1)*m[i].num;
				}
				else if(m[i].r<lb){
					lb = m[i].l;
					ans += (m[i].cnt-1)*m[i].num;
				}
				else if(m[i].l>rb){
					rb = m[i].r;
					ans += (m[i].cnt-1)*m[i].num;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

