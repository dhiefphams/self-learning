/**
 * Webpack config
 */
switch (process.env.NODE_ENV) {
  case 'dev':
  case 'development':
    module.exports = require('./config/webpack.dev')();
  
  case 'prod':
  case 'production':
    module.exports = require('./config/webpack.prod')();
  
  default:
    module.exports = require('./config/webpack.dev')()
}
