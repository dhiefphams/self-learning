from sanic import Sanic
from sanic.response import json

app = Sanic(__name__)


@app.route("/hello")
async def hello(request):
    resp = {
        "foo": "bar"
    }
    return json(resp)


if __name__ == '__main__':
    app.run(host="0.0.0.0", port=8080, workers=4, debug=False)
