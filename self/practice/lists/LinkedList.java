package lists;

import java.util.function.Consumer;

public class LinkedList {

  private Node head = null;
  private int length;

  private class Node {
    public int value;
    public Node next = null;

    public Node(int value) {
      this.value = value;
    }
  }

  /**
   * Add a node at the beginning of the linked list.
   */
  public void push(int value) {
    Node node = new Node(value);
    node.next = head;
    head = node;
    length++;
  }

  /**
   * Add a node at the end of the linked list.
   */
  public void append(int value) {
    if (head == null) {
      push(value);
      return;
    }

    Node node = new Node(value);
    Node current = head;

    while (current.next != null) {
      current = current.next;
    }
    current.next = node;
    length++;
  }

  /**
   * Add many nodes to a linked list entering a method such as append or push.
   */
  public void addMany(Consumer<Integer> method, int...values) {
    for (int value: values) {
      method.accept(value);
    }
  }

  /**
   * Insert a new node after a given position.
   */
  public void insertAfter(int position, int value) {
    if (head == null) {
      push(value);
      return;
    } else if (position >= getLength()) {
      return;
    }

    Node node = new Node(value);
    Node current = head;
    int currentPosition = 0;

    while (currentPosition < position && current.next != null) {
      current = current.next;
      currentPosition++;
    }
    node.next = current.next;
    current.next = node;
    length++;

  }

  /**
   * Make a new node place a specific position in the linked list.
   */
  public void insertAt(int position, int value) {
    if (position == 0) {
      push(value);
    } else if (position < getLength()) {
      insertAfter(position - 1, value);
    }
  }

  /**
   * Delete the first element of a linked list.
   */
  public void pop() {
    if (head != null) {
      Node delete = head;
      head = head.next;
      delete.next = null;
      length--;
    }
  }

  /**
   * Delete the last element of a linked list.
   */
  public void detach() {
    if (head == null) {
      return;
    } else if (head.next == null) {
      pop();
      return;
    }

    Node current = head;
    while (current.next.next != null) {
      current = current.next;
    }
    Node delete = current.next;
    current.next = null;
    delete.next = null;
    length--;
  }

  /**
   * Delete a node in a specific position of the linked list.
   */
  public void deleteAt(int position) {
    if (head == null) {
      return;
    } else if (position == 0) {
      pop();
      return;
    }

    Node current = head;
    while (current.next.next != null) {
      current = current.next;
    }
    Node delete = current.next;
    current.next = null;
    delete.next = null;
    length--;
  }

  /**
   * Get a specific node value from a given position.
   */
  public int getNodeByPosition(int position) throws Exception {
    if (position >= getLength()) {
      throw new Exception("Position out of range.");
    }

    Node current = head;
    int currentPosition = 0;

    while (currentPosition < position && current.next != null) {
      current = current.next;
      currentPosition++;
    }

    return current.value;
  }

  public int getLength() {
    return length;
  }

  /**
   * Display a linked list.
   */
  public void display() {
    Node current = head;

    while (current != null) {
      System.out.printf("%d -> ", current.value);
      current = current.next;
    }
    System.out.println("NULL");
  }
}
