const HtmlWebpackPlugin = require('html-webpack-plugin');


const config = {
	entry: './index.js',
	mode: 'development',
	module: {
		rules: [
			{ test: /\.wasm$/, use: 'wasm-loader' },
		],
	},
	plugins: [
		new HtmlWebpackPlugin({
			template: './index.html'
		}),
	],
};


module.exports= config;
