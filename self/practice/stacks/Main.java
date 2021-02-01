package stacks;

public class Main {

  /**
   * Main method.
   */
  public static void main(String[] args) {
    Stack stack = new Stack();

    System.out.print("\033\143");
    System.out.println("Queue.");
    stack.push(5);
    stack.push(1);
    stack.push(0);
    stack.push(2);
    stack.push(8);
    stack.display();
    System.out.printf("Queue top: [%d]\n", stack.peek());
    System.out.printf("Queue len: %d\n", stack.getSize());
    
    System.out.println("\nPopped queue.");
    stack.pop();
    stack.display();
    System.out.printf("Queue top: [%d]\n", stack.peek());
    System.out.printf("Queue len: %d\n", stack.getSize());
  }

}
