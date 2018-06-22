#ifndef EPOLL_HPP
#define EPOLL_HPP

#include <sys/epoll.h>
#include <functional>


namespace mongols {

    class epoll {
    public:

        epoll() = delete;
        epoll(int ev_size = 64, int timeout = -1);

        virtual~epoll();

    public:

        bool is_ready()const;
        bool add(int fd, int event);
        bool del(int fd);
        bool mod(int fd, int event);
        int wait();
        size_t size()const;
        size_t expires()const;
        void loop(int size, const std::function<void(struct epoll_event*) >& handler);
    private:
        int epfd, ev_size, timeout;
        struct epoll_event ev, *evs;
    };
}

#endif /* EPOLL_HPP */
