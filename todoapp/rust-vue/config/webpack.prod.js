const webpackMerge = require('webpack-merge');
const commonConfig = require('./webpack.common');

module.exports = () => {
  return webpackMerge(commonConfig({isProd: true}), {
    devtool: '#source-map',
    // http://vue-loader.vuejs.org/en/workflow/production.html
    plugins: [
      new webpack.DefinePlugin({
        'process.env': {
          NODE_ENV: '"production"'
        }
      }),
      new webpack.optimize.UglifyJsPlugin({
        sourceMap: true,
        compress: {
          warnings: false
        }
      }),
      new webpack.LoaderOptionsPlugin({
        minimize: true
      })
    ]
  })
}
