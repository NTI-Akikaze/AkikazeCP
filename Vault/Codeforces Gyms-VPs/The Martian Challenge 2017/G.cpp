/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define EPS 1e-9
#define GOLD ((1+sqrt(5))/2)
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
i64 n, nextinlist = 0, diff = 0;
vector<i64> unil;
vector<i64> permu;
vector<bool> picked;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n; unil.resize(n); permu.resize(n);
	picked.resize(n, false);
	for (i64 i=0; i<n; i++) cin >> unil[i];
	for (i64 i=0; i<n; i++) {
		cin >> permu[i]; permu[i]--;
	}
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	while (nextinlist < n) {
		//tracker1(nextinlist);
		i64 tmp = unil[permu[nextinlist]] - unil[permu[nextinlist+1]];
		if (tmp > 0) {
			//cout << "picked " << nextinlist << " and " << nextinlist+1 << endl;
			picked[nextinlist] = true; picked[nextinlist+1] = true;
			diff += tmp; nextinlist += 2; continue;
		}
		//cout << "tmp = " << tmp << endl;
		i64 mx = -1;
		for (i64 i=nextinlist+1; i<n; i++) {
			if (picked[i]) continue;
			if (mx == -1) mx = i;
			else if (unil[permu[i]] > unil[permu[mx]]) mx = i;
		}
		if (unil[permu[mx]] - unil[permu[nextinlist]] > tmp) {
			tmp = unil[permu[mx]] - unil[permu[nextinlist]];
			//cout << "picked " << mx << " and " << nextinlist << endl;
			picked[mx] = true; picked[nextinlist] = true;
		}
		else {
			//cout << "picked " << nextinlist << " and " << nextinlist+1 << endl;
			picked[nextinlist] = true; picked[nextinlist+1] = true;
		}
		//cout << "tmp = " << tmp << endl;
		diff += tmp;
		while (nextinlist < n && picked[nextinlist]) nextinlist++;
	}
	cout << diff;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
