import asyncio
import sys

queue = asyncio.Queue()


def _stdin():
    data = sys.stdin.readline()
    asyncio.async(queue.put(data))


async def tick():
    while True:
        data = await queue.get()
        print("Data received: %s" %data)


def main():
    loop = asyncio.get_event_loop()
    loop.add_reader(sys.stdin, _stdin)
    loop.run_until_complete(tick())


if __name__ == '__main__':
    main()
