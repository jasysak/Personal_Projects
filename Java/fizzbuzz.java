/*   A simple FizzBuzz solution in Java
     if number is / 3 print Fizz
     if number is / 5 print Buzz
     if number is / 3 and 5 both print FizzBuzz
     else print the number
     This one is better than my somewhat poor python solution
     Less repitition here...still not a great piece of code but it works
*/
    
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
