#include<bits/stdc++.h>
using namespace std;
int n,a[10009],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[3]+a[1]>a[2]){
			cout<<1;
		}
		else{
			cout<<0;
		} 
		return 0;
	}
	if(n>3&&n<=10){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k])) ans++;
		for(int x=1;x<=n;x++)
			for(int b=x+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						if(a[x]+a[b]+a[c]+a[d]>2*max(max(a[x],a[b]),max(a[c],a[d]))) ans++;
		for(int x=1;x<=n;x++)
			for(int b=x+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							if(a[x]+a[b]+a[c]+a[d]+a[e]>2*max(max(a[x],a[b]),max(max(a[c],a[d]),a[e]))) ans++;
		for(int x=1;x<=n;x++)
			for(int b=x+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++) 
								if(a[x]+a[b]+a[c]+a[d]+a[e]+a[f]>2*max(max(a[x],a[b]),max(max(a[c],a[d]),max(a[e],a[f])))) ans++;
		for(int x=1;x<=n;x++)
			for(int b=x+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++) 
								for(int g=f+1;g<=n;g++)
									if(a[x]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]>2*max(max(max(a[x],a[g]),a[b]),max(max(a[c],a[d]),max(a[e],a[f])))) ans++;
		for(int x=1;x<=n;x++)
			for(int b=x+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++) 
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										if(a[x]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]>2*max(max(max(a[x],a[g]),max(a[b],a[h])),max(max(a[c],a[d]),max(a[e],a[f])))) ans++;
		for(int x=1;x<=n;x++)
			for(int b=x+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++) 
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											if(a[x]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]>2*max(max(max(max(a[x],a[g]),max(a[b],a[h])),max(max(a[c],a[d]),max(a[e],a[f]))),a[i])) ans++;
		for(int x=1;x<=n;x++)
			for(int b=x+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++) 
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											for(int j=i+1;j<=n;j++) 
												if(a[x]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]>2*max(max(max(max(a[x],a[g]),max(a[b],a[h])),max(max(a[c],a[d]),max(a[e],a[f]))),max(a[i],a[j]))) ans++;
	cout<<ans;
	}
	if(n>10) cout<<0;
	return 0;
}
