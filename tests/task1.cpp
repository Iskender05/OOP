#include <iostream>
#include <stdexcept>
#include <vector>

// Исключение, бросаемое при попытке добавить элемент в полную очередь в режиме форсирования false
class QueueFullException : public std::exception {
public:
    QueueFullException(size_t queueSize, const std::string& value)
        : queueSize(queueSize), value(value) {}

    const char* what() const noexcept override {
        return "Queue is full";
    }

    size_t getQueueSize() const {
        return queueSize;
    }

    const std::string& getValue() const {
        return value;
    }

private:
    size_t queueSize;
    std::string value;
};

template <size_t Size, typename T, bool ForceMode = true>
class LimitedQueue {
    std::vector<T> queue;

public:
    LimitedQueue(std::initializer_list<T> init) {
        if (init.size() > Size) {
            auto start = init.end() - Size;
            queue.insert(queue.end(), start, init.end());
        } else {
            queue = init;
        }
    }

    void push_back(const T& value) {
        if (queue.size() == Size) {
            if (ForceMode) {
                queue.erase(queue.begin());
            } else {
                throw QueueFullException(Size, std::to_string(value));
            }
        }
        queue.push_back(value);
    }

    T pop_front() {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }
        T frontValue = queue.front();
        queue.erase(queue.begin());
        return frontValue;
    }

    T front() const {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return queue.front();
    }

    bool empty() const {
        return queue.empty();
    }

    bool full() const {
        return queue.size() == Size;
    }

    void clear() {
        queue.clear();
    }

    size_t size() const {
        return queue.size();
    }
};

int main() {
    try {
        LimitedQueue<3, int, false> queue = {1, 2};

        queue.push_back(3);
        std::cout << "Front: " << queue.front() << std::endl;
        std::cout << "Queue size: " << queue.size() << std::endl;

        std::cout << "Pop front: " << queue.pop_front() << std::endl;
        std::cout << "Queue size: " << queue.size() << std::endl;

        queue.push_back(4);
        queue.push_back(5);
        std::cout << "Front: " << queue.front() << std::endl;
        std::cout << "Queue size: " << queue.size() << std::endl;

        queue.push_back(6); // Will throw QueueFullException in ForceMode=false
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        if (const QueueFullException* qfe = dynamic_cast<const QueueFullException*>(&e)) {
            std::cerr << "Queue size: " << qfe->getQueueSize() << ", Attempted value: " << qfe->getValue() << std::endl;
        }
    }

    return 0;
}
