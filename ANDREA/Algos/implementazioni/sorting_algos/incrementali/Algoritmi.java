public class Algoritmi {
    /*
     * Selection Sort:
     * prendendo in input un array A, swappa un elemento alla posizione i-esima con un altro minore di esso.
     * L'algoritmo esegue ogni volta 2 cicli iterativi, sia che l'elemento alla posizione i-esima debba essere swappato che nel caso opposto.
     * Chiamando questo algoritmo f(n), potremmo quindi dire che f(n) = O(n^2).
     * @param A array di interi da sortare in ordine crescente
     */
    public void SelectionSort(int A[]){
        int m;
        for(int i = 0; i < A.length; i++){
            m = Min(A, i);
            if (m != i)
                Swap(A,i,m);
        }
    } 

    /*
     * Insertion Sort:
     * prendendo in input un array A e partendo dalla seconda posizione di questo,
     * procede ad iterare su tutti gli elementi antecedenti a quello corrente (A[i]) e swappa quando
     * A[i] > A[i - 1].
     * Questo algoritmo risulta più stabile del Selection Sort in quanto il ciclo nested potrebbe essere
     * saltato completamente, nel caso in cui le corrette condizioni vengano verificate.
     * Nel caso migliore si eseguità quindi solamente un ciclo for (quello più esterno): f(n) = O(n).
     * Nel caso peggiore si eseguiranno entrambi i cicli for per una complessità totale pari a O(n^2).
     */
    public void InsertionSort(int A[]){
        for (int i = 1; i < A.length; i++){
            int j = i;
            while (j > 0 && A[j] < A[j - 1]){
                Swap(A, j, j-1);
                j = j - 1;
            }
        }
    }

    private int Min(int A[], int i){
        for (int j = i + 1; j < A.length; j++)
            if (A[j] < A[i])
                i = j;
        return i;
    }

    private void Swap(int A[], int i, int j){
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }

    public void PrintArray(int[] A){
        for(int i = 0; i < A.length; i++){
            System.out.print(A[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args){
        Algoritmi algo = new Algoritmi();
        int[] A = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        int[] B = A.clone();    // fare B = A renderà B un puntatore ad A, perché di base passa valori per reference
        
        algo.PrintArray(A);
        algo.SelectionSort(A);
        algo.PrintArray(A);

        algo.PrintArray(B);
        algo.InsertionSort(B);
        algo.PrintArray(B);
    }

}
