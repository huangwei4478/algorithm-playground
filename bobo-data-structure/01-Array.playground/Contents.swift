import UIKit

final class MyArray<T> {
    private var data: [T]
    
    private var size: Int
    
    private var capacity: Int
    
    init(capacity: Int) {
        self.capacity = capacity
        self.size = 0
        self.data = [T]()
        self.data.reserveCapacity(capacity)
    }
    
    convenience init() {
        self.init(capacity: 10)
    }
    
    func getSize() -> Int {
        return size
    }
    
    func getCapacity() -> Int {
        return capacity
    }
    
    func isEmpty() -> Bool {
        return size == 0
    }
    
    func isFull() -> Bool {
        return size == capacity
    }
    
    func addLast(e: T) {
        add(at: size, e: e)
    }
    
    func addFirst(e: T) {
        add(at: 0, e: e)
    }
    
    func add(at index: Int, e: T) {
        assert(index >= 0 && index <= size, "index must be in range [0, size]")
        if (size == capacity) {
            resize(newCapacity: capacity * 2)
        }
        
        var i = size - 1
        while (i >= index) {
            data[i + 1] = data[i]
            i -= 1
        }
        
        data[index] = e
        size += 1
    }
    
    func remove(at index: Int) -> T {
        assert(index >= 0 && index < size, "index must be in range [0, size)") as! T
        let ret = data[index]
        for i in (index + 1 ..< size) {
            data[i - 1] = data[i]
        }
        
        size -= 1
        
        if (size <= capacity / 4 && capacity / 2 != 0) {
            resize(newCapacity: capacity / 2)
        }
        
        return ret
    }
    
    func removeFirst() -> T {
        return remove(at: 0)
    }
    
    func removeLast() -> T {
        return remove(at: size - 1)
    }
    
    func getElement(at index: Int) -> T {
        assert(index >= 0 && index < size) as! T
        return data[index]
    }
    
    func setElement(at index: Int, element: T) {
        assert(index >= 0 && index < size) as! T
        data[index] = element
    }
        
    private func resize(newCapacity: Int) {
        var newData = [T]()
        newData.reserveCapacity(newCapacity)
        for i in (0 ..< data.count) {
            newData[i] = data[i]
        }
        self.data = newData
        self.capacity = newCapacity
    }
    
    
}

extension MyArray where T: Equatable {
    func contains(element: T) -> Bool {
        for e in data {
            if e == element {
                return true
            }
        }
        
        return false
    }
    
    func find(element: T) -> Int {
        for (i, e) in data.enumerated() {
            if e == element {
                return i
            }
        }
        return -1
    }
}

extension MyArray: CustomStringConvertible where T: CustomStringConvertible {
    var description: String {
        return "[\(data.map{$0.description})]"
    }
}

let array = MyArray<Int>.init(capacity: 10)
for i in (0 ..< 10) {
    array.addLast(e: i)
}

array
