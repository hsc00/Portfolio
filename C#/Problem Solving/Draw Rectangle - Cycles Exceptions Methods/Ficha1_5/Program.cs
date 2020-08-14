using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Ficha1_5
{
    class Program
    {
        static void Draw_Ret(int larg, int alt, char c)
        {

            Console.Write("\t");
            for (int i = 1; i <= larg; i++)
            {
                Console.Write(c);
            }
            Console.WriteLine();


            for (int k = 1; k <= alt - 2; k++)
            {
                Console.Write("\t");
                for (int p = 1; p <= larg; p++)
                {
                    if (p == 1 || p == larg)
                    {
                        Console.Write(c);
                    }
                    else
                    {
                        Console.Write(' ');
                    }
                }
                Console.WriteLine();
            }
            

            Console.Write("\t");
            for (int a = 1; a <= larg; a++)
            {
                Console.Write(c);
            }
        }

        static void Rect()
        {
            try
            {
                Console.Title = "Rectangle";
                Console.Write("Tell how wide is the rectangle: ");
                int wide = Convert.ToInt16(Console.ReadLine());

                Console.Write("Tell the height of the rectangle: ");
                int height = Convert.ToInt16(Console.ReadLine());

                Console.Write("Say the character you want to use draw the rectangle: ");
                char c = Convert.ToChar(Console.ReadLine());

                Console.WriteLine();
                Draw_Ret(wide, height, c);
                Console.ReadLine();
            }

            catch (System.FormatException)
            {
                Console.Write("Enter numbers only!");
                Thread.Sleep(1500);
                Console.Clear();
                Rect();
            }
        }


        static void Main(string[] args)
        {
            Rect();
        }
    }
}
