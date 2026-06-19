#include<bits/stdc++.h>
using namespace std;
struct node
{
	int d,v,a;
}q[100001];
struct Node1
{
	int s1,s2;
}r[100001];
bool cmp(struct Node1 m,struct Node1 n)
{
	return m.s2<n.s2; 
}
int main()
{
    int T;
    cin>>T;
    for(int z=1;z<=T;z++)
    {
    int n,m,L,V;
    cin>>n>>m>>L>>V;
    int p[m];
    for(int i=1;i<=n;i++)cin>>q[i].d>>q[i].v>>q[i].a;
    for(int i=1;i<=m;i++)cin>>p[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
    	if(q[i].a==0){
    		if(q[i].v>V){cnt++;
    			r[cnt].s1=q[i].d;
    			r[cnt].s2=L;
			} 
		}
		if(q[i].a>0){
    		if(q[i].v>V){cnt++;
    			r[cnt].s1=q[i].d;
    			r[cnt].s2=L;
			} 
				if(q[i].v==V){cnt++;
    			r[cnt].s1=q[i].d+1;
    			r[cnt].s2=L;
			} 
					if((q[i].v<V)&&(((V*V-q[i].v*q[i].v)/(2*q[i].a)+q[i].d)<L)){cnt++;
    			r[cnt].s1=q[i].d+abs((q[i].v*q[i].v-V*V)/(2*q[i].a))+1;
    			r[cnt].s2=L;
			} 
	    }
		if(q[i].a<0){
    		if(q[i].v>V){cnt++;
    			r[cnt].s1=q[i].d;
    			r[cnt].s2=q[i].d+abs((q[i].v*q[i].v-V*V)/(2*q[i].a));
    			if(r[cnt].s2>L)r[cnt].s2=L; 
			} 
		}
	
		}
			sort(r+1,r+cnt+1,cmp);
int ans1=0;
		for(int i=1;i<=cnt;i++)
		{
			if(p[m]>=r[i].s1)ans1++;
	
	}
	int ans2;
		 if(ans1==0)ans2=m;
		 else ans2=m-1;
			
	
	cout<<ans1<<" "<<ans2<<"\n";
}
	
		return 0;
    
}

	
