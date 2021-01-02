public class ContaCorrenteC {
    private String nome = "";
    private String cpf = "";
    private double saldo;
    
    public ContaCorrenteC(String nome, String cpf){
        this.nome = nome;
        this.cpf = cpf;
        this.saldo = 0;
    }
    public ContaCorrenteC(String nome, String cpf, double saldo){
        this.nome = nome;
        this.cpf = cpf;
        if (saldo >= 0){
            this.saldo = saldo;
        }
        else{
            this.saldo = 0.0;
        }
    }

    public double getSaldo(){
        return this.saldo;
    }

    public String getTitular(){
        return this.nome + ", " + this.cpf;
    }

    public void depositar(double quantia){
        if (quantia >= 0){
            if ((nome != "") && ( cpf != "")){
                this.saldo += quantia;
            }
        }
    }

    public void sacar(double quantia){
        if (quantia >= 0){
            if ((nome != "") && ( cpf != "")){
                double saldoAtual = this.getSaldo();
                if (quantia <= saldoAtual){
                    this.saldo -= quantia;
                }
            }
        }
    }

    public static void transferir(ContaCorrenteC de, ContaCorrenteC para, double quantia){
        if (quantia <= de.getSaldo()){
            de.sacar(quantia);
            para.depositar(quantia);
        }
    }

}
