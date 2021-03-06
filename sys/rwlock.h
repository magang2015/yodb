#ifndef _YODB_RWLOCK_H_
#define _YODB_RWLOCK_H_

#include "sys/mutex.h"
#include "sys/condition.h"
#include <boost/noncopyable.hpp>

namespace yodb {

class RWLock : boost::noncopyable {
public:
    RWLock();

    bool try_read_lock();
    void read_lock();
    void read_unlock();

    bool try_write_lock();
    void write_lock();
    void write_unlock();

private:
    Mutex mutex_;
    CondVar cond_wait_read_;
    CondVar cond_wait_write_;

    size_t readers_;
    size_t writers_;
    size_t want_readers_;
    size_t want_writers_;
};

} // namespace yodb

#endif // _YODB_RWLOCK_H_
