class Solution {
    int[] parent;
    int[] height;

    void merge(int u, int v) {
        int p1 = findParent(u);
        int p2 = findParent(v);

        if (p1 == p2) {
            return;
        }
        parent[p1] = p2;
        // if(height[u] > height[v]){
        //     parent[v]= u;
        // }
        // else if(height[u]< height[v]){
        //     parent[u]= v;
        // }
        // else{
        //     parent[u]= v;
        //     height[v]++;
        // }

    }

    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        }
        parent[u] = findParent(parent[u]);
        return parent[u];
        // return  findParent(parent[u]);
    }

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        parent = new int[n];
        height = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            height[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i!=j) {
                    merge(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) System.out.println(parent[i] + "  ");

        // Arrays.sort(parent);
        int res = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i) {
            res++;
        }

        return res;
    }
}
