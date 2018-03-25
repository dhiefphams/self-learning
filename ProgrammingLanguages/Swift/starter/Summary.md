# Swift Summary cheetsheet

## Variable

- `let`: constant
- `var`: variable

## Data types

- Numeric: `Int`, `Int64`, `Float`, `Double`
- Boolean: `Bool`
- String: `Character` (`"A"`)

**Notes**

- No boolean implicit

```swift
let i = 1
if i {
    // won't compile
}
// use like this
if i == 1 {
    // dosth
}
```

**Type casting** `DType(value)`

- Between interger: raised error when results in a overflow
- Floatint point -> Integer: Truncated

### String

```swift
var name = "Just give Q a reason"
// length
name.characters.count
// first str
name[name.startIndex]
// 5 index
let index5 = name.index(name.startIndex, offsetBy: 5)
name[index5]
// check empty
name.isEmpty
// insert string, notes: the name must be var
name.insert("A", at: repeatingname.startIndex)
// more complex
name.insert(contentsOf: " hello world ".characters, at: name.index(name.startIndex, offsetBy: 4))

// slice
let startIndex = name.index(name.startIndex, offsetBy: 2)
let endIndex = name.index(name.startIndex, offsetBy: 10)
// this will create a `substring reference` from from the memory address of the
// string
let substr = name[startIndex ..< endIndex]
// start the copying
String(substr)
```

### Array

Store data that have the same dtype

```swift
// using constructor
var q_arr = [Int]()
q_arr.isEmpty
q_arr.append(5)
q_arr += [1, 2]
q_arr[0] = 100
// at index must lower than the current size of array
q_arr.insert(10, at: 2)
q_arr.remove(at: 2)
// change a slice inside the arr
q_arr[0...2] = [1, 2, 3] // can not use [1...3] or 1...3
// length
q_arr.count


// init the array with length
var arr_2 = Array(repeatElement(0, count: 10))
var arr_3 = arr_2 + q_arr
```

Range operators:

- Closed: [a...b] include both a and b
- Haft: [a..<b]: Exclude b, we can delete a if a == 0
- One side: [...a], [b...]

### Dict

```swift
// constructor
var dict = [Int: String]()
// init value
var dict: [String: String] = ["1": "Just", "adsf": "aaa"]
dict.isEmpty

if let name = q["3"] {
    print(name)
}

// loop/enumerating the dictionary
for (k, v) in dict {
    // do something
}
```

### Tuples

```swift
let height: Double = 6.25
let width: Int = 175

// using index based
let t = (height, width)
t.0
t.1

// using name based
let t = (height: height, width: width)
t.height
t.width
```

**Deconstruct the tuples**

```swift
let (height, width) = t
// or just one part
let (height, _) = t
```

### Optinal values

```swift
var q: String? // q automatic set to `nil`
q = "aaa"
if q != nil { // hola, like go
    let anotherQ = q
    // do sth
}

// using binding
if let anotherQ = q {
    // do sth
}
// str -> int
if let age = Int(ageStr) {
    // success conversion
} else {
    // failed conversion
}
```

Using binding to check condition

```swift
if let firstNum = Int("4"), let secondNum = Int("42"), firstNum < secondNum && secondNum < 100 {
    // do something
} else {
    // just false validate
}
```

Implicit unwrappeed optionals

```swift
// force get the value of optional value
// raise if the value is `nil`
let possibleStr: String? = "aaa"
let forcedStr: String = possibleStr! // ok

var possible: String?
let forced: String = possible! // raised error

let assumedString: String! = "aaa" // assumedString is an optinal String (String? type)
let implicitStr: String = assumedString // ok, auto unwrapped
```

### Enum

```swift
enum QEmotion: Int { // specific the type of enum
    case funny
    case sad
    case anger
}
var qm = QEmotion.funny
qm = .angar
// compare
qm == .funny
```

### Struct

```swift
// like C++
struct Rect {
    // automatic create a constructo with all params
    var height = 0.0
    var width = 0.0

    func area() -> Double {
        // implicit self
        return width * height
    }
}

val q = Rect(height: 200, width: 22)
q.area()
```

### Class

```swift
class Animal {
    var name: String
    var height: Double // kg
    var weight: Double // m
    var sound: String

    // constructor
    init(name: String, height: Double, weight: Double, sound: String) {
        self.name = name
        self.height = height
        self.weight = weight
        self.sound = sound
    }

    func talk() -> String {
        return self.sound
    }

    func bmi() -> Double {
        return self.weight / (self.height * self.height)
    }
}
```

Inheritence

```swift
// like C+
class Dog: Animal {
    final func digHole() {
        print("Dig Dig Dig")
    }

    override func talk() -> String {
        return "Hahaha \(super.talk())"
    }
}
```

Check instance

```swift
let dog = Dog(name: "Vz", height: 22, weight: 11, sound: "Wofffff")
dog is Dog // true
dog is Animal
```

### Protocol

Just like interface

