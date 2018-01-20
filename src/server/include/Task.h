
#ifndef REVERSI_TASK_H
#define REVERSI_TASK_H

class Task {
 public:
  Task(void *(*func)(void *arg), void *arg) :
      func(func), arg(arg) {}
  void execute() {
    func(arg);
  }
  virtual ~Task() {}
 private:
  void *(*func)(void *arg);
  void *arg;
};

#endif //REVERSI_TASK_H
