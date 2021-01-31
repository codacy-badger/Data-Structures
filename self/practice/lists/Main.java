package lists;

public class Main {

  /**
   * main function.
   */
  public static void main(String[] args) {
    System.out.print("\033\143");
    System.out.println("Linked List\n");

    List list = new List();
    list.append(1); // 1 -> NULL
    list.append(2); // 1 -> 2 -> NULL
    list.append(5); // 1 -> 2 -> 5 -> NULL
    list.display();

    list.push(0); // 0 -> 1 -> 2 -> 5 -> NULL
    list.insertAt(3, 4); // 0 -> 1 -> 2 -> 4 -> 5 -> NULL
    list.detach(); // 0 -> 1 -> 2 -> 4 -> NULL
    list.insertAfter(2, 3); // 0 -> 1 -> 2 -> 3-> 4 -> NULL
    list.pop(); // 1 -> 2 -> 3-> 4 -> NULL
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
