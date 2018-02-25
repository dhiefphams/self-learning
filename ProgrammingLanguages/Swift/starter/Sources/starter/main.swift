import Foundation

// use different in linux

#if os(Linux)
	srandom(UInt32(time(nil)))
#endif

func getRandom(_ max: Int) -> UInt32 {
    #if os(Linux)
        return UInt32(random() % max)
    #else
        return UInt32(arc4random_uniform(UInt32(max)))
    #endif
}

let magicNumber: UInt32 = getRandom(100)

print("Magic number \(magicNumber)")

var guess: UInt32 = 0
repeat {
	guess += 1
} while (magicNumber != guess)

print("Catch")

func helloWorld(name: String) {
	print("Hello \(name)")
}

if CommandLine.arguments.count != 2 {
	print("Usage hello Name")
} else {
	let name = CommandLine.arguments[1]
	helloWorld(name: name)
}
