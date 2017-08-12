from japronto import Application


def hello(request):
    return request.Response(json={"foo": "bar"})


app = Application()
app.router.add_route('/hello', hello)
app.run(debug=False)
