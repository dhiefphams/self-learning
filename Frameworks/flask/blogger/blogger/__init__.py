import os

from flask import Flask


def create_app(test_config=None) -> Flask:
    # Create and configure the app
    # __name__ tells flask that where it's located to set up some paths
    app = Flask(__name__, instance_relative_config=True)
    # app.instance_path is the instance folder that locates outside the blogger
    # package and can hold data that shouldn't commited to vcs
    app.config.from_mapping(
        SECRET_KEY='q',
        DATABASE=os.path.join(app.instance_path, 'blogger.sqlite')
    )

    if test_config is None:
        # load the instance config, if it exists, when not testing
        app.config.from_pyfile('config.py', silent=True)
    else:
        app.config.from_mapping(test_config)

    # ensure the instance folder exists
    try:
        os.makedirs(app.instance_path, exist_ok=True)
    except OSError:
        pass

    @app.route('/')
    def home():
        return 'Hello world'

    from . import db
    db.init_app(app)
    from . import auth
    app.register_blueprint(auth.auth_blueprint)

    return app

