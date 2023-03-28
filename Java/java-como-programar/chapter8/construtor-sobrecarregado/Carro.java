public class Carro
{
    private String nome;
    private int ano;
    private float preco;

    public Carro() // construtor padrao
    {
        this("NULL", 2022, 0);
    }

    public Carro(String nome) // construtor com um parãmetro só
    {
        this(nome, 2022, 0);
    }

    public Carro(String nome, int ano)
    {
        this(nome,ano,0);
    }

    public Carro(String nome, int ano, float preco) // construtor com todos argumentos passados
    {
        this.nome = nome;
        this.ano = ano;
        this.preco = preco;
    }

    public String getNome()
    {
        return nome;
    }
    public int getAno()
    {
        return ano;
    }
    public float getPreco()
    {
        return preco;
    }

    /* 
       public carro(Carro teste)
    {
        this(teste.getName(), teste.getAno(), teste.getPreco());
    }
     * 
     * 
    */
    public void DisplayCarro()
    {

    }
}