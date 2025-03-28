1. ## vector 不能在遍历过程中删除元素，但是队列就可以，这是为什么

### **`vector`**​**​ 是连续存储的**​**动态数组**

* `vector` 在底层实现时，所有元素是 **连续存储** 在内存中的，类似于一个动态数组。
* 删除某个元素后，后面的元素需要 ​**向前移动**​，以保持连续存储。
* 但是如果仅仅使用`pop_back()`删除元素，则不会发生重新排列。而使用迭代器或者erase（）`则不被允许



### **`queue`**​**​ 是基于**​**链表**​**或环形缓冲区**

* `queue` 在大多数实现中 ​**不存储连续数据**​，通常基于 ​**链表**​**​（​​​**`std::list`**​**​）或者循环缓冲区（​**​​**`std::deque`**​**）进行管理。
* 这样，每次删除（`pop()`）时，不需要移动剩余元素，只需调整指针。
* 换句话说，队列只支持删除队尾元素，因此不会发生排列变化

### ​ ​**​**`queue`**​**​ 只允许 ​**​**FIFO**​**​ 操作

* `queue` 只允许 **​从前端（​​​**`front`**​​**）取出元素​​，并 **​从后端（​​​**`back`**​​**）插入元素​，所以删除操作不会影响未访问的元素
