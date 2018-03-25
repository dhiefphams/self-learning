class User < ApplicationRecord
  # one user has many articles
  has_many :articles
  validates :password, presence: true, length: { minimum: 8}

  validates :email, presence: true
end
