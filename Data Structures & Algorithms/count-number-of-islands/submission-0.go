func dfs(i int, j int, vis [][]int, grid [][]byte, m int, n int) {
	if i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == '0' || vis[i][j] == 1 {
		return
	}

	vis[i][j] = 1

	dfs(i+1, j, vis, grid, m, n)
	dfs(i-1, j, vis, grid, m, n)
	dfs(i, j+1, vis, grid, m, n)
	dfs(i, j-1, vis, grid, m, n)
}

func numIslands(grid [][]byte) int {
	m, n := len(grid), len(grid[0])

	vis := make([][]int, m)
	for i := 0; i < m; i++ {
		vis[i] = make([]int, n)
		for j := 0; j < n; j++ {
			vis[i][j] = -1
		}
	}

	ans := 0

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == '1' && vis[i][j] == -1 {
				dfs(i, j, vis, grid, m, n)
				ans++
			}
		}
	}

	return ans
}