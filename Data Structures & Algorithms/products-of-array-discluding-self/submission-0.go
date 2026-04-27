func productExceptSelf(nums []int) []int {
	n := len(nums)
	pref := make([]int, n)
	pref[0] = nums[0]
	suff := make([]int, n)
	suff[n - 1] = nums[n - 1]
	for i := 1; i < n; i++ {
		pref[i] = pref[i - 1] * nums[i]
	}
	for i := n - 2; i >= 0; i-- {
		suff[i] = suff[i + 1] * nums[i]
	}
	for i := 0; i < n; i++ {
		if i == 0 {
			nums[i] = suff[i + 1]
		} else if i == n - 1 {
			nums[i] = pref[i - 1]
		} else {
			nums[i] = pref[i - 1] * suff[i + 1]
		}
	}
	return nums
}
