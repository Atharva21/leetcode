var v [51]int
var acc *[][]int
var wg sync.WaitGroup
var n int
func test(idx int) {
    // fmt.Println((*acc)[idx][0])
    ans := 0
    for i:=0; i<n;i++ {
        ans += (*acc)[idx][i]
    }
    v[idx] = ans
}

func maximumWealth(accounts [][]int) int {
    acc = &accounts
    m := len(accounts)
    n = len(accounts[0])
    ans := 0
    for i := 0; i<m; i++ {
        wg.Add(1)
        go func(i int) {
            test(i)
            wg.Done()
        }(i)
    }
    wg.Wait()
    for i:=0; i<m;i++ {
        if v[i] > ans {
            ans = v[i]
        }
    }
    return ans
}