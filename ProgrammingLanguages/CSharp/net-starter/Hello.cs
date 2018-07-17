using System;

namespace NetStarter
{
    class Hello
    {
        private string hello = "Hello world";

        public static void run() {
            Console.WriteLine("Welcome to hello world app");
            var hello = new Hello();
            Console.WriteLine(hello.hello);
        }
    }
}