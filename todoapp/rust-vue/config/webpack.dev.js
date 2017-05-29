const path = require('path');
const webpackMerge = require('webpack-merge');

const commonConfig = require('./webpack.common');

module.exports = () => {
  return webpackMerge(commonConfig({ isProd: false }), {
    output: {
      path: path.resolve('./dist'),
      publicPath: '/dist/',
      filename: '[name].js'
    },
    devServer: {
      historyApiFallback: {
        index: '/dist/'
      }
    },
    devtool: 'cheap-eval-source-map'
  });
}