from selectors import DefaultSelector, EVENT_WRITE, EVENT_READ
import socket
import time

# select the best selector-like in our system: kqueue, epoll or IOCP
selector = DefaultSelector()
URL = "data.vietstock.vn"


def get(path):
    s = socket.socket()
    s.setblocking(False)
    try:
        s.connect((URL, 80))
    except BlockingIOError:
        pass

    request = "GET {} HTTP/1.0\r\n Host: {}\r\n\r\n".format(path, URL)
    # subscribe the event
    selector.register(s.fileno(), EVENT_WRITE)
    # wait
    selector.select()
    # done and un register
    selector.unregister(s.fileno())

    s.send(request.encode())

    chunks = []
    while True:

        selector.register(s.fileno(), EVENT_READ)
        selector.select()
        selector.unregister(s.fileno())
        chunk = s.recv(1000)
        if chunk:
            chunks.append(chunk)
        else:
            body = (b"".join(chunks)).decode()
            print(body.split("\n")[0])
            return


if __name__ == "__main__":
    start = time.time()
    get("/about")
    get("/support")
    print("took %.1f secs" % (time.time() - start))
