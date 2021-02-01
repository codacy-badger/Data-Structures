package stacks;

/**
 * Stack.
 */
public class Stack implements StackInterface {

  private int length = 0;
  private Node top;

  private class Node {
    public int value;
    public Node next;

    public Node(int value) {
      this.value = value;
    }
  }

  /**
   * Add a new node to the stack.
   */
  @Override
  public void push(int element) {
    Node node = new Node(element);

    node.next = top;
    top = node;
    length++;
  }

  /**
   * Remove the front node from the stack.
   */
  @Override
  public void pop() {
    if (top == null) {
      return;
    }

    Node toPop = top;
    top = top.next;
    toPop.next = null;
    length--;
  }

  /**
   * Return the front node value.
   */
  @Override
  public Object peek() {
    return top.value;
  }

  public int getSize() {
    return length;
  }

  /**
   * Display the value of every node in the stack.
   */
  public void display() {
    Node current = top;

    while (current != null) {
      System.out.printf("%d -> ", current.value);
      current = current.next;
    }
    System.out.println("NULL");
  }
}
