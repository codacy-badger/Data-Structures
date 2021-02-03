package lists;

public class DoublyLinkedList {

  private int length = 0;
  private Node head;
  private Node tail;

  private class Node {
    public int value;
    public Node next;
    public Node last;

    public Node(int value) {
      this.value = value;
    }
  }

  /**
   * Add a node at the beginning of the doubly linked list.
   */
  public void push(int element) {
    Node node = new Node(element);

    if (head == null) {
      tail = node;
    } else {
      head.last = node;
      node.next = head;
    }
    head = node;
    length++;
  }

  /**
   * Add a node at the end of the doubly linked list.
   */
  public void append(int element) {
    Node node = new Node(element);

    if (head == null) {
      head = node;
    } else {
      tail.next = node;
      node.last = tail;
    }
    tail = node;
    length++;
  }

  /**
   * Delete the head node of a linked list.
   */
  public void pop() {
    if (head != null) {
      Node delete = head;
      head = head.next;
      head.last = null;
      delete.next = null;
      length--;
    }
  }

  /**
   * Delete the tail of a double linked list.
   */
  public void detach() {
    if (tail != null) {
      Node delete = tail;
      tail = tail.last;
      tail.next = null;
      delete.last = null;
      length--;
    }
  }

  public int getLength() {
    return length;
  }

  /**
   * Display a linked list.
   */
  public void display() {
    Node current = head;

    System.out.print("NULL <- ");
    while (current != null) {
      System.out.printf("%d", current.value);
      if (current.next != null) {
        System.out.print(" <-> ");
      }
      current = current.next;
    }
    System.out.println(" -> NULL");
  }

}
