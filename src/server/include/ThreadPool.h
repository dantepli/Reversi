
#ifndef REVERSI_THREADPOOL_H
#define REVERSI_THREADPOOL_H

#include "Task.h"
#include <queue>
#include <pthread.h>
#include <unistd.h>

using namespace std;
class ThreadPool {
 public:
  /**
   * C'tor.
   * @param threadsNum - number of threads in the pool.
   */
  ThreadPool(int threadsNum);
  /**
   * adds a task to the pool.
   * @param task - a task to be added.
   */
  void addTask(Task *task);
  /**
   * terminates the thread pool.
   */
  void terminate();
  /**
   * D'tor. deletes the threads.
   */
  virtual ~ThreadPool();
 private:
  queue<Task *> tasksQueue;
  pthread_t *threads;
  void executeTasks();
  bool stopped;
  pthread_mutex_t lock;
  static void *execute(void *arg);
};

#endif //REVERSI_THREADPOOL_H
