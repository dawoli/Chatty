#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int no,ac,bc,cc,val;
};
int a[N],b[N],c[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		queue<node>q;
		node st;
		st.no=1;
		st.bc=0;
		st.cc=0;
		st.ac=0;
		st.val=0;
		q.push(st);
		int ans=0;
		while(!q.empty()){
			node tmp=q.front();
			if(tmp.no==n+1)
			{
				ans=max(ans,tmp.val);
			}
			q.pop();
			if(tmp.no<=n)
			{
				if(tmp.ac<n/2)
				{
					node ne;
					ne.ac=tmp.ac+1;
					ne.bc=tmp.bc;
					ne.cc=tmp.cc;
					ne.val=tmp.val+a[tmp.no];
					ne.no=tmp.no+1;
					q.push(ne);
				}
				if(tmp.bc<n/2)
				{
					node ne;
					ne.ac=tmp.ac;
					ne.bc=tmp.bc+1;
					ne.cc=tmp.cc;
					ne.val=tmp.val+b[tmp.no];
					ne.no=tmp.no+1;
					q.push(ne);
				}
				if(tmp.cc<n/2)
				{
					node ne;
					ne.ac=tmp.ac;
					ne.bc=tmp.bc;
					ne.cc=tmp.cc+1;
					ne.val=tmp.val+c[tmp.no];
					ne.no=tmp.no+1;
					q.push(ne);
				}	
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

