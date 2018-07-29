extern "C" {
  int sum(int total) {
    int s = 0;
    for (int i = 0; i < total; ++i) {
      s += i;
    }
    return s;
  }
}

