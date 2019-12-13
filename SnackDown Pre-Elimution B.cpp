#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int t,n,m,x,y;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d%d",&n,&m,&x,&y);
		int ans=0,i,j;
		int dl=min(y-1,n-x);
		int dr=min(n-x,m-y);
		int ul=min(y-1,x-1);
		int ur=min(m-y,x-1);
		for (i=1; i<=n; i++){
			for (j=1; j<=m; j++){
				if (i==x && y==j) continue;
				int dll=min(j-1,n-i);
				int drr=min(n-i,m-j);
				int ull=min(j-1,i-1);
				int urr=min(m-j,i-1);
				int zz=(n-1)*(m-1);
				zz-=(dll+drr+ull+urr);
				
				if (abs(i-x)==abs(j-y)){
							if (i<x && j<y) zz+=dr;
					else if (i<x && j>y) zz+=dl;
					else if (i>x && j>y) zz+=ul;
					else if (i>x && j<y) zz+=ur;
				}
				else if (i==x)
					j<y ? zz+=m-y:zz+=y-1;
				else if (j==y)
					i<x ? zz+=n-x:zz+=x-1;
				else zz-=1;
				ans+=zz;
			}
		}
		printf("%d\n",ans);
	} return 0; 
}
