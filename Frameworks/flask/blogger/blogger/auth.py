import functools

from flask import Blueprint, flash, g
from flask import redirect, render_template, request, session, url_for
from werkzeug.security import check_password_hash, generate_password_hash

from blogger.db import get_db

auth_blueprint = Blueprint('auth', __name__, url_prefix='/auth')


@auth_blueprint.route('/register', methods=['POST', 'GET'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        db = get_db()
        error = None
        if not username:
            error = 'Username is required'
        elif not password:
            error = 'Password is required'
        elif db.execute('SELECT id from users where username = ?',
                        (username, )).fetchone() is not None:
            error = 'User {} is already registered'.format(username)
        if error is None:
            db.execute('INSERT INTO users (username, password), VALUES (?, ?)',
                       (username, generate_password_hash(password)))
            db.commit()
            return redirect(url_for('auth.login'))
        pass
    return render_template('auth/register.html')


@auth_blueprint.route('/login', methods=['POST', 'GET'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        db = get_db()
        error = None
        user = db.execute('select * from users where username = ?',
                          (username,)).fetchone()
        if user is None:
            error = 'Incorrect username'
        elif not check_password_hash(user['password'], password):
            error = 'Incorrect password'
        if error is None:
            session.clear()
            session['user_id'] = user['id']
            return redirect(url_for('index'))
        flash(error)
    return render_template('auth/login.html')


@auth_blueprint.before_app_request
def load_logged_in_user():
    user_id = session.get('user_id')
    if user_id is None:
        g.user = None
    else:
        g.user = get_db().execute(
            'select * from users where id = ?', (user_id,)
        ).fetchone()


@auth_blueprint.route('/logout')
def logout():
    """Logout handler
    Clear everythings
    """
    session.clear()
    return redirect(url_for('index'))


# required auth for other route
def auth_required(view):
    """Decorate a view handler for auth required"""
    @functools.wraps(view)
    def wrapper(**kwargs):
        if g.user is None:
            return redirect(url_for('auth.login'))
        return view(**kwargs)
    return wrapper