```swift
protocol Flyable {
    // props
    var flies: Bool { get set }

    // methods
    func fly(distance: Double) -> String
}

class Plant: Flyable {
    var flies: Bool = false
    var name: String = "Hola"

    func fly(distance: Double) -> String {
        return "I flied \(dist) m"
    }
}

let f: Flyable = Plant()
f.fly(distance: 100.0)
```

## Flow control

Condition operator:

- `>, <, <=, >=`
- `==, !=` (compare value)
- `===, !==`: Compare reference

### If/Else

```swift
let age = 17
if age < 5 {
    print("Go to preschool")
} else if (age >= 5) && (age < 18) {
    print("Go to grade")
} else {
    print("Go to other")
}

// Tenary operator
let canDrive: Bool = age >= 16 ? true : false

// if let: use with dict
let dict: [Int: String] = [11: "just"]
if let q = dict[11] {
    // will execute if `11` is in dict
    print(q)
}
```

**Nil Coalescing Operators**

```swift
var optinal: String?
print("Hello \(optional ?? \"world\")" // like || in javascript
```

### Switch/Case

```swift
let ingredient = "pasta"
switch ingredient {
case "tomato", "pasta":
    print("Spaghetti")
    // if I want to execute the next case, even though the condition doesn't match
    fallthrough

case "beans":
    print("Burrito")
default:
    print("Nothing")
}

// With range
let score = 8
switch score {
case 0...5:
    print("Failed")

case 8...10:
    print("Great")

default:
    print("Ok fine")
}
```

### For loop

```swift
// iterate through array
for item in arr_3 {
    print(item)
}

for (index, val) in arr_3.enumerated() {
    // do somethings
}


// specific values
var arr_5 = [1, 2, 3]
// array like
for i in 1...5 {
    print(i)
}
// with condition
for i in 1...10 where i % 2 == 0 {
    // do something
}
```

### While loop

```swift
var i: Int = 0
where i  < 10 { // like golang, no ()
    if i % 2 == 0 {
        i += 1
        continue
    }
    if i == 7 {
        break
    }
    print(i)
    i += 1
}
```

### Repeat while (like while-do)

```swift
import Foundation

// use different in linux

// random seed
#if os(Linux)
    srandom(UInt32(time(nil)))
#endif

func getRandom(_ max: Int) -> UInt32 {
    #if os(Linux)
        return UInt32(random() % max)
    #else
        return UInt32(arc4random_uniform(UInt32(max))
    #endif
}

let magicNumber: UInt32 = getRandom(10)
var guess: UInt32 = 0
repeat {
    print("Guess \(guess)")
    guess += 1
} while (magicNumber != guess)
```

## Function

- Like golang
- Function isn't return inference

```swift
func sum(a: Int, b: Int) -> Int {
    return a + b
}
sum(a: 1, b: 2)
```

**Rest parameters**

```swift
func sum(ints: Int...) -> Int {
    var sum: Int = 0
    for val in ints {
        sum += val
    }
    return sum
}
```

**Closure/Lambda function**

- Nested function

```swift
func multiply(first: Int, second: Int) -> Double {
    func divide() -> Double {
        return Double(first) / Double(second)
    }
    return divide()
}
```

- Lambda function

```swift
var square: (Int) -> (Int) = {
    num in
    return num * num
} // this is lambda function
square(2)

// using functional
var arr = [1, 2, 3]
arr
    .sorted(by: {
        x, y in x < y
    })
    .map{ (num: Int) -> Int in square(num) }
```

- Higher order function

```swift
func multiplyBy(factor: Int) -> (Int) -> (Int) {
    func mul(nb: Int) {
        return factor * nb
    }
    return mul
}
let mul3 = multiplyBy(factor: 3)
mul3(3)
```

Function receive another function as param

```swift
func exec(_ fn: (Int) -> (Int), val: Int) {
    print(fn(val))
}

exec({x in x * x}, val 2)
```

Functional

```swift
let q = 1...100
q.filter({ (num: Int) -> Bool in return num % 5 == 0})
// for short
q.filter{(num: Int) -> Bool in num % 5 == 0}

q.reduce(0) { ( acc: Int, val: Int) -> Int in acc + val }
```

## Error handling

```swift
enum DivisionError: Error {
    case DivideByZero

    case tooLarge(Int)
}

func divide(_ nb1: Double, _ nb2: Double) throws -> Double { // like a mark in java
    if (nb2 == 0) {
        throw DivisionError.DivideByZero
    }
    return nb1 / bn2
}

do {
    let q = try divide(10, 0)
    print(q)
} catch DivisionError.DivideByZero {
    // do sth
} catch DivisionError.tooLarge(let val) {
    // do something with val
}
```

## Extensions

Add new methods/props for existing class or struct or dtype

```swift
extension Double {
    // props
    var fm: Double {
        return self * 1000.0
    }

    // method
    mutating func square() -> Double {
        return self * self
    }

    func log() -> String {
        return "Hahaha \(self)"
    }
}
```