import java.util.Random;
public class sorting {
    
    public static void selectionSort(int[] v){
        for (int i=0; i < v.length-1; i++){
            int indicie_menor = i;

            for (int k = i+1; k < v.length; k++){

                if (v[k] < v[indicie_menor]){
                    indicie_menor = k;
                }
            }
            if (i != indicie_menor){
                int tmp = v[i];
                v[i] = v[indicie_menor];
                v[indicie_menor] = tmp;
            }
        }
    }

    //#region DEFINING RECURSIVE SORTING
    public static int obter_menor_indicie(int[] v, int i){
        if (i == v.length-1) return i;
        int indicie_menor_temp = obter_menor_indicie(v, i+1);
        if (v[indicie_menor_temp] < v[i]) return indicie_menor_temp;
        else return i;
    }
    public static void selectionSort_recursive(int[] v, int i){
        if (i == v.length-1) return;
        
        int indicie_menor = obter_menor_indicie(v, i);
        if (i != indicie_menor){
            int tmp = v[i];
            v[i] = v[indicie_menor];
            v[indicie_menor] = tmp;
        }
        selectionSort_recursive(v, i+1);
    }
    public static void selectionSort_auxiliar(int[] v){
        selectionSort_recursive(v, 0);
    }
    //#endregion

    public static void imprimir(int[] v){

        for (int i=0; i < v.length; i++){
            System.out.print(v[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args){

        Random rnd = new Random(); //criar vetor aleatorio
        int[] v = new int[20];
        for (int i=0; i < v.length; i++){
            v[i] = rnd.nextInt(50);
        }

        imprimir(v);
        selectionSort_auxiliar(v);
        imprimir(v);

    }

}
