public class Empregado
{
    private final String name;
    private final String cpf;
    protected  double gross; // protected para a base poder acessar
    protected double comission;
    
    public Empregado(String name, String cpf, double gross, double comission)
    {
        this.name = name;
        this.cpf = cpf;
        this.gross = gross;
        this.comission = comission;
    }

    public String getName()
    {
        return name;
    }
    public String getCpf()
    {
        return cpf;
    }
    public double getGross()
    {
        return gross;
    }
    public double getComission()
    {
        return comission;
    }
    public void setGross(double gross)
    {
        if (gross > 0)
            this.gross = gross;
        else
            throw new IllegalArgumentException("gross tem que ser maior q zero");
    }
    public void setComission(double comission)
    {
        if (comission > 0 && comission < 1)
            this.comission = comission;
        else
            throw new IllegalArgumentException("comission tem que estar entre 0 e 1");
    }
    public double earnings()
    {
        return comission * gross;
    }
    @Override //sobrescreve o método toString da superclasse padrão do java
    public String toString()
    {
        return String.format("%s: %s  %n %s: %s %n %s: %f %f", "nome", getName(), "cpf", getCpf(), "venda e comissao", getGross(), getComission());
    }
}