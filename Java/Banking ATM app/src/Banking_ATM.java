import java.util.Scanner;

class ScannerTest {

    public static void main(String[] args) {

        BankAccount user1 = new BankAccount("John Doe",824751028, 9359);
        System.out.println("(Use this user to test the ATM) Client ID: " + user1.customerId + " PIN: " + user1.userPin);
        user1.login();
    }
}


class BankAccount {
     double balance;
     double previousTransaction;
     String customerName;
     int customerId;
     int userPin;
     int checkCustomerId;
     int checkUserPin;

     BankAccount(String cname,int cid, int pin) {

         customerName = cname;
         customerId = cid;
         userPin = pin;
     }

     void login(){
         try {
             Scanner scanner = new Scanner(System.in);
             System.out.println("Welcome to my ATM! \n\nPlease insert your client ID: ");
             checkCustomerId = scanner.nextInt();
             System.out.println("Please insert your PIN: ");
             checkUserPin = scanner.nextInt();
         }
         catch (Exception e) {
             System.out.println("Invalid user! Please try again!");
             return;
         }
         if(customerId == checkCustomerId && userPin == checkUserPin) {
             showMenu();
         }
         else System.out.println("Your Client ID or Pin was wrong!");
     }

     void deposit(double amount) {
         balance = balance + amount;
         previousTransaction = amount;
     }

     void withdraw(double amount) {

         if(amount != 0)
         {
             balance = balance - amount;
             previousTransaction = -amount;
         }
     }

     void getPreviousTransactions() {

         if(previousTransaction > 0) {

             System.out.println("Deposited: " + previousTransaction);
         }
         else if(previousTransaction < 0)
         {
            System.out.println("Withdraw: " + Math.abs(previousTransaction));
         }
         else {

             System.out.println("No transaction occurred");
         }
     }

     void showMenu() {

         char option;
         Scanner scanner = new Scanner(System.in);

         System.out.println("\nWelcome " + customerName);
         System.out.println("Client ID: " + customerId);
         System.out.println("\n");
         System.out.println("A. Check Balance");
         System.out.println("B. Deposit");
         System.out.println("C. Withdraw");
         System.out.println("D. Previous Transaction");
         System.out.println("E. Exit");

         option = Character.toUpperCase(scanner.next().charAt(0));

             switch(option){
                 case 'A':
                     System.out.println("Balance = " + balance);
                     System.out.println("\n");
                     System.out.println("Press X to go back to the menu");
                     getInput();
                 case 'B':
                     System.out.println("Enter an amount to deposit: ");
                     try {
                         double amount = scanner.nextDouble();
                         if(amount > 0) {
                             deposit(amount);
                             System.out.println("The amount has been deposited!");
                             System.out.println("\nPress X to go back to the menu");
                             getInput();
                         }

                         else {
                             System.out.println("Invalid amount! Please try again!");
                             showMenu();
                         }
                     }
                     catch (Exception e) {
                         System.out.println("Invalid amount! Please try again!");
                         showMenu();
                     }
                 case 'C':
                     System.out.println("Enter an amount to withdraw: ");
                     try {
                         double amountW = scanner.nextDouble();
                         if(amountW > 0) {
                             withdraw(amountW);
                             System.out.println("The amount has been withdrawn!");
                             System.out.println("\nPress X to go back to the menu");
                             getInput();
                         }
                         else{
                             System.out.println("Invalid amount! Please try again!");
                             showMenu();
                         }
                     }
                     catch (Exception e) {
                         System.out.println("Invalid amount! Please try again!");
                         showMenu();
                     }
                 case 'D':
                     getPreviousTransactions();
                     System.out.println("\nPress X to go back to the menu");
                     getInput();
                 case 'E':
                     System.out.println("Thank you for using our services");
                     login();
                 default:
                     System.out.println("Invalid Option!! Please enter again");
                     showMenu();
             }

     }
     void getInput() {
         Scanner scanner = new Scanner(System.in);
         char input = Character.toUpperCase(scanner.next().charAt(0));
         if(input == 'X') {
             showMenu();
         }
         else getInput();
     }
}