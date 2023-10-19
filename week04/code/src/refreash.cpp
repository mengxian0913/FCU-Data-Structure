void MyPoly::refresh(const char* filename) {
  idx = 0; // 初始化 idx
  ifstream ifs(filename, ifstream::in);
  polynomial input;
  while(ifs >> input.coef >> input.expon) {
    terms[idx] = input; // 將每一筆資料存入 terms[idx]
    idx++; // 每次做完 idx + 1
  }
  ifs.close(); // 關閉檔案
}
