#ifndef BASIC_VECTOR_H
#define BASIC_VECTOR_H

#include <iostream>
#include <stdexcept>
#include <cmath>

/*Method/Function/Constructor*/
//Input: None
//Returns, size_t: The value of the largest number of elements that can be stored in this vector before the vector overflows the memory space.
//Description: Returns the maximum number of elements that the vector can hold before overflowing the memory space.
//Implementation: Uses the formula provided in the assignment instructions to calculate the maximum size that the vector can store before overflowing.

template <typename T>
class basic_vector
{
    // This object will attempt to recreate the basic data structure of a Vector
    // The key aspects of a vector is that it can store data in a linear array while dynamically resizing itself when at capacity
    // we are using T as a template data type, meaning this variable can be of any type
private:
    T *data_;
    size_t size_;
    size_t capacity_;

public:
    /*Constructors*/
    // Input: None
    // Description: Constructs a vector with a default capacity of 1.
    // Implementation: Initializes size and capacity to 0 and 1 respectively, and allocates memory for data_.
    basic_vector()
    {
        // The capacity of the vector defaults to 1.
        size_ = 0;
        capacity_ = 1;
        if(capacity() > max_size()){
            capacity_ = max_size();
        }
        data_ = new T[capacity_];
    }

    // Input, size_t: The capacity of the vector.
    // Description: Constructs a vector with the specified capacity.
    // Default = None
    // Implementation: Sets the capacity to the provided value and initializes size to 0. Allocates memory for data_ based on the provided capacity.
    basic_vector(size_t in_capacity)
    {
        // Set the capacity to this value.
        capacity_ = in_capacity;
        size_ = 0;
        if(capacity() > max_size()){
            capacity_ = max_size();
        }
        data_ = new T[capacity_];
    }

    // Input, const basic_vector&: Another vector to be copied.
    // Description: Constructs a vector by copying the elements of another vector.
    // Implementation: Copies the capacity, size, and data of the provided vector to the new vector.
    basic_vector(const basic_vector &rhs)
    {
        capacity_ = rhs.capacity();
        if(capacity() > max_size()){
            capacity_ = max_size();
        }
        size_ = rhs.size();
        data_ = new T[capacity_];
        T *otherData = rhs.data();
        for (size_t i = 0; i < size(); i++)
        {
            data_[i] = otherData[i];
        }
    }
    
    // Input, const basic_vector&: Another vector to be copied.
    // Returns: None
    // Description: Assigns the elements of another vector to this vector.
    // Implementation: Similar to the copy constructor, but assigns values to an existing vector instead of creating a new one.
    basic_vector &operator=(const basic_vector &rhs)
    {
        capacity_ = rhs.capacity();
        if(capacity() > max_size()){
            capacity_ = max_size();
        }
        size_ = rhs.size();
        data_ = new T[capacity_];
        T otherData = rhs.data();
        for (size_t i = 0; i < size(); i++)
        {
            data_[i] = otherData[i];
        }
    }

    /*Methods*/
    // Input: None
    // Returns, size_t: The current size of stored data.
    // Description: Returns the current number of elements stored in the vector.
    // Implementation: Returns the size_ member variable.
    size_t size() const
    {
        return size_;
    }

    // Input: None
    // Returns, size_t: The maximum number of elements that can be stored in the vector.
    // Description: Returns the maximum number of elements that the vector can hold before overflowing the memory space.
    // Implementation: Uses the formula provided in the assignment instructions to calculate the maximum size that the vector can store before overflowing.
    size_t max_size() const
    {
        return (pow(2, 32)/sizeof(T)) -1;
    }

    // Input: None
    // Returns, size_t: The capacity of the vector.
    // Description: Returns the capacity of the vector, which is the maximum number of elements it can hold without reallocation.
    // Implementation: Returns the capacity_ member variable.
    size_t capacity() const
    {
        return capacity_;
    }

    // Input, size_t: The new size of the vector.
    // Returns: None
    // Description: Resizes the vector to contain the specified number of elements.
    // Implementation: If the new size is less than the current capacity, adjusts the size only. If the new size exceeds the capacity, reallocates memory for the vector.
    void resize(size_t n)
    {
        // no change to capacity
        if (n < capacity())
        {
            // only change size stuff
            if (n > size())
            {
                for (size_t i = size(); i < n; i++)
                {
                    if constexpr (std::is_fundamental_v<T>)
                    {
                        // fundamental types, set the value to 0
                        push_back(T());
                    }
                    else
                    {
                        // non-fundamental types, use default construction
                        push_back(T());
                    }
                }
            }
            else
            {
                for (size_t i = size(); i >= n; i--)
                {
                    pop_back();
                }
            }
            // need to change capacity
        }
        else
        {
            // Create a new vector
            capacity_ = n;
            if(capacity() > max_size()){
                capacity_ = max_size();
            }
            T *resizedVector = new T[capacity_];
            for (size_t i = 0; i < size(); i++)
            {
                resizedVector[i] = data_[i];
            }

            delete[] data_;
            data_ = resizedVector;
            size_ = n;
        }
    }

