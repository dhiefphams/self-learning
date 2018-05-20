#include <nan.h>

const int maxValue = 10;
int numberOfCalls = 0;

//void whoAmI(const Nan::FunctionCallbackInfo<v8::Value>& args) {
// same things but using macro
NAN_METHOD(whoAmI) {
  auto message = Nan::New<v8::String>("Welcome to Q'Island!").ToLocalChecked();
  info.GetReturnValue().Set(message);
}

NAN_METHOD(increment) {
//void Increment(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  if (!info[0]->IsNumber()) {
    Nan::ThrowError("Argument must be a number");
    return;
  }
  double argsValue = info[0]->NumberValue();
  if (numberOfCalls + argsValue > maxValue) {
    Nan::ThrowError("Counter went through the roof!");
    return;
  }

  numberOfCalls += argsValue;
  auto currentNumberOfCalls = Nan::New<v8::Number>(numberOfCalls);
  info.GetReturnValue().Set(currentNumberOfCalls);
}

//void Initialise(v8::Local<v8::Object> exports) {
//  exports->Set(Nan::New("whoAmI").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(whoAmI)->GetFunction());
//  exports->Set(Nan::New("increment").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(increment)->GetFunction());
//}

NAN_MODULE_INIT(Initialise) {
    NAN_EXPORT(target, whoAmI);
    NAN_EXPORT(target, increment);
}

NODE_MODULE(addon, Initialise);