# Swift 4+ FAQ
- [Swift 4+ FAQ](#swift-4-faq)
    - [1. class method vs static method ?](#1-class-method-vs-static-method)
    - [2. Access control explaination](#2-access-control-explaination)

## 1. class method vs static method ?

Same: Associate a method of a class, rather than an instance

Diff: **The subclasses can override class method but can not override with static method**

## 2. Access control explaination

- `open`: Both outside and inside module (target) can access, **can override**
- `public`: Like `open` but the subclasses **CAN ONLY** override within same module (target)
- `internal`: (default): Only inside module (target) can access
- `fileprivate`: can only be used with in current file
- `private`: scope `{}`

Reference: [1](https://medium.com/@abhimuralidharan/swift-3-0-1-access-control-9e71d641a56c)