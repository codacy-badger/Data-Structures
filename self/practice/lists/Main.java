package lists;

import java.util.function.Consumer;

public class Main {

  /**
   * main function.
   */
  public static void main(String[] args) {
    System.out.print("\033\143");
    System.out.println("Linked List\n");

    LinkedList list = new LinkedList();
    Consumer<Integer> append = v -> list.append(v);
    Consumer<Integer> push = v -> list.push(v);

    list.addMany(append, 1, 2, 5);
    list.push(0); 
    list.display();

    list.insertAt(3, 4);
    list.detach();
    list.display();

    list.insertAfter(2, 3);
    list.pop();
    list.display();

    list.addMany(push, 0, -1, -2);
    list.display();
    System.out.printf("Linked list len: %d\n", list.getLength());

    int position = 2;
    int valueExtracted = 0;
    try {
      valueExtracted = list.getNodeByPosition(position);
    } catch (Exception e) {
      System.out.println(e);
      System.exit(1);
    }
    System.out.printf("\nElement in position[%d]: %d\n", position, valueExtracted);
  }
}
