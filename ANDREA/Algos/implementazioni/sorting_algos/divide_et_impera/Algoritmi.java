import java.util.Arrays;

public class Algoritmi {

    /*
     * Merge Sort:
     * spezzo l'array in due subarrays: left e right.
     * Richiamo ricorsivamente sia per left che per right, fino ad arrivare a quando si hanno array lunghi 1,
     * In seguito la funzione ritornerà, procedendo con l'esecuzione del resto della funzione.
     * Chiama merge per riempire l'array originale con il minore tra left e right, che sono ora ordinati.
     */
    public void mergeSort(int[] array) {
        if (array.length < 2) {
            return;
        }
        
        int mid = array.length / 2;
        int[] left = Arrays.copyOfRange(array, 0, mid);
        int[] right = Arrays.copyOfRange(array, mid, array.length);
        
        mergeSort(left);
        mergeSort(right);
        
        merge(array, left, right);
    }

    public void quickSort(int[] array, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(array, low, high);
            quickSort(array, low, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, high);
        }
    }
    
    private int partition(int[] array, int low, int high) {
        int pivot = array[high]; // Pivot scelto come ultimo elemento
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (array[j] < pivot) {
                i++;
                swap(array, i, j);
            }
        }
        
        swap(array, i + 1, high);
        return i + 1;
    }
    
    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    /*
     * Combina gli array ordinati left e right.
     * Per farlo itera contemporaneamente su entrambi, confrontando i valori così trovati
     * e riempiendo l'array originale con il minore tra i due.
     */
    private void merge(int[] array, int[] left, int[] right) {
        int i = 0, j = 0, k = 0;
        
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }
        }
        
        while (i < left.length) {
            array[k++] = left[i++];
        }
        
        while (j < right.length) {
            array[k++] = right[j++];
        }
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
        int[] B = A.clone();

        algos.PrintArray(A);
        algos.mergeSort(A);
        algos.PrintArray(A);
        
        algos.PrintArray(B);
        algos.quickSort(B, 0, A.length - 1);
        algos.PrintArray(B);
    }
}