    //Input, size_t: The new size of the vector.
    //Input, T: The value to fill the new elements with.
    //Default = None
    //Returns: None
    //Throws: None
    //Description: Resizes the vector to contain 'n' elements. If 'n' is less than the current size, the vector is reduced to its first 'n' elements. If 'n' is greater than the current size, additional elements are appended with value 'val'. If 'n' exceeds the current capacity, a new vector is created and elements are copied to it.
    //Implementation: The method first checks if 'n' is less than the current capacity. If so, it adjusts the size of the vector without changing its capacity. If 'n' is greater than the current capacity, a new vector is created with size 'n'. Elements from the old vector are copied to the new one, and additional elements are filled with 'val'. Finally, the old vector is deallocated, and the new vector becomes the resized vector.
    void resize(size_t n, T val)
    {
        // no change to capacity
        if (n < capacity())
        {
            // only change size stuff
            if (n > size())
            {
                for (size_t i = size(); i < n; i++)
                {
                    if constexpr (std::is_fundamental_v<T>)
                    {
                        // fundamental types, set the value to 0
                        push_back(T(val));
                    }
                    else
                    {
                        // non-fundamental types, use default construction
                        push_back(T(val));
                    }
                }
            }
            else
            {
                for (size_t i = size(); i >= n; i--)
                {
                    pop_back();
                }
            }
            // need to change capacity
        }
        else
        {
            // Create a new vector
            capacity_ = n;
            if(capacity() > max_size()){
                capacity_ = max_size();
            }
            T *resizedVector = new T[capacity_];
            for (size_t i = 0; i < n; i++)
            {
                if (i < size())
                {
                    resizedVector[i] = data_[i];
                }
                else
                {
                    push_back(T(val));
                }
            }

            delete[] data_;
            data_ = resizedVector;
            size_ = n;
        }
    }

    // Input: None
    // Returns: bool: True if the vector is empty, false otherwise.
    // Description: Checks if the vector is empty (contains no elements).
    // Implementation: Compares the size_ member variable to 0 and returns true if it is 0, false otherwise.
    bool empty()
    {
        size_t zero = 0;
        if (size() == zero)
        {
            // no data is stored
            return true;
        }
        else
        {
            // there is data is stored
            return false;
        }
    }

    // Input, size_t: The new capacity of the vector.
    // Returns: None
    // Description: Reserves memory for at least the specified number of elements.
    // Implementation: Reallocates memory for the vector if the specified capacity is greater than the current capacity.
    void reserve(size_t n)
    {
        if (n > capacity_)
        {
            capacity_ = n;
            if(capacity() > max_size()){
                capacity_ = max_size();
            }
            T *newData = new T[capacity_];
            for (size_t i = 0; i < size(); ++i)
            {
                newData[i] = data_[i];
            }

            // Deallocate old memory
            delete[] data_;

            // Update data pointer and capacity
            data_ = newData;
        }
    }

    // Input: None
    // Returns: None
    // Description: Shrinks the capacity of the vector to fit its size.
    // Implementation: Reallocates memory for the vector to match its size.
    void shrink_to_fit()
    {
        if (capacity() > size())
        {
            T *resizedVector = new T[size()];
            for (size_t i = 0; i < size(); i++)
            {
                resizedVector[i] = data_[i];
            }
            delete[] data_;
            data_ = resizedVector;
            capacity_ = size();
            if(capacity() > max_size()){
                capacity_ = max_size();
            }
        }
    }

    // Input, size_t: The index of the element to access.
    // Returns: T&: A reference to the element at the specified index.
    // Description: Accesses the element at the specified index in the vector.
    // Implementation: Returns a reference to the element at the specified index using the at() method.
    T &operator[](size_t n)
    {
        // Accesses the value stored at index n
        return at(n);
        // !This does not throw an exception!
    }

    // Input, size_t: The index of the element to access.
    // Returns: T&: A reference to the element at the specified index.
    // Throws std::out_of_range: If the specified index is out of bounds.
    // Description: Accesses the element at the specified index in the vector, with bounds checking.
    // Implementation: Similar to the operator[], but throws an exception if the index is out of bounds.
    T &at(size_t n)
    {
        // Acts like operator[]
        // Throws a range_error when n is out of bounds
        if (n > size())
        {
            throw std::out_of_range("Index is out of bounds");
        }
        else
        {
            return data_[n];
        }
    }

