func lengthOfLongestSubstring(s string) int {
	l := len(s)
	ans := 0
	freq := make(map[byte]int)
	i, j := 0, 0
	for j < l {
		freq[s[j]]++
		for j - i + 1 > len(freq) {
			freq[s[i]]--
			if freq[s[i]] == 0 {
				delete(freq, s[i])
			}
			i++
		}
		if ans < (j - i + 1) {
			ans = j - i + 1
		}
		j++
 	}
	return ans
}
