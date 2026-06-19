#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V,cnt,cnt2;
struct num{
	int A=0,B=1; 
};
struct car{
	int d,v,a;
	num p,q;
	bool p0,q0;//0->端点处超速 1->端点处不超速 
	int ll,rr;
}t[100001];
bool cmp(car X,car Y)
{
	return X.ll < Y.ll || (X.ll == Y.ll && X.rr < Y.rr);
}
int det[100001];
/*bool find(int XA,int XB,bool X0,int YA,int YB,bool Y0)
{
	int lbound=1,rbound=m,mid;
	while(true)
	{
		mid=(lbound+rbound)/2;
		if(det[mid]*XB<XA
		||(det[mid]*XB==XA&&X0==1)) lbound=mid+1;
		else if(det[mid]*YB>YA
		||(det[mid]*YB==YA&&Y0==1)) rbound=mid;
		else return true;
		if(lbound==mid) break;
	}
	return false;
}*/
int findl(int XA,int XB,bool X0,int YA,int YB,bool Y0)
{
	int lbound=1,rbound=m,mid;
	while(true)
	{
		mid=(lbound+rbound)/2;
		if(det[mid]*XB<XA
		||(det[mid]*XB==XA&&X0==1)) lbound=mid+1;
		else if(det[mid]*XB>XA
		||     (det[mid]*XB==XA&&X0==0)) rbound=mid;
		if(lbound==mid) break;
	}
	return mid;
}
int findr(int XA,int XB,bool X0,int YA,int YB,bool Y0)
{
	int lbound=1,rbound=m,mid;
	while(true)
	{
		mid=(lbound+rbound)/2;
//		cout << lbound << " " << mid << " " << rbound << endl;
		if(det[mid]*YB<YA
		||(det[mid]*YB==YA&&Y0==0)) lbound=mid+1;
		else if(det[mid]*YB>YA
		||(det[mid]*YB==YA&&Y0==1)) rbound=mid-1;
		if(rbound==mid) break;
	}
	return mid;
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	for(int z = 1; z <= T; z++)
	{
		cin >> n >> m >> L >> V;
		cnt=0;
		for(int i = 1; i <= n; i++)
		{
			cin >> t[i].d >> t[i].v >> t[i].a;
			t[i].p.B=1;
			t[i].q.B=1;
		}
		for(int i = 1; i <= m; i++)
		{
			cin >> det[i];
		}
		for(int i = 1; i <= n; i++)
		{
			if(t[i].a<=0&&t[i].v<=V)
			{
				t[i].p.B=0;
			}
			else if(t[i].a>=0&&t[i].v>V)
			{
				t[i].p.A=t[i].d;
				t[i].q.A=L;
			}
			else if(t[i].a<0&&t[i].v>V)
			{
				t[i].p.A=t[i].d;
				int X,Y;
				X=t[i].v*t[i].v-V*V;
				Y=-2*t[i].a;
				if(Y*L<X) t[i].q.A=L;
				else
				{
					t[i].q.A=X+t[i].d*Y;
					t[i].q.B=Y;
					t[i].q0=1;
				}
			}
			else if(t[i].a>0&&t[i].v<=V)
			{
				int X,Y;
				X=V*V-t[i].v*t[i].v;
				Y=2*t[i].a;
				if(Y*L<=X) t[i].p.B=0;
				else
				{
					t[i].p.A=X+t[i].d*Y;
					t[i].p.B=Y;
					t[i].p0=1;
					t[i].q.A=L;
				}
			}
//			cout << t[i].p.A << " " << t[i].p.B << " " << t[i].p0 << " "
//			     << t[i].q.A << " " << t[i].q.B << " " << t[i].q0 << endl;
			if(t[i].p.B==0)
			{
				continue;
			}
			t[i].ll=findl(t[i].p.A,t[i].p.B,t[i].p0,t[i].q.A,t[i].q.B,t[i].q0);
			t[i].rr=findr(t[i].p.A,t[i].p.B,t[i].p0,t[i].q.A,t[i].q.B,t[i].q0);
//			if(find(t[i].p.A,t[i].p.B,t[i].p0,t[i].q.A,t[i].q.B,t[i].q0)) cnt++;
//			cout << t[i].ll << " " << t[i].rr << endl;
			if(t[i].ll<=t[i].rr) cnt++;
		}
		cout << cnt << " ";
		cnt2=1;
		sort(t+1,t+n+1,cmp);
		int P=1,Q=m;
		for(int i = 1; i <= n; i++)
		{
//			
//			cout << t[i].ll << t[i].rr << endl;
			if(t[i].ll>t[i].rr||(t[i].p.B==0)) continue;
			if(t[i].ll>P) P=t[i].ll;
			if(t[i].rr<Q) Q=t[i].rr;
			if(P>Q)
			{
				cnt2++;
				P=1;Q=m;
			}
		}
		cout << m-cnt2 << endl;
	}
}
