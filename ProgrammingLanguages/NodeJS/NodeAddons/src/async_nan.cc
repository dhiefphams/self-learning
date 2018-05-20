#include <nan.h>

void delay(int iterations) {
    // use volatile to prevent compiler from optimizing empty loop
    for (volatile auto i = 0; i < iterations; ++i);
}

/**
 * We must implement 3 basic methods
 * 1. Execute
 * 2. OkHandler
 * 3. Error handler
 */
class LongAsyncWorker: public Nan::AsyncWorker {
public:
    std::string workerId;
    int iterations;
    bool throwsError;

    LongAsyncWorker(std::string workerId, int iterations, bool throwsErrors, Nan::Callback *callback)
        :Nan::AsyncWorker(callback),
        workerId(workerId),
        iterations(iterations),
        throwsError(throwsErrors){

    }

    void Execute() {
        if (throwsError) {
            this->SetErrorMessage("An error occurred!");
            return;;
        }
        delay(iterations);
    }

    void HandleOKCallback() {
        Nan::HandleScope scope;
        v8::Local<v8::Value> argv[] = {
                Nan::Null(),
                Nan::New(workerId).ToLocalChecked()
        };
        callback->Call(2, argv);
    }

    void HandleErrorCallback() {
        Nan::HandleScope scope;
        v8::Local<v8::Value> argv[] = {
                Nan::New(this->ErrorMessage()).ToLocalChecked(),
                Nan::Null()
        };
        callback->Call(2, argv);
    }
};

NAN_METHOD(asyncDelay) {
    if (!info[0]->IsString()) {
        return Nan::ThrowError(Nan::New("Expected arg 0: string workerId").ToLocalChecked());
    }

    if (!info[1]->IsInt32()) {
        return Nan::ThrowError(Nan::New("Expected arg 1: int iterations").ToLocalChecked());
    }
    if (!info[2]->IsBoolean()) {
        return Nan::ThrowError(Nan::New("Expected arg 2: bool throwsError").ToLocalChecked());
    }
    if (!info[3]->IsFunction()) {
        return Nan::ThrowError(Nan::New("Expected arg 3: function callback").ToLocalChecked());
    }

    Nan::AsyncQueueWorker(new LongAsyncWorker(
            std::string(*Nan::Utf8String(info[0]->ToString())),
            info[1]->Int32Value(),
            info[2]->BooleanValue(),
            new Nan::Callback(info[3].As<v8::Function>())
    ));
}

NAN_METHOD(syncDelay) {
    if (!info[0]->IsString()) {
        return Nan::ThrowError(Nan::New("Export arg 0: string worker").ToLocalChecked());
    }
    if (!info[1]->IsInt32()) {
        return Nan::ThrowError(Nan::New("Export arg 1: int iterations").ToLocalChecked());
    }
    if (!info[2]->IsFunction()) {
        return Nan::ThrowError(Nan::New("Expected arg 3: function callback").ToLocalChecked());
    }

    delay(info[1]->Int32Value());
    info.GetReturnValue().Set(Nan::Undefined());
    std::string workerId = std::string(*Nan::Utf8String(info[0]->ToString()));
    auto callback = new Nan::Callback(info[2].As<v8::Function>());
    v8::Local<v8::Value> argv[] = {
            Nan::Null(),
            Nan::New(workerId).ToLocalChecked()
    };
    callback->Call(2, argv);
}

NAN_MODULE_INIT(Initialise) {
    NAN_EXPORT(target, asyncDelay);
    NAN_EXPORT(target, syncDelay);
}

NODE_MODULE(addon, Initialise);
