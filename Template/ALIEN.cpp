
/* 
 * Use when 
 * You are given an array of integers (possibly negative) of length N
 * and a number K. 
 * Select at most K disjoint subarrays of the initial sequence such 
 * that the 
 * sum of the elements included in the subarrays is maximized.
 * */

/* Pseudo Code
 * minbound = 0, maxbound = 1e18
while maxbound - minbound > 1e-6:
    λ = (maxbound - minbound) / 2
    #compute dp and aux for λ
    if cnt[n] <= k:
        minbound = λ
    else:
        maxbound = λ
#compute dp and cnt for the final λ
return dp[n] + cnt[n] * λ #note that if there are less than k positive values, then cnt[n] < k
 * */


/*	REQUIREMENT (CONVEX or CONCAVE property
 * I have k subarrays and add another one, it will help 
 * me more than 
 * if I had k+1 subarrays and added one more.
 * */
 
 /* valid for integer as well as fractions */
 
 /*
  * if exact K then dp[n] - lambda*K
  * if atmost K then dp[n] - lambda*cnt where cnt = # lambda used
  * CAREFUL about sometime check with atmost K = exact K
  *         integral cases
  * */
  
  /* length need not be fixed it can vary */
 

pll dp[N];
ll n, k, l;
 
ll cnt(ll mid, vec a)
{
	for (ll i = 0; i <= n; ++i) {
		dp[i] = make_pair(INF, INF);
	}
	dp[0] = make_pair(0, 0);
	for (ll i = 0; i < n; ++i) {
		// use a[i]
		if (dp[i + 1] > make_pair(dp[i].first + a[i], dp[i].second)) {
			dp[i + 1] = make_pair(dp[i].first + a[i], dp[i].second);
		}
		// neglect all values of a[i] upto length l
		if (dp[min(n, i + l)] > make_pair(dp[i].first + mid, dp[i].second + 1)) {
			dp[min(n, i + l)] = make_pair(dp[i].first + mid, dp[i].second + 1);
		}
	}
	return dp[n].second;
}
 
ll findans(vector<ll> v)
{
	ll l = 0, r = n;
	ll rem = 0;
	while(l <= r)
	{
		ll mid = (l+r) >> 1;
		if(k < cnt(mid, v))
			l = mid + 1, rem = mid;
		else 
			r = mid - 1;
	}
	ll x = cnt(rem, v);
	if(x <= k) return 0;
	x = cnt(rem+1, v);
	return dp[n].f - (rem + 1LL)*k; // in integral cases finding lowest 
									// lambda and then using exact K
}
