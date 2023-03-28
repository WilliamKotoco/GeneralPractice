import java.util.Random;
public class Votacao
{

    public static void main(String[] args)
    {
           
        int[] frequency = new int[7]; // há 7 canditados
        int[] votes = new int [2000]; // 2 mil votos
        int i;
        election(votes, frequency);
        votes[1999] = 90;
        for(i =0; i < votes.length ; i++)
        {

            try {

                ++frequency[votes[i]];

            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Erro" + e);
            }
        }

        for (i =0; i < frequency.length ; i++)
        {
            System.out.println("Canditate: "+ frequency[i]);
        }
    }

    public static void election(int[] votes, int[] frequency)
    // static porque static podem chamar static da mesma classe
    {
        int i;
        Random random = new Random();
        for (i=0; i< votes.length; i++)
        {
            votes[i] = Math.abs(random.nextInt()%7);
        }
    }
}