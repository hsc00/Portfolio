using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ficha_1._9
{
    class Program
    {
        static double Salary(int esc, double numh)
        {
            double quantity = 0;
            switch (esc)
            {
                case 1:
                    quantity = numh * 2.5;
                    break;

                case 2:
                    quantity = numh * 3.0;
                    break;

                case 3:
                    quantity = numh * 3.75;
                    break;

                case 4:
                    quantity = numh * 5;
                    break;

                default:
                    break;
            }
            return quantity;

        }

        static void Main(string[] args)
        {
            Console.Title = "Payments";

            Console.WriteLine("-------------Echelons----------------");
            Console.WriteLine("Echelon 1 - 2.5 euros");
            Console.WriteLine("Echelon 2 - 3.0 euros");
            Console.WriteLine("Echelon 3 - 3.75 euros");
            Console.WriteLine("Echelon 4 - 5 euros");

            int esc;
            double numh;
            do
            {
                Console.WriteLine("\nSay what is your echelon: ");
                esc = Convert.ToInt16(Console.ReadLine());
            } while (esc != 1 && esc != 2 && esc != 3 && esc != 4);

            do
            {
                Console.WriteLine("How much hours did you worked?");
                numh = Convert.ToInt16(Console.ReadLine());
            } while (numh <= 0);

            double quantity = Salary(esc, numh);
            Console.WriteLine("Because you're in the echelon {0} and you worked {1} hours, you'll receive {2} euros", esc, numh, quantity);

            Console.ReadLine();
        }
    }
}
