#include<bits/stdc++.h>

using namespace std;

typedef long double dbl;

const dbl eps = 1e-9;

inline bool gt(const dbl & x, const dbl & y){
	return x > y + eps;
}

inline bool lt(const dbl & x, const dbl & y){
	return y > x + eps;
}

inline dbl safe_sqrt(const dbl & D){
	return D < 0 ? 0 : sqrt(D);
}

struct pt{
	dbl x, y;
	pt(){}
	pt(dbl a, dbl b):x(a), y(b){}
};


const int N = 1e5 + 5;
const int STEPS = 150;

int n;
pt p[N];

inline bool can(dbl R){
	dbl l = -1e16 - 1, r = 1e16 + 1;
	for(int i = 0; i < n; i++){
		dbl b = -2 * p[i].x;
		dbl c = p[i].x * p[i].x + p[i].y * p[i].y - 2 * p[i].y * R;
		dbl D = b * b - 4 * c;
		if(lt(D, 0))
			return false;
		D = safe_sqrt(D);
		dbl x1 = p[i].x - D/2, x2 = p[i].x + D/2;
		l = max(l, x1);
		r = min(r, x2);
	}
	return !gt(l, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	bool has_positive = false, has_negative = false;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		p[i] = pt(x, y);
		if(y > 0)has_positive = true;
		else has_negative = true;
	}
	if(has_positive && has_negative){
		cout << -1 << endl;
		return 0;
	}
	if(has_negative){
		for(int i = 0; i < n; i++)
			p[i].y = -p[i].y;
	}
	dbl L = 0, R = 1e16;
	std::function<dbl(dbl, dbl)> get_mid;
	if(can(1)){
		R = 1;
		get_mid = [](dbl l, dbl r){return (l + r)/2.0;};
	}
	else{
		L = 1;
		get_mid = [](dbl l, dbl r){return sqrt(l * r);};
	}
	for(int step = 0; step < STEPS; step++){
		dbl mid = get_mid(L, R);
		if(can(mid))
			R = mid;
		else
			L = mid;
	}
	cout.precision(16);
	cout << fixed << get_mid(L, R) << endl;
}


/// Ternary Search on Doubles
// [L, R] contains some value which is answer
double L = Low;
double R = High;

// Here we have to find minimum

for(int i = 0; i< 100; i++){
	double a = (2*l +r) / 3;
	double b = (l + 2*r) / 3;
	if(check(a) < check(b)) r = b;
	else l = a;
}

/// Ternary Search on Intergers is not possible if F[mid] == F[mid+1];
while(l < r-1){
	int mid = (l + r) / 2;
	if(F(mid) > f(mid+1)) r = mid;
	else l = mid;
} 
// l + 1 is answer;


/// Second approach
while(r-l >= 3){
	int a = (2*l + r) / 3;
	int b = (l + 2*r) / 3;
	if(F(a) > F(b)) r = b;
	else l = a;
}
// l+1 and l+2 may be answers check for each one of them seperately
