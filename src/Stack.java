import java.util.Iterator;

public class Stack<Item> implements Iterable<Item> {

    private class Node {
        Item item;
        Node next;
    }

    private Node first;     // most-recent element
    private int N;          // element count

    public boolean isEmpty() { return first == null; }
    public int size()        { return N; }
    public void push(Item item)       {
        Node oldFirst = first;
        first = new Node();
        first.item = item;
        first.next = oldFirst;
        N++;
    }

    public Item pop() {
        Item item = first.item;
        first = first.next;
        N--;
        return item;
    }

    public Iterator<Item> iterator() {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<Item> {

        private Node current = first;

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

}