    // Input: None
    // Returns: T&: A reference to the first element in the vector.
    // Description: Returns a reference to the first element in the vector.
    // Implementation: Calls the at() method with an index of 0 to access the first element.
    T &front()
    {
        // Returns a reference to the first element in the vector
        return at(0);
    }

    // Input: None
    // Returns: T&: A reference to the last element in the vector.
    // Description: Returns a reference to the last element in the vector.
    // Implementation: Calls the at() method with an index of size() - 1 to access the last element.
    T &back()
    {
        // Returns a reference to the last element in the vector
        return at(size() - 1);
    }

    // Input: None
    // Returns, T*: A pointer to the underlying array storing the elements of the vector.
    // Description: Returns a pointer to the underlying array storing the elements of the vector.
    // Implementation: Returns the data_ member variable.
    T *data() const
    {
        // Returns the pointer to the data array.
        return data_;
    }

    // Input, const T&: The value to be added to the end of the vector.
    // Returns: None
    // Throws: None
    // Description: Puts the element val onto the end of the vector.
    // Implementation: This method first checks if the current size of the vector is less than its capacity. If so, it assigns the value to the last position in the data array and increments the size. If the size exceeds the capacity, it doubles the capacity by calling the reserve method recursively and then adds the value.
    void push_back(const T &val)
    {
        // Puts the element val onto the end of the vector
        if (size() < capacity())
        {
            data_[size()] = val;
            size_ += 1;
        }
        else
        {
            reserve(capacity_ * 2);
            push_back(val);
        }
    }

// Returns: None
// Throws: None
// Description: Removes the last element from the vector.
// Implementation: This method decreases the size of the vector by one if the size is greater than zero. If the type T requires cleanup (non-trivial destructible), it deletes the last element if it's dynamically allocated.
    void pop_back()
    {
        size_t zero = 0;
        if (size() > zero)
        {
            size_ -= 1; // Decrease the size of the vector

            // If the type T requires cleanup, (if its not a primitive)
            if constexpr (!std::is_trivially_destructible_v<T>)
            {
                delete data_[size()]; // Delete the last element if it's dynamically allocated
            }
        }
    }

    // Input, basic_vector&: The vector to swap contents with.
    // Returns: None
    // Throws: None
    // Description: Swaps the contents of the vector with another vector.
    // Implementation: This method swaps the data pointers, sizes, and capacities between the two vectors.
    void swap(basic_vector &other)
    {
        // Swap the contents of the other vector with your vector
        // Remember how pointers work and update the required information for the vectors accordingly (size and capacity).

        // Swap data pointers
        T *temp_data = data_;
        data_ = other.data_;
        other.data_ = temp_data;

        // Swap sizes
        size_t temp_size = size_;
        size_ = other.size_;
        other.size_ = temp_size;

        // Swap capacities
        size_t temp_capacity = capacity_;
        
        
        capacity_ = other.capacity_;
        if(capacity() > max_size()){
            capacity_ = max_size();
        }
        other.capacity_ = temp_capacity;
        if(other.capacity() > other.max_size()){
            other.capacity_ = other.max_size();
        }
    }

    // Returns: None
    // Throws: None
    // Description: Removes all elements from the vector and sets the size to zero.
    // Implementation: This method iterates through the elements of the vector and deletes each element if the type T requires cleanup. It then deallocates the entire data array and sets the size to zero.
    void clear()
    {
        // Empties the array of all values and sets the size to 0.
        for (size_t i = 0; i < size(); i++)
        {
            if constexpr (!std::is_trivially_destructible_v<T>)
            {
                delete data_[i]; // Delete the last element if it's dynamically allocated
            }
        }
        delete[] data_;
        size_ = 0;
    }

    // Input: None
    // Returns: None
    // Throws: None
    // Description: Prints the size, capacity, and elements of the vector to the standard output.

    // Implementation: This method retrieves the size, capacity, and data array of the vector. It then iterates through the elements of the vector and prints them along with commas to separate them. Finally, it prints the size and capacity of the vector.
    void print()
    {
        std::cout << "size: " << size() << " capacity: " << capacity() << std::endl;
        std::cout << "[ ";
        T *myData = data();
        for (size_t i = 0; i < size(); i++)
        {
            if (i != size() - 1)
            {
                std::cout << myData[i] << " , ";
            }
            else
            {
                std::cout << myData[i];
            }
        }
        std::cout << " ]" << std::endl;
        std::cout << std::endl;
    }
};

#endif // BASIC_VECTOR_H
