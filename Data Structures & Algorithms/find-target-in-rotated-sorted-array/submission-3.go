func search(nums []int, target int) int {
	i, j := 0, len(nums) - 1
	for i <= j {
		mid := i + (j - i) / 2
		if nums[mid] == target {
			return mid
		}
		if nums[i] <= nums[mid] { // left half is sorted
			if nums[i] <= target && target < nums[mid] {
				j = mid - 1
			} else {
				i = mid + 1
			}
		} else {
			if nums[mid] < target && target <= nums[j] {
				i = mid + 1
			} else {
				j = mid - 1
			}
		}
	}
	return -1
}
