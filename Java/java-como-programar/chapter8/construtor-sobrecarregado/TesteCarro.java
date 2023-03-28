public class TesteCarro
{
    public static void main(String[] args)
    {
        Carro carro = new Carro();
        Carro carro2 = new Carro("Prisma");
        Carro carro3 = new Carro("Uno", 2004);
        Carro carro4 = new Carro("Kwid", 2018, 200000);

        DisplayCarro(carro);
        DisplayCarro(carro2);
        DisplayCarro(carro3);
        DisplayCarro(carro4);
    }


    public static void DisplayCarro(Carro car)
    {
        System.out.println("Nome: " + car.getNome());
        System.out.println("Ano: " + car.getAno());
        System.out.println("Valor: " + car.getPreco());
    }
}