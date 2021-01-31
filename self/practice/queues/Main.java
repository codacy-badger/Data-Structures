package queues;

public class Main {

  /**
   * Main method.
   */
  public static void main(String[] args) {
    Queue queue = new Queue();

    System.out.print("\033\143");
    System.out.println("Queues.");
    queue.enqueue(5);
    queue.enqueue(3);
    queue.enqueue(2);
    queue.enqueue(0);
    queue.display();
    System.out.printf("Queue size: %d\n", queue.getSize());
    System.out.printf("Queue's front: %d\n", queue.peek());

    System.out.println("\nDequeued.");
    queue.dequeue();
    queue.display();
    System.out.printf("Queue size: %d\n", queue.getSize());
    System.out.printf("Queue's front: %d\n", queue.peek());
  }
}
