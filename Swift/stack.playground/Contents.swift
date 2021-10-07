import UIKit

func example(of description: String, execute: () -> Void) {
    print(description)
    execute()
    print("\n")
}

public struct Stack<Element> {
    private var storage: [Element] = []
    
    public init() {}
    
    public init(_ elements: [Element]) {
        storage = elements
    }
    
    public mutating func push(_ element: Element) {
        storage.append(element)
    }
    
    @discardableResult
    public mutating func pop() -> Element? {
        storage.popLast()
    }
    
    public func peek() -> Element? {
        storage.last
    }
    
    public var isEmpty: Bool {
        peek() == nil
    }
}

extension Stack: CustomStringConvertible {
    public var description: String {
        """
        ------top------
        \(storage
            .map({ "\($0)" })
            .reversed()
            .joined(separator: "\n"))
        ---------------
        """
    }
}

extension Stack: ExpressibleByArrayLiteral {
    public typealias ArrayLiteralElement = Element
    
    public init(arrayLiteral elements: Element...) {
        storage = elements
    }
    
}

example(of: "using a stack") {
    var stack = Stack<Int>()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    
    print(stack)
}

example(of: "initializing a stack from an array literal") {
    var stack: Stack = [1, 2, 3, 4, 5]
    print(stack)
    stack.pop()
}

// Challenge 1: Reverse an array
func printInReverse<T>(_ array: [T]) {
    var stack = Stack<T>()
    
    for value in array {
        stack.push(value)
    }
    
    while let value = stack.pop() {
        print(value)
    }
}

// Challenge 2: Balance the parentheses
func checkParentheses(_ string: String) -> Bool {
    var stack = Stack<Character>()
    
    for character in string {
        if character == "(" {
            stack.push(character)
        } else if character == ")" {
            if stack.isEmpty { return false }
            else { stack.pop() }
        }
    }
    
    return stack.isEmpty
}
