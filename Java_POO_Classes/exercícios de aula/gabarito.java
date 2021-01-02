/* Tudo comentado, pois não existem classes como Impressao, e afins. Código incompleto
########################################################

import java.util.ArrayList;
import java.util.Scanner;

public class ProgramaExpressao {
    
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        
        String entrada = scanner.nextLine();
        ArrayList expressaoSeparada = (separarCaracteres(entrada));
        

        Impressao impressao = new Impressao();
        impressao.imprimirResultado(calcular(expressaoSeparada));
    }
  
    private static ArrayList<String> separarCaracteres(String expressao){...23 linhas}
    
    private static Boolean isNum(String num){...8 linhas}
   
    private static int calcular(ArrayList<String> expressaoSeparada){
        OperacaoMatematica operacao = new OperacaoMatematica();
        
        //enquanto a quantidade de termos na expressao for diferente de 1
        while(expressaoSeparada.size() != 1){
            
            //percorre todos os termos da expressão
            for (int i = 0; i < expressaoSeparada.size(); i++) {
                
                //se for um operador
                if(!isNum(expressaoSeparada.get(i))){
                    
                    //caso seja um operador de * ou /
                    if(expressaoSeparada.get(i).equals("*") || expressaoSeparada.get(i).equals("/")){
                        
                        //faz o calculo de acordo com o operador correspondente
                        switch(expressaoSeparada.get(i)){
                            case "*":
                                //define o valor1 como o numeral antes do operador
                                operacao.setValor1(Integer.parseInt(expressaoSeparada.get(i-1)));
                                //define o valor2 como o numeral depois do operador
                                operacao.setValor2(Integer.parseInt(expressaoSeparada.get(i+1)));
                                operacao.executaOperacao(3);
                                
                                break;
                            case "/":
                                operacao.setValor1(Integer.parseInt(expressaoSeparada.get(i-1)));
                                operacao.setValor2(Integer.parseInt(expressaoSeparada.get(i+1)));
                                operacao.executaOperacao(4);
                                break; 
                        }
                        //calcula o resultado e substitui no index do operador anterior
                        expressaoSeparada.set(i, String.valueOf(operacao.getResultado()));
                        //remove os numeros usados na conta anterior
                        expressaoSeparada.remove(i+1);
                        expressaoSeparada.remove(i-1);
                        //esse break serve para que isso só seja feito uma vez, assim não preciso tratar casos onde há uma sequência de * ou /. Assim é mais fácil.
                        break;
                        
                    }
                    else{
                        //verifica se não tem nenhum operador prioritário
                        if(!(expressaoSeparada.contains("*") || expressaoSeparada.contains("/"))){
                            //enquanto não tiver apenas 1 elemento sobrando
                            while(expressaoSeparada.size() != 1){
                                //executa todas as operações remanescentes em ordem
                                switch(expressaoSeparada.get(i)){
                                    case "+":
                                    operacao.setValor1(Integer.parseInt(expressaoSeparada.get(i-1)));
                                    operacao.setValor2(Integer.parseInt(expressaoSeparada.get(i+1)));
                                    operacao.executaOperacao(1);
                                
                                     break;
                                case "-":
                                    operacao.setValor1(Integer.parseInt(expressaoSeparada.get(i-1)));
                                    operacao.setValor2(Integer.parseInt(expressaoSeparada.get(i+1)));
                                    operacao.executaOperacao(2);
                                    break; 
                                }
                                expressaoSeparada.set(i, String.valueOf(operacao.getResultado()));
                                expressaoSeparada.remove(i+1);
                                expressaoSeparada.remove(i-1);
                            }
                        }
                    }
                }
            }
        }
        
        return operacao.getResultado();
    }
}
*/