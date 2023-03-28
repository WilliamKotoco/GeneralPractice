import java.util.Scanner;
public class List
{
    public static void main(String[] args)
    {
 
        
        
        System.out.println("Lista de produtos: ");
        for (Enum item: Enum.values())
        {
            System.out.printf("%s %.2f \n", item, item.getPrice());
        }
     
        
        
    }
}