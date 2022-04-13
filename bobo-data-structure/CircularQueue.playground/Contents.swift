import UIKit

class CircularQueue<T> {
    private var data: [T]
    
    private var front: Int
    
    private var tail: Int
        
    private var size: Int
    
    init(capacity: Int) {
        data = [T]()
        data.reserveCapacity(capacity + 1)
        self.front = 0
        self.tail = 0
        self.size = 0
    }
    
    convenience init() {
        self.init(capacity: 10)
    }
    
    func getSize() -> Int {
        return size
    }
    
    func getCapacity() -> Int {
        return data.count - 1
    }
    
    func isEmpty() -> Bool {
        return front == tail
    }
    
    func isFull() -> Bool {
        return nextIndexOf(index: tail) == front
    }
    
    func enqueue(e: T) {
        if (isFull()) {
            resize(getCapacity() * 2)
        }
        
        data[tail] = e
        tail = nextIndexOf(index: tail)
        size += 1
    }
    
    func dequeue() -> T {
        assert(!isEmpty()) as! T
        
        let ret = data[front];
        front = nextIndexOf(index: front);
        size -= 1
        
        if (size <= getCapacity() / 4 && getCapacity() / 2 != 0) {
            resize(getCapacity() / 2)
        }
        
        return ret
    }
    
    func getFront() -> T {
        assert(!isEmpty()) as! T
        let ret = data[front];
        return ret
    }
    
    // size is unchanged
    private func resize(_ newCapacity: Int) {
        var newData: [T] = [T]()
        newData.reserveCapacity(newCapacity + 1)
        
        for i in (0 ..< size) {
            newData[i] = data[(i + front) % data.count]
        }
        
        data = newData
        front = 0
        tail = size
    }
    
    private func nextIndexOf(index: Int) -> Int {
        return (index + 1) % data.count
    }
}
