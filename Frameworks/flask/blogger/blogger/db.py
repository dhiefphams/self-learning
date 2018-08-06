import sqlite3

import click
from flask import Flask
from flask import current_app, g
from flask.cli import with_appcontext


def get_db() -> sqlite3.Connection:
    if 'db' not in g:
        g.db: sqlite3.Connection = sqlite3.connect(
            current_app.config['DATABASE'],
            detect_types=sqlite3.PARSE_DECLTYPES
        )
        g.db.row_factory = sqlite3.Row
    return g.db


def init_db():
    db = get_db()
    with current_app.open_resource('schema.sql') as f:
        db.executescript(f.read().decode('utf8'))


# Register new command flask init-db so we can init the database
@click.command('init-db')
@with_appcontext
def init_db_command():
    """clear the existing data and create new tables"""
    init_db()
    click.echo('Initlialized the database.')


def init_app(app: Flask):
    app.teardown_appcontext(close_db)
    app.cli.add_command(init_db_command)


def close_db(e=None):
    db: sqlite3.Connection = g.pop('db', None)
    if db is not None:
        db.close()

