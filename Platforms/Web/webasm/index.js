const loadWASM = async (filename) => {
	let importObject = {
		'env': {
        'memoryBase': 0,
        'tableBase': 0,
        'memory': new WebAssembly.Memory({initial: 256}),
        'table': new WebAssembly.Table({initial: 2, element: 'anyfunc'})
    }
	};
	return WebAssembly.instantiateStreaming(fetch(filename), importObject);
}


const wasmHelloWorld = async () => {
	const counter = await loadWASM('counter.wasm');
	console.log(counter.instance.exports._count());
};

document.addEventListener('DOMContentLoaded', wasmHelloWorld, false);

