public class ATM
{
    private double money;

    public ATM(double moneyReceived)
    {
        if (moneyReceived > 0)
            money = moneyReceived;
    }

    public double getMoney()
    {
        return money;
    }

    // não precisa do método set, não podemos setar o dinheiro inicial, apenas depositar mais
    public void deposit(double moneyReceived)
    {
        money += moneyReceived;
    }
    public void displayMessage()
    {
        System.out.printf("Money: %f \n", money );
    }
}