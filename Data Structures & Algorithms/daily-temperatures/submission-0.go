type pair struct {
	Key int
	Value int
}

func dailyTemperatures(temperatures []int) []int {
	var stack []pair
	l := len(temperatures)
	res := make([]int, l)
	res[l - 1] = 0
	stack = append(stack, pair{temperatures[l - 1], l - 1})
	for i := l - 2; i >= 0; i-- {
		for len(stack) > 0 && temperatures[i] >= stack[len(stack) - 1].Key {
			stack = stack[:len(stack) - 1]
		}
		if len(stack) == 0 {
			res[i] = 0
		} else {
			res[i] = stack[len(stack) - 1].Value - i;
		}
		stack = append(stack, pair{temperatures[i], i})
	}
	return res
}
