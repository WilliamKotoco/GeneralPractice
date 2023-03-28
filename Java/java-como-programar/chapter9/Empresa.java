public class Empresa{
    public static void main (String[] args)
    {
        Empregado empregado = new Empregado("Zé xota", "3432434", 34234, 0.5);
        EmpregadoSalarioMensal empregadoFoda = new EmpregadoSalarioMensal("zé cu", "234234", 200, 0.3, 4000);


        System.out.println(empregado.toString());
       System.out.println(empregadoFoda.toString());
    }
}