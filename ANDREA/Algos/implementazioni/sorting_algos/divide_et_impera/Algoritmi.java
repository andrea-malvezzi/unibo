public class Algoritmi {

    /*
     * Merge Sort:
     * 
     */
    public void MergeSort(int[] A, int p, int r){
        int q;
        if (p > r){
            q = Math.floorDiv(p + r, 2);
            MergeSort(A, p, q);
            MergeSort(A, q + 1, r);
            // ora A[p ... q] e A[q+1 ... r] sono ordinati
            Merge(A,p,q,r);
        }
    }

    /*
     * Combina gli array ordinati A[p ... q] e A[q + 1 ... r].
     * Per farlo prende l'indice di inizio delle due frammentazioni ed itera contemporaneamente su entrambi,
     * confrontando i valori così trovati e costruendo B con il minore tra i due.
     */
    private void Merge(int[] A, int p, int q, int r){
        int[] B = new int[r - p + 1];
        int i = p;              // index over A[p ... q]
        int j = q + 1;          // index over A[q+1 ... r]
        int k = 0;              // index over B
        while (i <= q && j <= r){
            // costruisco l'array con l'elemento minore tra i due correntemente presi in esame
            if (A[i] <= A[j]){
                B[k] = A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
            k++;
        }
        while(i <= q){
            B[k] = A[i];
            k++;
            i++;
        }
        while(j <= r){
            B[k] = A[j];
            k++;
            j++;
        }
        for (k = 1; k <= r - p + 1; k++)
            A[p + k - 1] = B[k];
    }
    
    public void PrintArray(int[] A){
        for(int i = 0; i < A.length; i++){
            System.out.print(A[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args){
        Algoritmi algos = new Algoritmi();
        int[] A = {9, 7, 4, 6, 3, 5, 1, 2, 10, 0};
        algos.PrintArray(A);
        // ???
        algos.MergeSort(A, 0, A.length);
        algos.PrintArray(A);
    }
}
