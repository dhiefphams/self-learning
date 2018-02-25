// references: https://medium.com/developermind/generics-in-swift-4-4f802cd6f53c

protocol Storage {
    associatedtype Item
    var items: [Item] { set get }
    mutating push(item: Item)

    var size: Int { get }
    mutating pop() -> Item

    
    func showCurrentInventory() -> [Item]
}

// implement the protocol above
struct RedisStorage: Storage {
    typealias Item = Food
    // implement the methods and props
    var items: [Food]()
}

// using with where clause
// only apply thoose method on String Item
extension Storage where Item == String {
    func thisIsStr()
}
