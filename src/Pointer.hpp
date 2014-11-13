#ifndef __MARSGAMEENGINE_POINTER_HPP__
#define __MARSGAMEENGINE_POINTER_HPP__

namespace MarsGE {
    /** \class RefCounter 
     * \brief Reference counter class used by the smart pointer to count refs
     * 
     * This class is used inside the Smart Pointer class to manage references for raw pointers.
     * 
     */
    class RefCounter {
    public:
        RefCounter() { count = 0; }
        void inc() { count++; }
        int dec() { return --count; }
    private:
        int count;
    };
    
    /** \class Pointer 
     * \brief Shared (ref counted) smart pointer used to wrap raw pointers
     * 
     */
    template <class Type> class Pointer {
    public:
        /// Null pointer constructor
        Pointer() {
            data = 0;
            counter = new RefCounter();
            counter->inc();
        }
        /**
         * \param rawPointer the raw pointer to be wrapped.
         * 
         */
        Pointer(Type* rawPointer) {
            // the first pointer
            data = rawPointer;
            counter = new RefCounter();
            counter->inc();
        }
        /**
         * \param ptr Pointer to be copied
         * 
         * Creates a copy of ptr, ie references the same raw pointer. When the are no more
         * references to the raw pointer, its finally freed.
         * 
         */
        Pointer(const Pointer<Type>& ptr) {
            data = ptr.data;
            counter = ptr.counter;
            counter->inc();
        }
        /**
         * Frees the raw pointer if there are no more references to it.
         * 
         */
        ~Pointer() {
            // if there are no refs, its time to free all
            if (counter->dec() == 0) {
                delete data;
                delete counter;
            }
        }
        Type& operator*() {
            return *data;
        }
        Type* operator->() {
            return data;
        }
        /**
         * operator= function; prevents self assignment
         * 
         */
        Pointer<Type>& operator=(const Pointer<Type>& ptr) {
            // avoid self assignment
            if (this != &ptr) {
                // dec/frees this pointer
                if (counter->dec() == 0) {
                    delete data;
                    delete counter;
                }
                
                // copies the other ptr data to this
                data = ptr.data;
                counter = ptr.counter;
                counter->inc();
            }
            return *this;
        }
    private:
        Type* data; // usual pointer
        RefCounter* counter;
    };
}

#endif