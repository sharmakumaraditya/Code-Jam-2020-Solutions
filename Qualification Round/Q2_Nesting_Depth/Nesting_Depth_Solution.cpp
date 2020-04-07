#include<bits/stdc++.h>
using namespace std;

string pa(char c,int t){
	string ans="";
	for(int i=0;i<t;++i)	ans+=c;
	return ans;
}
int main(){
	#ifdef xtest
	freopen("t.in","r",stdin);
	#endif // xtest
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    string s;
    for(int kase=1;kase<=T;++kase){
		cin>>s;
		string ans="";
		int d=0;
		for(auto x:s){
			int c = x-'0';
			if(c<d)	ans+=pa(')',d-c);
			else if(c>d)	ans+=pa('(',c-d);
			ans+=x;
			d=c;
		}
		if(d!=0)	ans+=pa(')',d);
		cout<<"Case #"<<kase<<": "<<ans<<endl;
    }
    return 0;
}