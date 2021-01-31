package queues;

public class Queue implements QueueInterface {

  private Node front;
  private Node back;
  private int length;

  private class Node {
    public int value;
    public Node next;

    public Node(int value) {
      this.value = value;
    }
  }

  /**
   * Add a new node to the queue.
   */
  @Override
  public void enqueue(int element) {
    Node node = new Node(element);

    if (front == null) {
      front = node;
    } else {
      back.next = node;
    }
    back = node;
    length++;
  }

  /**
   * Remove the front node from the queue.
   */
  @Override
  public void dequeue() {
    if (front == null) {
      return;
    }

    Node delete = front;
    front = front.next;
    delete.next = null;
    length--;

    if (front == null) {
      back = null;
    }
  }

  /**
   * Return the front node value.
   */
  @Override
  public Object peek() {
    if (front == null) {
      return null;
    }
    return front.value;
  }

  public int getSize() {
    return length;
  }

  /**
   * Display the value of every node in the queue.
   */
  public void display() {
    if (front == null) {
      System.out.println("Empty queue.");
      return;
    }

    Node current = front;

    while (current != null) {
      System.out.printf("| %d ", current.value);
      current = current.next;
    }
    System.out.println("|");
  }
}
