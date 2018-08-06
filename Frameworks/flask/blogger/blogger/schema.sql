DROP TABLE IF EXISTS users;
drop table if exists posts;

create table users (
  id integer primary key autoincrement,
  username text unique not null,
  password text not null
);

create table posts (
  id integer primary key autoincrement,
  author_id integer not null,
  created timestamp not null default current_timestamp,
  title text not null,
  body text not null,
  foreign key (author_id) references users(id)
);

