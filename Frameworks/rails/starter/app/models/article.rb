class Article < ApplicationRecord
  # define relationship
  # one user has many articles
  belongs_to :user
  has_many :comments

  validates :title, presence:true, length: { maximum: 50 }
  validates :post, presence: true
end
