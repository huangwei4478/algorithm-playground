package Liuyubobobo;

import java.lang.reflect.Array;

public class MaxHeap<E extends Comparable<E>> {
    private Comparable[] data;

    public MaxHeap(int capacity) {
        data = (Comparable[]) new Object[capacity];
    }

    public int size() {
        return data.length;
    }

    public boolean isEmpty() {
        return data.length == 0;
    }

    private int parent(int index) {
        if (index == 0)
            throw new IllegalArgumentException("index-0 has no parent");
        return (index - 1) / 2;
    }

    private int leftChild(int index) {
        return index * 2 + 1;
    }

    private int rightChild(int index) {
        return index * 2 + 2;
    }

    public void add(E e) {
        data.
    }
}
