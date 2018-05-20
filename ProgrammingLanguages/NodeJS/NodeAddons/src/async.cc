#include <node.h>
#include <v8.h>
#include <uv.h>


// native blocking or compute intensive function
long long delay(int seconds) {
    long long count = 0;
    int i, j;
    for (i = 0; i <200000; ++i) {
        for(j = 0; j < 400; ++j) {
            count *= seconds;
        }
    }
    return count;
}

struct WorkerData {
    uv_work_t request; // libuv work request
    v8::Persistent<v8::Function> callback; // js callback
    std::vector<int> locations;
    std::vector<int> results;
};

/**
 * DecodeAsync(fname, callback)
 */
void DecodeAsync(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    WorkerData* worker = new WorkerData;
    worker->request.data = worker;

    // extract each location (its a list) and store it in the works package work
    // is on the heap
    // so it can be accessible in worker thread
    v8::Local<v8::Array> inputLocations = v8::Local<v8::Array>::Cast(args[0]);
    unsigned int num_locations = inputLocations->Length();
    for (unsigned int i = 0; i < num_locations; ++i) {
        // new v8 version breaking change
        // use nan instead
        worker->locations.push_back(v8::Local<v8::Object>::Cast(inputLocations->Get(i)));
    }

    // now get callback function
    v8::Local<v8::Function> callback = v8::Local<v8::Function>::Cast(args[1]);
    worker->callback.Reset(isolate, callback);
    uv_queue_work(uv_default_loop(), &worker->request, AsyncWorker, AsyncWorkerComplete);
    args.GetReturnValue().Set(v8::Undefined(isolate));
}

/**
 * AsyncWorker will be executed in the libuv worker pools
 */
void AsyncWorker(uv_work_t * req) {
    // we can be full access the worker data
    WorkerData *work = static_cast<WorkerData *>(req->data);
    // do some thing in worker pool
    // remember assign data back to work data structure
}

void AsyncWorkerComplete(uv_work_t * req, int status) {
    v8::Isolate * isolate = v8::Isolate::GetCurrent();
    
    WorkerData* work = static_cast<WorkerData *>(req->data);
}