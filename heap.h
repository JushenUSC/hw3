#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() {};

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  //heapify
  std::vector<T> heap_;
  int arity_;
  PComparator comp_;
  void heapifyDown(int heapifyStartIndex);
  void heapifyUp(int heapifyStartIndex);
};

template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(int heapifyStartIndex) {
	int greaterPriorityChild = heapifyStartIndex;
	for (int i = 1; i <= arity_ && (heapifyStartIndex * arity_ + i) < size(); i++) {
		//i will increment up to the point where we have gone through all child elements or index goes beyond vector's size
		//notice indexing depends on arity_ (number of max child elements per node)
		int child = heapifyStartIndex * arity_ + i;
		//if its true then we make a swap...
		if (comp_(heap_[child], heap_[greaterPriorityChild])) {
			greaterPriorityChild = child;
		}

	}
	if (heapifyStartIndex != greaterPriorityChild) {
		std::swap(heap_[heapifyStartIndex], heap_[greaterPriorityChild]);
		heapifyDown(greaterPriorityChild);
	}
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(int heapifyStartIndex) {
	if (heapifyStartIndex == 0) {
		return;
	}
	int parentIndex = (heapifyStartIndex-1)/arity_;
	if (comp_(heap_[heapifyStartIndex], heap_[parentIndex])) {
		std::swap(heap_[heapifyStartIndex], heap_[parentIndex]);
		heapifyUp(parentIndex);
	}
}

// Add implementation of member functions here
template <typename T, typename PComparator> 
Heap<T, PComparator>::Heap(int m, PComparator c) {
	arity_ = m;
	comp_ = c;
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const &Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
	throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
	throw std::underflow_error("Heap is empty");
  }
  //assign the last element to the highest priority element
  heap_[0] = heap_[size()-1];
  //remove the duplicated last element
  heap_.pop_back();
  //heapify!
  heapifyDown(0);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
	heap_.push_back(item);
	heapifyUp(heap_.size()-1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
	if (heap_.size() == 0) {
		return true;
	}
	return false;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
	return heap_.size();
}


#endif

