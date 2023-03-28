public class EmpregadoSalarioMensal extends Empregado
{
    // tem doas as variavies do empregado, basta acrescentar a especial
    private double salary;

    // criando o construtor
    public EmpregadoSalarioMensal(String name, String cpf, double gross, double comission, double salary)
    {
        // chama o construtor empregado, a superclasse
        super(name, cpf, gross, comission);
        this.salary = salary;


    }

    public void setSalary(double salary)
    {
        if (salary > 0)
            this.salary = salary;
        else
            throw new IllegalArgumentException("salario tem que ser maior q 0");
    }
    public double getSalary()
    {
        return salary;
    }

    @Override // sobrescrevendo a maneira de calcular os ganhos do empregado, visto q eh um pouco diferente
    public double earnings()
    {
        return salary + (comission*gross);
    }

    @Override //sobrescreve o método toString da superclasse padrão do java
    public String toString()
    {
        return String.format("%s: %s  %n %s: %s %n %s: %f %f %n %s: %f", "nome", getName(), "cpf", getCpf(), "venda e comissao", getGross(), getComission(), "salario:", getSalary());
    }

}