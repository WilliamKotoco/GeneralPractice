public class WelcomeMelhorado
{
    private String name;
    // declara privado, só pode ser visto aqui dentro

    public void setName(String Receivedname)
    {
        name = Receivedname;
    }

    public String getName()
    {
        return name;
    }

    public void displayMessage()
    {
        System.out.printf("Welcome aboard captain %s", getName());
    }

}