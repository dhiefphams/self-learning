using System;

namespace NetStarter
{
    class Program
    {
        static void Main(string[] args)
        {
            Hello.run();
            Collections.HelloListString.run();
            Algorithms.FibonacciGenerator.run();
            // OOP.Bank.run();
            OOP.Inheritence.Shape.run();
            OOP.Inheritence.BookStore.run();
            OOP.DI.IOCContainer.run();
        }
    }
}
