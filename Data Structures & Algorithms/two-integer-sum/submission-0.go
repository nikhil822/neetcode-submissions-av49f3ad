func twoSum(nums []int, target int) []int {
    freq := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		dif := target - nums[i]
		val, ok := freq[dif]
		if !ok {
			freq[nums[i]] = i
		} else {
				return []int{val, i}
			
		}
	}
	return []int{-1, -1}
}
