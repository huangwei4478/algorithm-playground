import edu.princeton.cs.algs4.StdOut;

public class Main {
    public static void main(String[] args) {
        Integer[] nums = { -2, 0, 3, -5, 2, -1 };
        SegmentTree<Integer> segTree = new SegmentTree<>(nums, (a, b) -> a + b);

        // 从 [0 ... 2] 这个区间里，元素之和
        StdOut.print(segTree.query(0, 5));
    }
}
