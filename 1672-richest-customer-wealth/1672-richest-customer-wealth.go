// var v []int

func maximumWealth(accounts [][]int) int {
    m := len(accounts)
    n := len(accounts[0])
    // fmt.Println(m, n)
    // v := make([]int, m)
    // fmt.Println(v)
    ans := 0
    for i := 0; i<m; i++ {
        sum := 0
        for j := 0; j < n; j++ {
            sum += accounts[i][j]
        }
        if sum > ans {
            ans = sum;
        }
    }
    return ans
}