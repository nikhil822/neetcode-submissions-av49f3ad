func swap(nums []int, a int, b int) {
    nums[a], nums[b] = nums[b], nums[a]
}

func partition(low int, high int, nums []int) int {
    pivot := nums[high]
    i := low

    for j := low; j < high; j++ {
        if nums[j] <= pivot {
            swap(nums, i, j)
            i++
        }
    }
    swap(nums, i, high)
    return i
}

func quickSelect(low int, high int, nums []int, k int) int {
    if low <= high {
        pivot := partition(low, high, nums)

        if pivot == k {
            return nums[pivot]
        } else if pivot > k {
            return quickSelect(low, pivot-1, nums, k)
        } else {
            return quickSelect(pivot+1, high, nums, k)
        }
    }
    return -1
}

func findKthLargest(nums []int, k int) int {
    n := len(nums)
    k = n - k // convert to kth smallest
    return quickSelect(0, n-1, nums, k)
}