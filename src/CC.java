public class CC {
    // Connected Component
    private boolean[] marked;           // has vertex v being traversed by dfs
    private int[] id;                   // the component id ( 0 - count() - 1)
    private int count;                  // the count of connected component

    public CC(Graph G) {
        marked = new boolean[G.V()];
        id = new int[G.V()];
        count = 0;

        for (int s = 0; s < G.V(); s++) {
            if (!marked[s]) {
                dfs(G, s);
                count++;
            }
        }
    }

    public boolean connected(int v, int w) {
        return id[v] == id[w];
    }

    private void dfs(Graph G, int v) {
        marked[v] = true;
        id[v] = count;
        for (int w: G.adj(v)) {
            if (!marked[w]) {
                dfs(G, w);
            }
        }
    }

    public int count() {
        return count;
    }

    int id(int v) {
        return id[v];
    }
}
