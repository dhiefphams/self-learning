using System;

namespace NetStarter.OOP.Inheritence
{
    public enum PublicationType { Misc, Book, Magazine, Article };
    
    public class BookStore
    {
        public static void run()
        {
            var book = new Book("The Tempest", "0971655819", "Shakespeare, William", "Public Domain Press");
            ShowPublicicatioinInfo(book);
            book.Publish(new DateTime());
            ShowPublicicatioinInfo(book);

            var book2 = new Book("The Tempest", "Classic Works Press", "Shakespeare, William");
            Console.WriteLine($"{book.Title} and {book2.Title} are the same publication: " +
                $"{((Publication) book).Equals(book2)}");
        }

        public static void ShowPublicicatioinInfo(Publication pub)
        {
            string pubDate = pub.GetPublicationDate();
            Console.WriteLine($"{pub.Title}, " +
                              $"{(pubDate == "NYP" ? "Not Yet Published" : "published on" + pubDate):d} by {pub.Publisher}");
        }
    }


    public abstract class Publication
    {
        private bool published = false;
        private DateTime datePublished;
        private int totalPages;

        public Publication(string title, string publisher, PublicationType type)
        {
            if (publisher == null) {
                throw new ArgumentNullException("The publisher cannot be null");
            } else if (String.IsNullOrWhiteSpace(publisher)) {
                throw new ArgumentException("Ths publisher cann not only of white space");
            }
            Publisher = publisher;
            if (title == null) {
                throw new ArgumentNullException("The title cannot be null");
            } else if (String.IsNullOrWhiteSpace(title)) {
                throw new ArgumentException("The title can not only of white space");
            }
            Title = title;
            Type = type;
        }

        public string Publisher { get; }
        public string Title { get; }

        public PublicationType Type { get; }

        // allow public get but update value forces to used method
        public string CopyrightName { get; private set; }

        public int CopyrightDate { get; private set; }

        public int Pages
        {
            get { return totalPages; }
            set
            {
                if (value <= 0) {
                    throw new ArgumentOutOfRangeException("The number of pages cannot be zero of negative");
                }
                totalPages = value;
            }
        }

        public string GetPublicationDate()
        {
            return !published ? "NYP" : datePublished.ToString("d");
        }

        public void Publish(DateTime datePublished)
        {
            published = true;
            this.datePublished = datePublished;
        }

        public void CopyRight(string copyrightname, int copyrightDate)
        {
            CopyrightName = copyrightname;
            CopyrightDate = copyrightDate;
        }

        public override string ToString() => Title;
    }


    // now, create the book class
    // we use sealed to mark this class can't be interted any more
    public sealed class Book: Publication
    {
        public Book(string title, string author, string publisher):
            this(title, String.Empty, author, publisher)
        {}

        public Book(string title, string isbn, string author, string publisher):
            base(title, publisher, PublicationType.Book)
        {
            // isbn argument must be a 10- or 13- characters numeric string without "-" characters.
            // We could alose deternime whether the ISBN is valid by comparing its checksum digit
            // with a computed checksum

            if (!String.IsNullOrEmpty(isbn)) {
                if (!(isbn.Length == 10 || isbn.Length == 13)) {
                    throw new ArgumentException("The ISBN must be a 10=");
                }
                ulong nISBN = 0;
                if (!UInt64.TryParse(isbn, out nISBN)) {
                    throw new ArgumentException("this ISBM can consist of numeric characters only");
                }
                this.ISBN = isbn;    
            }
            Author = author;
        }

        public string ISBN { get; }

        public string Author { get; }

        public Decimal Price { get; private set; }

        public string Currency { get; private set; }

        public Decimal SetPrice(Decimal price, string currency) {
            if (price < 0) {
                throw new ArgumentOutOfRangeException("This price cannot be negative");
            }
            Decimal oldVal = Price;
            Price = price;
            if (currency.Length != 3) {
                throw new ArgumentException("The ISO currency symbol is a 3-character string");
            }
            Currency = currency;
            return oldVal;
        }

        public override bool Equals(object obj) {
            Book book = obj as Book;
            return book == null ? false : ISBN == book.ISBN;
        }

        public override int GetHashCode() => ISBN.GetHashCode();

        public override string ToString() => $"{(String.IsNullOrEmpty(Author) ? "" : Author + ", ")}{Title}";
    }

}