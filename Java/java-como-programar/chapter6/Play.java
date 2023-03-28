/*
 Criar um joguinho de cassino, brincando com números aleatórios, que vai ter até dinheiro envolvido
 */
import java.util.Scanner;




public class Play{
    public static void main(String[] args)  throws InterruptedException
    {
        Player player = new Player();
        Games games = new Games();
        player.starting();  
        int op, received;
        boolean receivedStatus;
        while (player.currentMoney > -1000 && player.end == false)
        {
        op = displayInfo(player);
        switch(op)
        {
            case 1:
            received = games.crazyRoulette();
            System.out.printf("\n You got the number: %d \n", received);
            player.currentMoney += received;
            break;

            case 2:
            receivedStatus = games.russianRoulette();
            if (receivedStatus == true)
            {
                System.out.println("\n You died!");
                player.end = receivedStatus;
            }
            else
            {
                System.out.println("\n You got lucky!");
                player.currentMoney += 1000;
            }
            break;

            case 3:
            received = games.jokenpo();
            if (received > 0 )
                System.out.println("You won!");
            else if (received == 0)
                System.out.println("Tied!");
            else
                System.out.println("You lost!");
            player.currentMoney += received;
            break;

            case 4:
            received = games.slotMachine();
            System.out.println("You received " + received);
            player.currentMoney += received;
            break;

            case 5:
            if (player.currentMoney >= 10000)
            {
                    System.out.println("You bought the cassino!");
                    player.end = true;
            }
            else
                System.out.println("Not enough money!");
            break;
            
        }

        Thread.sleep(1000);
        }
        if(player.currentMoney < -1000)
            System.out.println("You got killed due your debt with the cassino");
    }
    private static int displayInfo(Player player)
    {
        Scanner input = new Scanner(System.in);
        int op;
        System.out.println("--------------------------------");
        System.out.println("Displaying information: ");
        System.out.println("Current Money: " + player.currentMoney + "$");
        // ele converte o current money para string e mostra como string
        System.out.println("--------------------------------");
        System.out.println("[1] - crazy roulette wheel");
        System.out.println("[2] - russian roulette");
        System.out.println("[3] - jokenpo");
        System.out.println("[4] - slot machine");
        System.out.println("[5] - buy the cassino $10000");
        op = input.nextInt();
        return op;
       
    }

 
}
