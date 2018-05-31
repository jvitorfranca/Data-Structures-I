//basic algorith using queue standard library

#include<iostream> //std::cout and std::cin and std::endl
#include<queue> //std::queue

int main(int argc, char const *argv[]) {

  //in this first part we're using some functions such as push, pop, empty and pop.

  std::queue<int> myQueue;

  int myInt;

  std::cout << "Please, enter the integers you want to put in your queue (enter 0 to end)\n";

  do {

    std::cin >> myInt;
    myQueue.push(myInt);

  } while (myInt);

  std::cout << "myQueue contains: \n";

  while (!myQueue.empty()){

    std::cout << ' ' << myQueue.front();
    myQueue.pop();

  }

  std::cout << "\n";

  //in this second part we're a learning how to use swap function

  std::queue<int> queueA;
  std::queue<int> queueB;

  queueA.push(1);
  queueA.push(2);
  queueA.push(3);

  queueB.push(4);
  queueB.push(5);

  queueA.swap(queueB);

  std::cout << "size of queueA: " << queueA.size() << std::endl;
  std::cout << "size of queueB: " << queueB.size() << std::endl;

  return 0;
}
