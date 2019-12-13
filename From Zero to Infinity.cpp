#include <bits/stdc++.h>
using namespace std;
struct R{double tot=0,in=0;};
bool vowel(char c){
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
bool ForAlice(string s){
	for (int i=0; i<s.size(); i++){
		int vw=0,cn=0;
		vowel(s[i]) ? vw++:cn++;
		for (int j=i+1; j<s.size(); j++){
			vowel(s[j]) ? vw++:cn++;
			if (cn>vw) return false;
		}
	}
	return true;
}
int main(){
	int t,n;
	cin>>t;
	while (cin>>n){
		vector<string> alice,bob;
		string s;
		while (n--){
			cin>>s;
			if (ForAlice(s)) alice.push_back(s);
			else bob.push_back(s);
		}

		R cntA[200], cntB[200];
		for (auto it:alice){
			//cout<<it<<" ";puts("");
			int fl[200]={0};
			for (auto jt:it){
				cntA[jt].tot++;
				if (!fl[jt]) cntA[jt].in++;
				fl[jt]=1;
			}
		}
		for (auto it:bob){
			//cout<<it<<" ";puts("");
			int fl[200]={0};
			for (auto jt:it){
				cntB[jt].tot++;
				if (!fl[jt]) cntB[jt].in++;
				fl[jt]=1;
			}
		}

		double scoreA=1,scoreB=1,sa=alice.size(),sb=bob.size(),f=1;
		//printf("%f %f\n",sa,sb);
		for (int i='a'; i<='z' && f; i++){
			if (cntA[i].in){
				scoreA*=cntA[i].in/
					pow(cntA[i].tot,sa);
				//printf("Alice=%c=%.0f/%.0f\n",i,cntA[i].in,cntA[i].tot);
			}

			if (cntB[i].in){
				scoreB*=cntB[i].in/
					pow(cntB[i].tot,sb);
				//printf("Bob=%c=%.0f/%.0f\n",i,cntB[i].in,cntB[i].tot);
			}
			//if (scoreA>1e7 || scoreB>1e7) f=0;
		}
		double ans=scoreA/scoreB;
		if (ans>1e7) puts("Infinity");
		else printf("%.7f\n",ans);
	}
}
