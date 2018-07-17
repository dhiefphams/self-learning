using System;
using System.Collections.Generic;

namespace NetStarter.OOP {
    class Bank {
        public static void run() {
            var qACB = new BankAccount("Mr Q", 1000);
            qACB.MakeWithdrawal(500, DateTime.Now, "Nhau");
            Console.WriteLine("balance now " + qACB.Balance);
            qACB.MakeDeposit(100, DateTime.Now, "Nop to tk");
            Console.WriteLine($"balance now is {qACB.Balance}");
            Console.WriteLine(qACB.GetAccountHistory());

            // exceptions
            try {
                new BankAccount("Ms Q", -500);
            } catch (ArgumentOutOfRangeException e) {
                Console.WriteLine(e.ToString());
            }

            try {
                qACB.MakeWithdrawal(1500, DateTime.Now, "Haha");
            } catch (ArgumentOutOfRangeException e) {
                Console.WriteLine(e.ToString());
            }
        }
    }
    
    class BankAccount {
        private static int accountNumberSeed = 234242340;
        
        public string OwnerName;
        public string Number;
        public decimal Balance {
            get {
                decimal balance = 0;
                foreach (var transaction in transactions) {
                    balance += transaction.Account;
                }
                return balance;
            }
        }
        private List<Transaction> transactions = new List<Transaction>();

        public BankAccount(string name, decimal initialBalance) {
            this.Number = accountNumberSeed.ToString();
            accountNumberSeed ++;
            this.OwnerName = name;
            MakeDeposit(initialBalance, DateTime.Now, "Initial balance");
        }

        public void MakeDeposit(decimal amount, DateTime date, string note) {
            if (amount <= 0) {
                throw new ArgumentOutOfRangeException(nameof(amount), "Amount of deposit must be positive");
            }
            var deposit = new Transaction(amount, date, note);
            transactions.Add(deposit);
        }

        public void MakeWithdrawal(decimal amount, DateTime date, string note) {
            if (amount <= 0) {
                throw new ArgumentOutOfRangeException(nameof(amount), "Ammount of withDrawal must be positibe");
            }
            if (Balance - amount < 0) {
                throw new InvalidOperationException("Not sufficient funds for this withdrawal");
            }
            var withdrawal = new Transaction(-amount, date, note);
            transactions.Add(withdrawal);
        }

        public string GetAccountHistory() {
            var report = new System.Text.StringBuilder();
            report.AppendLine("Date\t\t\tAmmount\tNote");
            foreach (var transaction in this.transactions) {
                report.AppendLine($"{transaction.Date}\t{transaction.Account}\t{transaction.Notes}");
            }
            return report.ToString();
        }

    }

    class Transaction {
        public decimal Account { get; }
        public DateTime Date { get; }

        public string Notes { get; }

        public Transaction(decimal amount, DateTime date, string node) {
            this.Account = amount;
            this.Date = date;
            this.Notes = node;
        }
    }
}