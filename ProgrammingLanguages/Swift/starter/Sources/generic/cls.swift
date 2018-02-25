// class or struct kind of same
// struct InventoryList<Elem> {
class InventoryList<Elem> {
    var items: [Elem]

    mutating func push(item: Elem) {
        self.items.append(item)
    }

    mutating func pop() -> Elem {
        return self.items.removeLast()
    }

    func shouldBuyMore() -> Bool {
        return self.items.count < 3
    }
}

// extension the struct/class
extension InventoryList {
    var top: T? {
        return items.last
    }
}
