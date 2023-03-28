import java.util.Scanner;
public class Welcome2
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        WelcomeMelhorado welcome = new WelcomeMelhorado();

        System.out.printf("Testando nome padrao %s \n", welcome.getName());

        System.out.println("Digite seu nome: ");
       String name = input.nextLine();
        welcome.setName(name);
        System.out.println();

        welcome.displayMessage();
    } 
}