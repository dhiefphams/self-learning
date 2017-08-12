import asyncio
import uvloop

async def say(what, when):
    await asyncio.sleep(when)
    print(what)


if __name__ == "__main__":
    asyncio.set_event_loop_policy(uvloop.EventLoopPolicy())
    loop = asyncio.get_event_loop()
    task1 = loop.create_task(say("Hello One", 1))
    task2 = loop.create_task(say("Hello two", 0.5))
    print("Not a coroutines")
    # loop.run_forever()
    loop.run_until_complete(
        asyncio.gather(task1, task2))
    print("Done")
