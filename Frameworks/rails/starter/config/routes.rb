Rails.application.routes.draw do
  get 'pages/home'

  get 'pages/about'

  resources :articles do
    resources :comments
  end

  resources :users
  get 'home/index'

  # match ":controller(/:action(/:id))", :via => :get

  root 'home#index'

  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
