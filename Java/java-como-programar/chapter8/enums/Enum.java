public enum Enum
{
    BANANA(2.3),
    CEREAL(10),
    CACAU(15),
    CHOCOLATE(5),
    CAFÉ(0.3);

    private final double price;
    
    // método construtor para enum
    Enum(double price)
    {
        this.price = price;
    }
    public  double getPrice()
    {
        return price;
    }
}