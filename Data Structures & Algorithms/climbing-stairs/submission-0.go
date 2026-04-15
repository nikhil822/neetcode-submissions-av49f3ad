func solve(i int, dp []int, n int) int {
	if i == n {
		return 1
	}
	if i > n {
		return 0
	}
	if dp[i] != -1 {
		return dp[i]
	}
	dp[i] = solve(i + 1, dp, n) + solve(i + 2, dp, n)
	return dp[i]
}

func climbStairs(n int) int {
    dp := make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = -1
	}
	return solve(0, dp, n)
	
}
