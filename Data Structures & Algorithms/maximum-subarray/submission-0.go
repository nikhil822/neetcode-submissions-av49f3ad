func maxSubArray(nums []int) int {
    res := nums[0]
    currSum := 0
    for _, e := range nums {
        if currSum < 0 {
            currSum = 0
        }
        currSum += e
        if res < currSum {
            res = currSum
        }
    }
    return res
}
