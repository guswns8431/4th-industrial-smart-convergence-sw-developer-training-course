using System;

namespace ex0213
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = 52.273;
            double b = 103.32;

            Console.WriteLine(a + b);
            Console.WriteLine(a - b);
            Console.WriteLine(a * b);
            Console.WriteLine(a / b);
            Console.WriteLine("ex0214");
            Console.WriteLine();

            char c = 'a';
            Console.WriteLine(c);
            Console.WriteLine();

            Console.WriteLine("code0234");
            Console.WriteLine("int: " + sizeof(int));
            Console.WriteLine("long: " + sizeof(long));
            Console.WriteLine("float: " + sizeof(float));
            Console.WriteLine("double: " + sizeof(double));
            Console.WriteLine("ulong: " + sizeof(ulong));
            Console.WriteLine("uint: " + sizeof(uint));

            Console.Clear();

            char B = (char)0x42;
            char z = (char)(0x41 + 25 + 0x20);

            Console.WriteLine(B);
            Console.WriteLine(z);

        }
    }
}
