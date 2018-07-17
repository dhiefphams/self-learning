using System;
using System.Collections.Generic;

namespace NetStarter.Collections {
    class HelloListString {
        public static void run() {
            Console.WriteLine("Start to learn list collections");
            var names = new List<string> { "Micheal", "Liincln", "Abraham" };
            names.Add("Nam");
            foreach (var name in names) {
                Console.WriteLine(name);
            }

            Console.WriteLine($"Index of Trung is {names.IndexOf("Trung")}");
            Console.WriteLine($"Total item in list {names.Count}");
            // sort by alphabet
            names.Sort();
            foreach (var name in names) {
                Console.WriteLine(name);
            }
        } 
    }
}