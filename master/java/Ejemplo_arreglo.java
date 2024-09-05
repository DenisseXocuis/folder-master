import java.util.Scanner;

public class Ejemplo_arreglo {
    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        //definicion del array y reserva memoria en la misma línea
        int[] x = new int[5];
        x[0] = 8; x[1] = 33; x[2] = 200; x[3] = 150; x[4] = 11;
        
        System.out.println("El array x tiene 5 elementos, ¿cuál de ellos quiere ver?");
        System.out.println("Introduzca un número del 0 al 4:");
        int index = sc.nextInt();
        System.out.print("El elemento que se encuentra en la posición" + index + "\n");
        System.out.println(" es el" + x[index] + "\n\n");
        
        // ejemplo 2
        
        double[] nota = new double[4];
        double suma = 0;
        
        System.out.println("Para calcular la nota media necesito saber la ");
        System.out.println("nota de cada uno de tus exámenes.");
        
        for(int i=0;i<4;i++)
        {
            System.out.println("Nota del exam n° " + (i+1) + ": ");
            nota[i] = sc.nextInt();
        }
        
        System.out.println("Tus notas son: ");
        for(int i=0; i<4;i++)
        {
            System.out.print(nota[i] + " ");
            suma += nota[i];
        }
        
        System.out.println("\nLa media es " + suma/4);
        
    }
    
}
