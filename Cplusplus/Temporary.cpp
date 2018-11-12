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
Ý tưởng: tại mỗi đỉnh, đưa nó lên làm gốc của cây, tìm 2 lá xa thứ nhất và xa thứ nhì so với đỉnh đó:

//Trả về độ dài lớn nhất cây con gốc u sau khi bỏ cạnh (u,v)
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

