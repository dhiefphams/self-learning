module Api
  module V1
    class ArticlesController < ApplicationController
      def index
        articles = Article.order("created_at DESC")
        render json: { status: "SUCCESS", message: "Loaded Message", data: articles}, status: :ok
      end

      def show
        article = Article.find(params[:id])
        render json: {status: "SUCCESS", message: "Loaded Message", data: article}, status: :ok
      end

      def create
        article = Article.new(article_params)
        if article.save
          render json: {status: "SAVED", data: article}, status: :ok
        else
          render json: {status: "ERROR", message: "Oops!"}, status: :unprocessable_entry
        end
      end

      def destroy
        article = Article.find(params[:id])
        article.destroy
        render json: { status: "OK" }, status: :ok
      end

      def update
        article = Article.find(params[:id])
        if article.update_attributes(article_params)
          render json: {status: "SAVED", data: article}, status: :ok
        else
          render json: {status: "ERROR", message: "Oops!"}, status: :unprocessable_entry
        end
      end

      private
      def article_params
        params.permit(:title, :body)
      end

    end  
  end
end