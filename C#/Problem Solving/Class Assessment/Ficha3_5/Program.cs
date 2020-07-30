using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ficha3_5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Class Assessment";
            
            
            int numStudents;
            double grade;
            double sum = 0;
            double max = 0, min = 5000;
            int countpos = 0, countneg = 0;
            string op = string.Empty;

            Console.WindowWidth = Console.WindowWidth + 40;
            Menu1();
            Console.WriteLine();
            Menu2(out numStudents);
            Console.WriteLine();

            for (int i = 1; i <= numStudents; i++)
            {
                Console.Write("Type in the grade of the student {0}: ", i);
                grade = Convert.ToDouble(Console.ReadLine());
                max = Maximum(grade, max);
                min= Minimum(grade, min);
                sum = sum + grade;
                gradesPosNeg(grade, ref countpos, ref countneg);
            }

            do
            {
                Console.Clear();


                Menu3(ref op);
                Console.WriteLine();
                switch (op)
                {
                    case "med": Console.WriteLine("\t\tAverage: {0}", Average(sum, numStudents));
                        break;

                    case "max": Console.WriteLine("\t\tMax Grade: {0}", max);
                        break;

                    case "min": Console.WriteLine("\t\tMin Grade: {0}", min);
                        break;

                    case "pos": Console.WriteLine("\t\tPositives: {0}", countpos);
                        break;

                    case "neg": Console.WriteLine("\t\tNegatives: {0}", countneg);
                        break;

                    case "s": Environment.Exit(0);
                        break;

                    default:
                        break;
                }
                Console.ReadKey();
                
            } while (op!="s");

            Console.WriteLine();
            
        }

        static double Average(double sum, int na)
        {
            return sum / na;
        }

        static double Maximum(double grade, double max)
        {
            if (grade > max)
            {
                max = grade;
            }
            return max;
        }

        static double Minimum(double grade, double min)
        {
            if (grade < min)
            {
                min = grade;
            }
            return min;
        }

        static void gradesPosNeg(double grade, ref int countpos, ref int countneg)
        {
            if (grade >= 10)
            {
                countpos++;
            }
            else
            {
                countneg++;
            }
        }

        static void Menu1()
        {
            Console.WriteLine("With this program you can prepare a balance sheet for a class with values like:");
            Console.WriteLine("\t\t--Number of students to be assessed;");
            Console.WriteLine("\t\t--Students Evaluation;");
            Console.WriteLine("\t\t--Display Menu with: Average, Max, Min, Number of negatives and positives");
            Console.WriteLine("\t\t--Leave the program anytime.");
        }
        static void Menu2(out int na)
        {
            do
            {
                Console.Write("Enter the number of students to evaluate, the number must be greater than zero:");
                na = Convert.ToInt16(Console.ReadLine());
            } while (na <= 0);
            
        }
        static void Menu3(ref string op)
        {
            Console.WriteLine("********************* CLASS BALANCE SHEET *********************");
            Console.WriteLine("Calculation of the class average<Enter the word MED>.");
            Console.WriteLine("Calculation of maximum class grade<Enter the word MAX>.");
            Console.WriteLine("Calculation of minimum class grade<Enter the word MIN>");
            Console.WriteLine("Calculation of the number of positives in the class <Enter the word POS>.");
            Console.WriteLine("Calculation of the number of class negatives<Enter the word NEG>.");
            Console.WriteLine("To exit < Enter 's' or 'S' >");
            op = Console.ReadLine();
            op=op.ToLower();
        }
    }
}
