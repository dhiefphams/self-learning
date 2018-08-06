## How to runs
- `export FLASK_APP=blogger`
- `$ pip install -e .`
- `$ flask init-db`
- `$ flask run`

## Nginx deployment
- Install `uwsgi`: `$ sudo python -m pip install uwsgi`
- Create `uwsgi.ini` like bellow

```
```

- Nginx conf

```
location / {
  try_files $url @blogger;
}

location @blogger {
  include uwsgi_params;
  uwsgi_pass unix://tmp/blogger_sock.sock;
}
```

- `$ uwsgi --ini /path/to/uwsgi.ini`

## Testing
- `pytest`
- `$ coverage run -m pytest`
- `$ coverage report`
- `$ coverage html`
