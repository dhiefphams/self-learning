// Constraining the generic type
protocol Summable {
    static func +(lhs: Self, rhs: Self) -> Self
}

extension Int: Summable {}
extension Double: Summable {}
extension Float: Summable {}
extension String: Summable {}

func add<T: Summable>(_ nb1: T, _ nb2: T) -> T {
    return nb1 + nb2
}

// Function generics
func functionGenerics() {
    print("Function generics")
    print("1 + 1 = \(add(1, 1))")
    print("1.2 + 2.3 = \(add(1.2, 2.3))")
    print("hello + world = \(add("hello", "world"))")   
}
