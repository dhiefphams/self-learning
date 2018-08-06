from blogger import create_app


def test_config():
    assert not create_app().testing
    assert create_app({'TESTING': True}).testing


def test_home(client):
    response = client.get('/')
    assert response.data == b'Hello world'
