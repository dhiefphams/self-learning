import path = require('path');
import { Configuration } from 'webpack';
const nodeExternals = require('webpack-node-externals');
const CleanWebpackPlugin = require('clean-webpack-plugin');


const outDir = path.resolve('dist');

const config: Configuration = {
  mode: 'development',
  entry: './src/main.tsx',
  output: {
    path: outDir,
    filename: 'bin.js',
  },
  target: 'node',
  externals: [nodeExternals()],
  module: {
    rules: [
      { test: /.tsx?$/, use: 'awesome-typescript-loader' }
    ]
  },
  plugins: [
    new CleanWebpackPlugin([outDir], { root: process.cwd() }),
  ],
};

export default config;
