package queues;

/**
 * Queue.
 */
public interface QueueInterface {

  void enqueue(int element);

  void dequeue();

  Object peek() throws Exception;
}
