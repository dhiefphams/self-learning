import os

from typing import List
from flask import Flask, request, render_template, jsonify
from flask import send_from_directory, redirect, url_for, abort
from werkzeug.utils import secure_filename

app = Flask(__name__)
app.config['AVATAR_LOCATION'] = '/tmp/flasks/avatar'
os.makedirs(app.config['AVATAR_LOCATION'], exist_ok=True)


@app.route('/')
def index(user=None):
    return render_template('user.html', user=user)


@app.route('/users', methods=['POST', 'GET'])
def users() -> str:
    # handle post method
    if request.method == 'POST':
        pass
    # handle get method
    # get query string
    args = request.args
    search_query = args.get('query', '')
    print(search_query)
    return '<h1>This is list of user for {}</h1>'.format(search_query)


@app.route('/login', methods=['POST', 'GET'])
def login():
    if request.method == 'POST':
        login_credential = request.get_json()
        if 'username' not in login_credential or \
           'password' not in login_credential:
            return redirect(url_for('login'))
        return jsonify(login_credential)
    # handle get request
    return render_template('login.html')


@app.route('/users/<username>', methods=['GET'])
def profile(username: str) -> str:
    return render_template('profile.html', name=username)


@app.route('/users/<username>/avatar', methods=['GET', 'POST'])
def avatar(username: str):
    ext = '.png'
    if request.method == 'POST':
        # receive upload file
        f = request.files['avatar']
        _, ext = os.path.splitext(f.filename)
        filename = '{}{}'.format(username, ext)
        location = os.path.join(app.config['AVATAR_LOCATION'], filename)
        f.save(location)
        return secure_filename(filename)
    # return the files
    filename = '{}{}'.format(username, ext)
    return send_from_directory(app.config['AVATAR_LOCATION'],
                               filename=filename)

@app.route('/posts/<int:post_id>')
def post_detail(post_id: int) -> str:
    if post_id == 0:
        abort(401)
    return 'Getting detail of {}'.format(post_id)


# handle error page
@app.errorhandler(404)
def not_found(error):
    return render_template('notfound.html', error=error), 404

if __name__ == '__main__':
    app.run(debug=True)
