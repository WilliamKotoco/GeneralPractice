import java.util.Scanner;
public class ATMmain {

    public static void main(String[] args)
    {
        double currMoney;
        ATM atm = new ATM(30);
        ATM atm2 = new ATM(-34); // vamos testar se o construtor faz a verificacao

    atm.displayMessage();
    System.out.println();
    atm2.displayMessage();
    currMoney = atm.getMoney();
    Scanner input = new Scanner(System.in);
    System.out.println("Quanto deseja depositar ?: ");
    currMoney = input.nextDouble(); // indica para o scanner que está lendo um double do teclado
    atm.deposit(currMoney);
    atm.displayMessage();
    System.out.println();

    currMoney = atm2.getMoney();
    System.out.println("Quanto deseja depositar na segunda conta?: ");
    currMoney = input.nextDouble();
    atm2.deposit(currMoney);

    atm2.displayMessage();
    System.out.println();
    }

    

}