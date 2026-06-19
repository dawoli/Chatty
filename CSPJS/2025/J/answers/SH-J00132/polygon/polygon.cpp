#include<bits/stdc++.h>
using namespace std;
int n;
int q[15];
int cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	if(n>=3){
		for(int a=1;a<=n-2;a++){
			for(int b=a+1;b<=n-1;b++){
				for(int c=b+1;c<=n;c++){
					if(q[a]+q[b]+q[c]>2*max(q[a],max(q[b],q[c]))) cnt++;
				}
			}
		}
	}
	if(n>=4){
		for(int a=1;a<=n-3;a++){
			for(int b=a+1;b<=n-2;b++){
				for(int c=b+1;c<=n-1;c++){
					for(int d=c+1;d<=n;d++)
						if(q[a]+q[b]+q[c]+q[d]>2*max(q[a],max(q[b],max(q[c],q[d])))) cnt++;
				}
			}
		}
	}
	if(n>=5){
		for(int a=1;a<=n-4;a++){
			for(int b=a+1;b<=n-3;b++){
				for(int c=b+1;c<=n-2;c++){
					for(int d=c+1;d<=n-1;d++)
						for(int e=d+1;e<=n;e++)
							if(q[a]+q[b]+q[c]+q[d]+q[e]>2*max(q[a],max(q[b],max(q[c],max(q[d],q[e]))))) cnt++;
				}
			}
		}
	}
	if(n>=6){
		for(int a=1;a<=n-5;a++){
			for(int b=a+1;b<=n-4;b++){
				for(int c=b+1;c<=n-3;c++){
					for(int d=c+1;d<=n-2;d++)
						for(int e=d+1;e<=n-1;e++)
							for(int f=e+1;f<=n;f++)
								if(q[a]+q[b]+q[c]+q[d]+q[e]+q[f]>2*max(q[a],max(q[b],max(q[c],max(q[d],max(q[e],q[f])))))) cnt++;
				}
			}
		}
	}
	if(n>=7){
		for(int a=1;a<=n-6;a++){
			for(int b=a+1;b<=n-5;b++){
				for(int c=b+1;c<=n-4;c++){
					for(int d=c+1;d<=n-3;d++)
						for(int e=d+1;e<=n-2;e++)
							for(int f=e+1;f<=n-1;f++)
								for(int g=f+1;g<=n;g++)
									if(q[a]+q[b]+q[c]+q[d]+q[e]+q[f]+q[g]>2*max(q[a],max(q[b],max(q[c],max(q[d],max(q[e],max(q[f],q[g]))))))) cnt++;
				}
			}
		}
	}
	if(n>=8){
		for(int a=1;a<=n-7;a++){
			for(int b=a+1;b<=n-6;b++){
				for(int c=b+1;c<=n-5;c++){
					for(int d=c+1;d<=n-4;d++)
						for(int e=d+1;e<=n-3;e++)
							for(int f=e+1;f<=n-2;f++)
								for(int g=f+1;g<=n-1;g++)
									for(int h=g+1;h<=n;h++) 
									if(q[a]+q[b]+q[c]+q[d]+q[e]+q[f]+q[g]+q[h]>2*max(q[a],max(q[b],max(q[c],max(q[d],max(q[e],max(q[f],max(q[g],q[h])))))))) cnt++;
				}
			}
		}
	}
	if(n>=9){
		for(int a=1;a<=n-8;a++){
			for(int b=a+1;b<=n-7;b++){
				for(int c=b+1;c<=n-6;c++){
					for(int d=c+1;d<=n-5;d++)
						for(int e=d+1;e<=n-4;e++)
							for(int f=e+1;f<=n-3;f++)
								for(int g=f+1;g<=n-2;g++)
									for(int h=g+1;h<=n-1;h++)
										for(int i=h+1;i<=n;i++)
											if(q[a]+q[b]+q[c]+q[d]+q[e]+q[f]+q[g]+q[h]+q[i]>2*max(q[a],max(q[b],max(q[c],max(q[d],max(q[e],max(q[f],max(q[g],max(q[h],q[i]))))))))) cnt++;
				}
			}
		}
	}
	if(n>=10){
		int z=0;
		int zx=0;
		for(int i=1;i<=10;i++) z+=q[i];
		for(int i=1;i<=10;i++) zx=max(zx,q[i]);
		if(ax*2<z) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
