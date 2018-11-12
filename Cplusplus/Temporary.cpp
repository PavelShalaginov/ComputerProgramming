Problem: Maximum product of two non-intersecting paths in a tree.
Given an undirected connected tree with N nodes (and N-1 edges), we need to find two paths in this tree such that they are non-intersecting and the product of their length is maximum.
Link: https://www.geeksforgeeks.org/maximum-product-of-two-non-intersecting-paths-in-a-tree/

Vấn đề: Tìm tích lớn nhất của 2 đường đi không cắt nhau trên một cây cho trước.
Đề bài: Cho một cây có n đỉnh, n-1 cạnh vô hướng, tìm tích lớn nhất của 2 đường đi không cắt nhau trên một cây đó.
Dữ liệu đầu vào gồm: dòng thứ nhất cho số n, n-1 dòng còn lại cặp số u v tương ứng cạnh nối từ u tới v.
Subtask 1: n<=1000 0,01% số test.
Subtask 2: n<=100000, 99,99% số test.
Ps: Bài hay nhưng mỗi tội không có test.

Giải thuật 1: Giải thuật từ trang web.
Ý tưởng: Lần lượt bỏ các cạnh của cây, ta sẽ được 2 cây con mới, tìm trên 2 cây con mới đường đi dài nhất của mỗi cây, kết quả sẽ là tích lớn nhất trong các phương án loại bỏ cạnh khỏi cây.

Giải quyết các bài toán con:
Bài toán 1: Tìm độ dài dài nhất trong cây:
Ý tưởng: tại mỗi đỉnh, đưa nó lên làm gốc của cây không chứa nhánh trên của đường đi DFS, tìm 2 lá xa thứ nhất và xa thứ nhì so với đỉnh đó:

int dfs(vector<int> g[], int& curMax, int u, int v) { 
    // To find lengths of first and second maximum 
    // in subtrees. currMax is to store overall 
    // maximum. 
    int max1 = 0, max2 = 0, total = 0; 
  
    //  loop through all neighbors of u 
    for (int i = 0; i < g[u].size(); i++) 
    { 
        //  if neighbor is v, then skip it 
        if (g[u][i] == v) 
            continue; 
  
        //  call recursively with current neighbor as root 
        total = max(total, dfs(g, curMax, g[u][i], u)); 
  
        //  get max from one side and update 
        if (curMax > max1) 
        { 
            max2 = max1; 
            max1 = curMax; 
        } 
        else
            max2 = max(max2, curMax); 
    } 
  
    // store total length by adding max 
    // and second max 
    total = max(total, max1 + max2); 
  
    // update current max by adding 1, i.e. 
    // current node is included 
    curMax = max1 + 1; 
    return total; 
}

Bài toán 2: Bỏ cạnh của cây. Tìm kết quả của bài toán.
Ý tưởng: Trong khi duyệt dfs ở trên, khi tới đỉnh mới, ta kiểm tra xem đỉnh mới là là cha của nó không, ngầm định là cắt cạnh đó.

// method returns maximum product of length of 
// two non-intersecting paths 
int maxProductOfTwoPaths(vector<int> g[], int N) 
{ 
    int res = INT_MIN; 
    int path1, path2; 
  
    // one by one removing all edges and calling 
    // dfs on both subtrees 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < g[i].size(); j++) 
        { 
            // calling dfs on subtree rooted at 
            // g[i][j], excluding edge from g[i][j] 
            // to i. 
            int curMax = 0; 
            path1 = dfs(g, curMax, g[i][j], i); 
  
            //  calling dfs on subtree rooted at 
            // i, edge from i to g[i][j] 
            curMax = 0; 
            path2 = dfs(g, curMax, i, g[i][j]); 
  
            res = max(res, path1 * path2); 
        } 
    } 
    return res; 
}

Độ phức tạp của hàm dfs là O(n), của hàm maxProductOfTwoPaths là O(n);
Vậy độ phức tạp của bài toán là O(n^2)

Giải thuật 2: Tự cải tiến, có thể sai sót nhờ mọi người đóng góp ý kiến.
