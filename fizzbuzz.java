public class FizzBuzz{

     public static void main(String []args){
         int low = -50, high = 50;
         for (int i = low; i <= high; i++) {
             String test = "";
             test += (i % 3) == 0 ? "Fizz" : "";
             test += (i % 5) == 0 ? "Buzz" : "";
             System.out.println(!test.isEmpty() ? test: i);
         }
     }
}
