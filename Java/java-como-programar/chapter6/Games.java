import java.util.Random;
import java.util.Scanner;
public class Games
{
    Random rand = new Random();

    public int crazyRoulette()
    {
        int randNum = rand.nextInt()%501;
        // números ficarão entre -500 e 500
        return randNum;
    }
    public boolean russianRoulette()
    {
        // vai ter 3 posições na fila
        int queuePosition, killed;
        queuePosition = rand.nextInt()%3;
        System.out.println("Loading the gun...");
        killed = rand.nextInt()%3;
        if (queuePosition == killed)
            return true;
        return false;
    }

    public int jokenpo()
    {
        int op, computerOp;
        Scanner input = new Scanner(System.in);
        System.out.println(" Enter your option: ");
        System.out.println("[0] Rock");
        System.out.println("[1] Paper");
        System.out.println("[2] Scissors");
        op = input.nextInt();
       computerOp = Math.abs(rand.nextInt()%3);
       if (computerOp == op)
        return 0;
        if((computerOp == 0 && op == 1) || (computerOp  == 1 && op == 2) || (computerOp == 2 && op == 0))
        {
            return 350;
            // o java usa short-circuit evaluation para or statements, então se o primeiro for verdadeiro ele já para de ler a expressao           
        }
        return -350;
    }

    public int slotMachine() throws InterruptedException
    {
        int op1,op2,op3;
        op1 = Math.abs(rand.nextInt()%11);
        op2 = Math.abs(rand.nextInt()%11);
        op3 = Math.abs(rand.nextInt()%11);
        System.out.println("Primeira máquina: " + op1);
        Thread.sleep(1000);
        System.out.println("Segunda máquina: " + op2);
        Thread.sleep(1000);
        System.out.println("Terceira máquina: " + op3);
        if (op1 == op2 && op2== op3 )
            return 2000;
        if (op1 != op2 && op2 != op3)
            return -500;
        else
            return 500;
    }
}