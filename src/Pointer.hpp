#ifndef __MARS2D_POINTER_HPP__
#define __MARS2D_POINTER_HPP__

namespace mars2d {
    // reference counter class used by the smart pointer to count refs
    class RefCounter {
    public:
        RefCounter() { count = 0; }
        void inc() { count++; }
        int dec() { return --count; }
    private:
        int count;
    };
    
    template <class Type> class Pointer {
    public:
        Pointer() {
            // null pointer
            data = 0;
            counter = new RefCounter();
            counter->inc();
        }
        Pointer(Type* rawPointer) {
            // the first pointer
            data = rawPointer;
            counter = new RefCounter();
            counter->inc();
        }
        Pointer(const Pointer<Type>& ptr) {
            data = ptr.data;
            counter = ptr.counter;
            counter->inc();
        }
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
        Pointer<Type>& operator=(const Pointer<Type>& ptr) {
            // avoid self assignment
            if (this != &ptr) {
                // dec/frees this pointer
                if (counter->dec() == 0) {
                    delete data;
                    delete counter;
                }
                
                // copies the other ptr to this
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