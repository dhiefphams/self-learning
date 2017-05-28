const webpackMerge = require('webpack-merge');

const commonConfig = require('./webpack.common');

module.exports = () => {
  return webpackMerge(commonConfig({ isProd: false }), {
    output: {
      path: path.resolve(__dirname, './dist'),
      publicPath: '/dist/',
      filename: '[name].js'
    },
    devServer: {
      historyApiFallback: true,
      noInfo: true
    },
    performance: {
      hints: false
    },
    devtool: '#eval-source-map'
  });
}