void MyPoly::refresh(const char* filename) {
  terms.clear();
  ifstream ifs(filename, ifstream::in);
  polynomial input;
  while(ifs >> input.coef >> input.expon) {
    terms.pb(input);
  }
  ifs.close();
}
