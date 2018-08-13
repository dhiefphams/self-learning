using System;

namespace khtn_2018.Basic
{
    public class Homework
    {
        public static void run()
        {
            // grab the input from console
            Console.Write("Type your favorite number: ");
            int n = int.Parse(Console.ReadLine());
            if (n <= 0) {
                throw new Exception("N >= 1");
            }
            Console.WriteLine($"Ex1: S({n}) is {sumSquareReverse(n)}");
            Console.WriteLine($"Ex2: S({n}): {sumFacOverSum(n)}");
            Console.WriteLine($"Ex3: {n} is prime ? {isPrime(n)}");
            Console.WriteLine($"Ex4: sum of prime less than {n} : {sumOfPrimeLessThan(n)}");
        }

        /// Ex1: Calculate S(n) = 1/1 + 1/2^2 + ... + 1/n^2
        public static double sumSquareReverse(int n) {
            return n <= 1 ? 1 : sumSquareReverse(n - 1) + 1 / (Math.Sqrt(n));
        }


        /// Ex2: Calcuate S(n) = 1/1 + (1 * 2) / (1 + 2) + ... + N!/(1 + 2 + ... + N)
        public static double sumFacOverSum(int n) {
            return n <= 1 ? 1 : sumFacOverSum(n - 1) + (factorial(n) / sumRange(n));
        }

        /// Ex3. Prime number checking
        /// See algorithms: https://en.wikipedia.org/wiki/Primality_test#Pseudocode
        public static bool isPrime(int n) {
            if (n <= 1) {
                return false;
            }
            if (n <= 3) {
                return true;
            }
            if (n % 2 == 0 || n % 3 == 0) {
                return false;
            }
            for (int i = 5; i * i <= n; i += 6) {
                if (n % i == 0 || n % (i + 2) == 0) {
                    return false;
                }
            }
            return true;
        }

        // Ex4: Sum of prime less than n
        public static int sumOfPrimeLessThan(int n)
        {
            return n <= 1 ? 0 : sumOfPrimeLessThan(n - 1) + (isPrime(n) ? n : 0);
        }

        /// Calculate sum from 1 to n
        /// Example: n = 10, we have 1 + 2 + 3 + ... + 10
        public static int sumRange(int n) {
            return n <= 0 ? 0 : sumRange(n - 1) + n;
        }

        /// Factorial implementation
        /// 10! = 10...1
        public static int factorial(int n) {
            return n <= 1 ? 1 : factorial(n - 1) * n;
        }
    }
}