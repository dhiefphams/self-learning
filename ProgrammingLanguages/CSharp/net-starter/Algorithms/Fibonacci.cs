using System;
using System.Collections.Generic;

namespace NetStarter.Algorithms {
    class FibonacciGenerator {
        public static void run() {
            var first20Fib = new List<int>{};
            Console.WriteLine($"Index 20 {generate(20)}");
            for (var i = 1; i <= 20; ++i) {
                first20Fib.Add(generate(i));
            }
            Console.WriteLine(String.Join(" ", first20Fib));
        }

        /**
         * Implement fibonacci in c#
         * https://en.wikipedia.org/wiki/Fibonacci_number
         */
        public static int generate(int index) {
            return index == 0 || index == 1
                ? index
                : generate(index - 1) + generate(index - 2);
        }
    }
}