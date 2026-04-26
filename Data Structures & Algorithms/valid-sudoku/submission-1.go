func isValidSudoku(board [][]byte) bool {
    for i := 0; i < 9; i+=3 {
        for j := 0; j < 9; j+=3 {
            freq := make(map[byte]int)
            for k := i; k < i + 3; k++ {
                for l := j; l < j + 3; l++ {
                    if board[k][l] != '.' {

                        _, ok := freq[board[k][l]]
                        if !ok {
                            freq[board[k][l]]++
                        } else {
                            return false
                        }
                    }
                }
            }
        }
    }
    for i := 0; i < 9; i++ {
        freq := make(map[byte]int)
        for j := 0; j < 9; j++ {
            if board[i][j] != '.' {

                        _, ok := freq[board[i][j]]
                        if !ok {
                            freq[board[i][j]]++
                        } else {
                            return false
                        }
                    }
        }
    }
    for i := 0; i < 9; i++ {
        freq := make(map[byte]int)
        for j := 0; j < 9; j++ {
            if board[i][j] != '.' {

                        _, ok := freq[board[i][j]]
                        if !ok {
                            freq[board[i][j]]++
                        } else {
                            return false
                        }
                    }
        }
    }
    for i := 0; i < 9; i++ {
        freq := make(map[byte]int)
        for j := 0; j < 9; j++ {
            if board[j][i] != '.' {

                        _, ok := freq[board[j][i]]
                        if !ok {
                            freq[board[j][i]]++
                        } else {
                            return false
                        }
                    }
        }
    }
    return true
}
