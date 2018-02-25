enum Result<V> {
    case success(V)
    case error(Error)
}

enum MathError: Error {
    case divideByZero
}

func divide(_ x: Int, _ y: Int) -> Result<Int> {
    return y == 0 ? .error(MathError.divideByZero) : .success(x / y)
    // using guard
    // guard y != 0 else {
    //     return .error(MathError.divideByZero)
    // }
    // return .success(x / y)
}

func enumGenerics() {
    print("Enum generics")
    print(divide(10, 0))
    print(divide(10, 2))
}