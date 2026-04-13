func maxArea(heights []int) int {
	left, right := 0, len(heights) - 1
	ans := 0
	for left < right {
		wid := right - left
		var minHeight int
		if heights[left] < heights[right] {
			minHeight = heights[left]
		} else {
			minHeight = heights[right]
		}
		if ans < wid * minHeight {
			ans = wid * minHeight
		}
		if heights[left] < heights[right] {
			left++
		} else {
			right--
		}
		
	}
	return ans
}
