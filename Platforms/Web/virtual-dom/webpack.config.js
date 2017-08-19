const webpack = require('webpack');
const path = require('path');
const { CheckerPlugin } = require('awesome-typescript-loader')
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
  resolve: {
    extensions: ['.ts', '.tsx', '.js', '.jsx']
  },
  entry: './src/main.tsx',
  output: {
    filename: 'main.js',
    path: path.resolve('dist'),
    publicPath: '/static/'
  },
  devtool: 'source-map',
  module: {
    rules: [
      {
        test: /\.tsx?$/,
        use: 'awesome-typescript-loader',
        exclude: /node_modules/
      }
    ]
  },
  plugins: [
    new CheckerPlugin(),
    new HtmlWebpackPlugin({
      template: './src/index.html',
      title: 'Virtual Dom Research'
    })
  ],
  devServer: {
    historyApiFallback: {
      index: '/static/'
    }
  }
};
