import java.util.Arrays;

// from liuyubobobo
public class SegmentTree<E> {

    private E[] tree;
    private E[] data;
    private Merger<E> merger;

    public SegmentTree(E[] arr, Merger<E> merger) {
        this.merger = merger;

        data = (E[])new Object[arr.length];
        for (int i = 0; i < arr.length; i++) {
            data[i] = arr[i];
        }

        tree = (E[])new Object[4 * arr.length];
        buildSegmentTree(0, 0, data.length - 1);
    }

    // 在 treeIndex 的位置，创建表示区间 [l ... r] 的线段树
    private void buildSegmentTree(int treeIndex, int l, int r) {
        if (l == r) {
            tree[treeIndex] = data[l];
            return;
        }

        int leftTreeIndex = leftChild(treeIndex);
        int rightTreeIndex = rightChild(treeIndex);

        int mid = l + (r - l) / 2;

        buildSegmentTree(leftTreeIndex, l, mid);
        buildSegmentTree(rightTreeIndex, mid + 1, r);

        // 这一个节点的值是什么？这个是一个业务需求
        tree[treeIndex] = merger.merge(tree[leftTreeIndex], tree[rightTreeIndex]);
    }

    public int getSize() {
        return data.length;
    }

    public E get(int index) {
        if (index < 0 || index >= data.length) {
            throw new IllegalArgumentException("Index is illegal.");
        }
        return data[index];
    }

    private int leftChild(int index) {
        return 2 * index + 1;
    }

    private int rightChild(int index) {
        return 2 * index + 2;
    }

    // 返回区间[queryL, queryR] 的值
    public E query(int queryL, int queryR) {
        if (queryL < 0 || queryL >= data.length ||
                queryR < 0 || queryR >= data.length || queryL > queryR) {
            throw new IllegalArgumentException("Index is illegal");
        }

        return query(0, 0, data.length - 1, queryL, queryR);
    }

    // 以 treeID为根的线段树中 [l ... r] 的范围内，搜索区间 [queryL ... queryR] 的值
    // （treeIndex, l, r） 三元组，共同确立一个线段树里的某个节点
    private E query(int treeIndex, int l, int r, int queryL, int queryR) {
        if (l == queryL && r == queryR) {
            return tree[treeIndex];
        }

        int middle = l + (r - l) / 2;
        int leftTreeIndex = leftChild(treeIndex);
        int rightTreeIndex = rightChild(treeIndex);

        if (queryL >= middle + 1) {
            return query(rightTreeIndex, middle + 1, r, queryL, queryR);
        } else if (queryR <= middle) {
            return query(leftTreeIndex, l, middle, queryL, queryR);
        } else {
            E leftResult = query(leftTreeIndex, l, middle, queryL, middle);
            E rightResult = query(rightTreeIndex, middle + 1, r, middle + 1, queryR);
            return merger.merge(leftResult, rightResult);
        }
    }

    // 将 index 位置的值，更新为 e
    public void set(int index, E e) {
        if (index < 0 || index >= data.length) {
            throw new IllegalArgumentException("Index is illegal");
        }

        data[index] = e;
        set(0, 0, data.length - 1, index, e);
    }

    // 在以 treeIndex 为根的线段树中，更新 index 的值为 e
    private void set(int treeIndex, int l, int r, int index, E e) {

        if (l == r) {
            tree[treeIndex] = e;
            return;
        }

        int mid = l + (r - l) / 2;
        int leftTreeIndex = leftChild(treeIndex);
        int rightTreeIndex = rightChild(treeIndex);

        if (index >= mid + 1) {
            set(rightTreeIndex, mid + 1, r, index, e);
        } else {
            set(leftTreeIndex, l, mid, index, e);
        }

        // update parent node
        tree[treeIndex] = merger.merge(tree[leftTreeIndex], tree[rightTreeIndex]);
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append('[');
        for (int i = 0; i < tree.length; i++) {
            if (tree[i] != null) {
                res.append(tree[i]);
            } else {
                res.append("null");
            }
        }

        return res.toString();
    }
}
